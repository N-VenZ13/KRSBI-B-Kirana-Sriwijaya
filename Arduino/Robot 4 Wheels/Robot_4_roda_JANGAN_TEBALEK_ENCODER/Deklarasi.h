#include <Wire.h>           // Library kompas cmps 12 I2C

#include <EEPROM.h>         // Library EEPROM memory internal

#include <SoftwareSerial.h> // Library Komunikasi SoftwareSerial

//#include <Servo.h>

//----------------Komunikasi Serial Nodemcu-----------------------
SoftwareSerial s(43, 41); // Deklarasi Pin Data SoftwareSerial

// PAHAMI PENGERTIAN VARIABEL
// (https://djukarna4arduino.wordpress.com/2015/01/19/memahami-variabel-tipe-data-dan-konstanta/#:~:text=Variabel%20adalah%20nama%20yang%20dibuat,suatu%20variabel%20bernama%20%E2%80%9Clampu1%E2%80%9D.)

// kompas GY26
char valorbyte[8];
int heading2 = 0;
int contador = 0;
byte valor = 0;


//----------------Variabel EEPROM MEMORY-----------------------
int Moda;
int A_Moda = 10;
int playmode = 0;

//---------------- Variabel PID-----------------------
int error, last_error, I;
int kp, kd, sp, ki, pid_kb ;
int P, D, PD;

// ============= Variabel PID POSISI ===============
int setPoint_k, P_k, I_k, D_k, error_k, lastError_k, pwm_k;
int setPoint_x, P_x, I_x, D_x, error_x, lastError_x, pwm_x;
int setPoint_y, P_y, I_y, D_y, error_y, lastError_y, pwm_y;
int stepK ;
float arc_tan;

//----------Deklarasi Pin TOMBOL-----------
#define up_kiri 42
#define up_kanan 36
#define okJok 38
#define backJok 40
#define down_kiri 44
#define down_kanan 46

//----------Program Membaca Pin TOMBOL-----------
#define upL digitalRead(up_kiri)
#define downL digitalRead(down_kiri)
#define ok digitalRead(okJok)
#define back digitalRead(backJok)
#define upR digitalRead(up_kanan)
#define downR digitalRead(down_kanan)

//----------Program Buatan Tombol Untuk Deklarasi di void setup -----------
void deklarasi_tombol() {
  pinMode(up_kiri, INPUT_PULLUP);
  pinMode(down_kiri, INPUT_PULLUP);
  pinMode(okJok, INPUT_PULLUP);
  pinMode(backJok, INPUT_PULLUP);
  pinMode(up_kanan, INPUT_PULLUP);
  pinMode(down_kanan, INPUT_PULLUP);
}

//=============Deklarasi pin I2C dan address CMPS12====================
#define CMPS11_ADDRESS 0x60  // Address of CMPS12 shifted right one bit for arduino wire library
#define ANGLE_8  1           // Register to read 8bit angle from

//VARIABEL KOMPAS CMP12
unsigned char high_byte, low_byte, angle8;
char tmp; // Variabel untuk menyimpan data yang tidak diperlukan (Roll & Pitch)
unsigned int angle16;
float heading;
int logic_cmps = 0;
int logic_gy = 0;
int cmpsFix, gyFix, sudut, sudut2;
bool siap;

//++++++ Deklarasi PIN Data ENCODER ++++++++
#define enA 18  //x  //SUDAH BENER JANGAN DIKUTAK KATIK
#define enB 16  //x
#define enC 19  //y
#define enD 17  //y

//------------Variabel Rotary ENCODER dan GO TO---------------
int a, sudut0, sudutv, xx, yy;
float jarakx, jaraky, Xx, Yx, Xy, Yy, X, Y, Xc, Yc, Xv, Yv, Xr, Yr;
int leftCounty = 0;
int leftCountx = 0;
int pwm, pwm1, speed, pwmRem;
float r, r1;
//int btn = 0;
int langkah = 0;
int langkah2 = 0;
int langkah3 = 0;
int langkah4 = 0;
int langkah5 = 0;
int langkahM = 0;
bool moda1, moda2, moda3, moda4, moda5;
//String Data;
int kamera_atas, logic_cam, X_now, Y_now;
unsigned long LastAkselerasi = 0;
const long intervalA = 100;
//int servoBola = 120;
bool Tendang = false;
bool nyampe = false;
bool nyampe1 = false;
//----------Program Buatan Rotary Encoder Untuk Deklrasi di void setup -----------
void inisial_encoder() {
  pinMode(enA, INPUT_PULLUP);
  pinMode(enB, INPUT_PULLUP);
  pinMode(enC, INPUT_PULLUP);
  pinMode(enD, INPUT_PULLUP);
}

//Deklrasi PIN Data MOTOR DRIBBLE
//======== Dribble =========
#define motordribble1 4
#define motordribble2 5

//======== Dribble ========= //DIJADIKE 1 PIN, pin 4 sm 5 bae yg dipakek, ini idak dipakek tapi belum berhasil matikenyo jadi tetep diedopi
#define motordribblekanan1 2
#define motordribblekanan2 3

//----------Program Buatan Motor Dribel Untuk Deklrasi di void setup -----------
void deklarasi_dribble() {
  pinMode(motordribblekanan1, OUTPUT);
  pinMode(motordribblekanan2, OUTPUT);
  pinMode(motordribble1, OUTPUT);
  pinMode(motordribble2, OUTPUT);
}

//Deklarasi PIN Data Sinyal MOTOR PENENDANG
//======== Penendang =========
// int Gkick = A1;  
// int oper = A2; //A1 sm A2 untuk penendang yang makek motorPG45 dengen nano

//Deklarasi PIN Data TRIGER PENENDANG SELENOID
#define Selenoid 12

//----------Program Buatan Penendang sinyal Untuk Deklrasi di void setup -----------
void deklarasi_kick() {
  pinMode(Selenoid, OUTPUT);    

// Ini men makek motorPG45 sm nano
  // pinMode(Gkick, OUTPUT);
  // pinMode(oper, OUTPUT);
}

//Deklarasi PIN Data MOTOR PG45
//======== Left =========
#define pin_MOTOR_DIRL 10 //JANGAN DIBALEK LAGI, INSYAALLAH LAH BENER UNTUK 2024
#define pin_MOTOR_PWML 11
//======== Right =========
#define pin_MOTOR_DIRR 6   
#define pin_MOTOR_PWMR 7
//======== Back =========
#define pin_MOTOR_DIRB 8  
#define pin_MOTOR_PWMB 9

//----------Program Buatan Motor PG45 Untuk Deklrasi di void setup -----------
void deklarasi_pg45() {
  pinMode(pin_MOTOR_DIRR, OUTPUT);
  pinMode(pin_MOTOR_PWMR, OUTPUT);
  pinMode(pin_MOTOR_DIRL, OUTPUT);
  pinMode(pin_MOTOR_PWML, OUTPUT);
  pinMode(pin_MOTOR_DIRB, OUTPUT);
  pinMode(pin_MOTOR_PWMB, OUTPUT);
}

//---------Deklarasi Pin DataSharpGP-----------
#define sharpGP  A0  //INI YANG SGP DALEM
#define bkn A3       // SGP KANAN
#define bkr A4       // SGP KIRI

//----------Program membaca pin data sharp-----------
#define sgp analogRead(sharpGP)
#define bahukiri analogRead(bkr)
#define bahukanan analogRead(bkn)

//----------Variabel Data sharp-----------
bool dapetBola;
bool bkiri;
bool bkanan;

//Program logika sharp membuat kondisi dapet bola atau tidak dapat bola
void sharpgp() {
  if (sgp > 500 && sgp < 600) {
    dapetBola = true;
  }
    else {
    dapetBola = false;
  }
}

void bkirifix() {
  if (bahukiri > 300 && sgp < 700) {
    bkiri = true;
    
  }
  else {
    bkiri = false;
  }
}

void bkananfix() {
  if (bahukanan > 300 && sgp < 700) {
    bkanan = true;
  }
  else {
    bkanan = false;
  }
}

//--------Variabel Komunikasi Python--------
char pesan;
String pesanx;
int belok = 0;
int nanoSerial;

//==================Variabel Baca komunikasi Serial python =======================
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
char inChar;
int x, y, v, w, Xcam, Ycam, xcam, ycam, rxcam, rycam;
String data;
String d;

#define led1 33
#define led2 37
#define led3 29
#define led4 39
#define led5 35
#define led6 31

//OUTPUT LED
void deklarasi_led() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void ledData(int C, int K, int M, int R, int O, int N) {
  digitalWrite(led1, C);
  digitalWrite(led2, K);
  digitalWrite(led3, M);
  digitalWrite(led4, R);
  digitalWrite(led5, O);
  digitalWrite(led6, N);
}

//tambahan variabel 2024
int step;
// unsigned long previousMillis = 0;
// unsigned long previousMillisKomunikasi = 0;
// const unsigned long intervalKomunikasi = 100;
