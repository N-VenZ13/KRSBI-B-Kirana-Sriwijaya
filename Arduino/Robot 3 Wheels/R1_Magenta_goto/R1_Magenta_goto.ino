// -------------ROAD TO KRSBI 2024 JUARA! AAMIIN--------------
//------1 Desember 2020 September 2019 || Sedry M. Iqbal
//------Januari 2024 - Maret 2024 || Siti Kamila
//-----------------------------------------------------------

#include "Deklarasi.h"   // ||
#include "Gerakan.h"     // || Library Buatan
#include "PID_posisi.h"  // ||

#include <Wire.h>
#include <LiquidCrystal_I2C.h>       // || LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // ||

void posisi() {  // PROGRAM Buatan Posisi berfungsi untuk menentukan nilai jarak X dan Y Rotary Encoder dalam Satuan DM dengan sumbu X dan Y
  float sudutv = 45 * PI / 180;
  float sudutw = 135 * PI / 180;

  Xv = -(leftCountx * cos(sudutv) + leftCounty * cos(sudutw)) * 0.00261;  
  Yv = (leftCountx * cos(sudutv) + leftCounty * sin(sudutw)) * 0.00261;

  float sudut1 = sudut * PI / 180;
  float sudut2 = sudut0 * PI / 180;  //ngakali supaya salah satu sumbu rotasi derajat yo tebalek

  jarakx = Xv;  //nilai hasil dari perhitungan nilai yg di hasilkan enc di kali jarak per pulsa
  jaraky = Yv;

  Xx = jarakx * cos(sudut1);  //Mengabungkan perhitungan nilai enc dgn kompas
  Yx = jarakx * sin(sudut1);
  Xy = jaraky * sin(sudut2);
  Yy = jaraky * cos(sudut2);

  X = X + Xx + Xy;  //Nilai posisi di update setiap interval milis
  Y = Y + Yx + Yy;
  //  Xc = X / 10;
  //  Yc = Y / 10;

  leftCounty = 0;  //ngakali supaya bacaan sekarang 0 di update dengan nilai X dan Y di atas
  leftCountx = 0;
}

void update_data(){
  kompas();
  UpdatePosisi();
  pid_kompas();
  logic_cmps = 1;
  dribble_on1();
  dribble_on2();
  sharpgp();
  bkirifix();
  bkananfix();
  // lcd.setCursor(0, 0); lcd.print("S = ");
  // lcd.setCursor(3, 0); lcd.print(sudut); lcd.print("   ");
  // lcd.setCursor(0, 1); lcd.print("X = ");
  // lcd.setCursor(3, 1); lcd.print(X); lcd.print("   ");
  // lcd.setCursor(0, 2); lcd.print("Y = ");
  // lcd.setCursor(3, 2); lcd.print(Y); lcd.print("   ");
  // lcd.setCursor(12, 1); lcd.print(nyampe); lcd.print("   ");
  // lcd.setCursor(12, 2); lcd.print(step); lcd.print("   ");
  // lcd.setCursor(14, 1); lcd.print(dapetBola); lcd.print("   ");
}



void setup() {
  // Serial.begin(500000);  //untuk komunikasi dengan python
  Serial.begin(115200);   //Deklarasi Serial Monitor dan mengatur nilai baud
  // Serial.begin(9600); 
  // Serial3.begin(9600);  // kompass
  // s.begin(115200);      //Deklarasi untuk komunikasi Software Serial

  Wire.begin();  //Deklarasi Kompas CMPS12
  lcd.init();       // || Deklarasi LCD i2C
  lcd.backlight();  // ||

  deklarasi_pg45();  // Deklarasi Buatan untuk PIN Data Motor Pg45
  deklarasi_dribble();  // Deklarasi Buatan untuk PIN Data Motor Drible
  // deklarasi_tombol();  // Deklarasi Buatan untuk PIN Data Tombol
  deklarasi_kick();   // Deklarasi Buatan untuk PIN Data Penendang
  inisial_encoder();  // Deklarasi Buatan PIN Data Untuk Rotary Encoder

  inputString.reserve(200);
  attachInterrupt(digitalPinToInterrupt(18), leftEncoderEventy, CHANGE);  // || Deklarasi PIN Data Interrupt untuk Rotary Encoder (http://omelektro.blogspot.com/2019/02/fungsi-interrupt-pada-arduino-adalah.html)
  attachInterrupt(digitalPinToInterrupt(19), leftEncoderEventx, CHANGE);  // ||
  // homescreen();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           //Program Buatan Tombol (alasan Program tombol di letakan di void setup karena program berjalan terlebih dahulu sebelum program laen berjalan di void loop )
}

void loop() {
  //===========================================//
  //==== TESTING POSISI ====
  // nyampe = false;
  // step = 1;
  // while (nyampe == false) {
  //   update_data();
  //   go_to(77, X, Y, 50);
  // }
  // motor(0, 0, 0);
  // delay(1000);

  // nyampe = false;
  // step = 2;
  // while (nyampe == false) {
  //   update_data();
  //   go_to(0, X, Y, 50);
  // }
  // motor(0, 0, 0);
  // delay(1000000);

  // do {
  //   up_data();
  //   go_to(0, 2, 0, 50);
  // } while (nyampe == false);
  // motor(0, 0, 0);
  // delay(100000);

  // === CODING EDOPI DRIBBLE ===
  
  //  Serial.print("Serial jalan");
  //  dribble_on1();
  //  dribble_on2();

  // === CODING CEK OMNI ===   //untuk motor dan kompas
  // omni(0,0,100);   //program maju
  // delay(2000);
  // omni(180,0,100); //program mundur
  // delay(2000);
  // omni (90,0,100); //program ke kiri
  // delay(2000);
  // omni (270,0,100); //program ke kanan
  // delay(2000);

  // === CODING CEK MOTOR ===
  // motor(50, 50, 50);    //motor muter kanan
  // delay(2000);
  // motor(-50, -50, -50); //motor muter kiri
  // delay(2000);

  // === CODING CEK KOMPAS DAN X Y ===
  // s.print("k");
  // kompas();
  // logic_cmps = 1;
  // UpdatePosisi();
  // Serial.print("S = ");
  // Serial.print(sudut);
  // Serial.print("||");
  // Serial.print("X = ");
  // Serial.print(X);
  // Serial.print("||");
  // Serial.print("Y = ");
  // Serial.println(Y);
  // delay(50);  //supaya nilainyo dk kecepetan di serial monitor jadi dikasih delay

  // === CODING CEK TAMPILAN LCD ===
  //  lcd.setCursor(0, 0); lcd.print("D = ");
  //  lcd.setCursor(5, 0); lcd.print(d); lcd.print("   ");
  //  lcd.setCursor(0, 0); lcd.print("X = ");
  //  lcd.setCursor(5, 0); lcd.print(X); lcd.print("   ");
  //  lcd.setCursor(0, 2); lcd.print("Y = ");
  //  lcd.setCursor(5, 2); lcd.print(Y); lcd.print("   ");

  // === CODING EDOPI SELENOID ===
  // kickON();            //men nak aman makai sharpGp bae, kodingannyo ado di ModaM
  // delay(2000);
  // operON();

  // === CODING LIHAT NILAI SHARP GP ===
  // lcd.setCursor(0, 0); lcd.print("S = ");
  //  lcd.setCursor(5, 0); lcd.print(sgp); lcd.print("   ");
  //  Serial.print("S = ");
  //  Serial.println(sgp);
  //  Serial.print("||");
  //  Serial.print("BKI = ");
  //  Serial.print(bahukiri);
  //  Serial.print("||");
  //  Serial.print("BKN = ");
  //  Serial.println(bahukanan);
  //  delay(50);

  // === CODING BACA KAMERA PYTHON ===
  //  UpdatePosisi();
  // //  serialEvent();
  // //  baca_kamera();
  //  kejar_bola_omni();
  //  kejar_bola_omni_depan();   //best
  // tangkapBolaOmni(0);   //bestt
  // tangkapBolaOmniDekat(0);
  // dapetBola == false;
  // if (dapetBola == true){
  //   motor(0, 0, 0);
  //   delay(10000000);
  // }

  // tangkapBolaModa2(0);
  //
  //  bkirifix();
  //    bkananfix();
  //
  //    if (bkiri == true) {
  //     tangkapBola(0);
  //    }
  //    if (bkanan == true) {
  //      tangkapBola(0);
  //    }

  //  Serial.print("X= ");
  //  Serial.print(leftCountx);
  //  Serial.print("||");
  //  Serial.print("Y= ");
  //  Serial.println(leftCounty);
  //  delay(1000);

  // unsigned long currentMillis = millis();
  // if (currentMillis - previousMillisKomunikasi >= intervalKomunikasi) { // Eksekusi komunikasi setiap intervalKomunikasi milidetik
  //   previousMillisKomunikasi = currentMillis;
  // // === MODE KOMUNIKASI ===
  komunikasi();
  if (moda1 && !moda2 && !moda3 && !moda4 && !moda5) {
    // Serial.println("moda masuk");
    Moda1();
  }
  else if (!moda1 && moda2 && !moda3 && !moda4 && !moda5) {
    Moda2();
  }
  // else if (!moda1 && !moda2 && moda3 && !moda4 && !moda5) {
  //   Moda3();
  // }
  // else if (!moda1 && !moda2 && !moda3 && !moda4 && !moda5) {
  //   Moda4();
  // }
  // else if (!moda1 && !moda2 && !moda3 && !moda4 && !moda5) {
  //   Moda5();
  // }
  //  }

  //==========================================//
  //  if (!back) {
  //    homescreen();
  //  }
}


// void serialEvent() {  //Program Untuk Membaca data python dari komunikasi serial
//   while (Serial.available()) {
//     inChar = (char)Serial.read();
//     inputString += inChar;
//     d.indexOf('>');

//     if (inChar == 'x') {  // Membaca Data x frame kamera dari python
//       x = inputString.toInt();
//       if (x >= 500) {
//         belok = 1;
//       } else if (x <= 100 && x > 0) {
//         belok = 0;
//       }
//       inputString = "";
//     }

//     else if (inChar == 'y') {  // Membaca Data y frame kamera dari python
//       y = inputString.toInt();
//       inputString = "";
//     } else if (inChar == '>') {  // Membaca Data basestation dari python
//       d = inputString;
//       inputString = "";
//     }
//     //    else if (inChar == 'v') {
//     //      v = inputString.toInt();
//     //      inputString = "";
//     //    }
//     //    else if (inChar == 'w') {
//     //      w = inputString.toInt();
//     //      inputString = "";
//     //      stringComplete = true;
//     //    }
//   }
// }


//  serial event baru-baru  
//  inibener untuk baca program x dan y kamera
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    // Serial.print("data basestation = "); Serial.println(inChar);

    if (inChar == '>') {
      // Cek apakah formatnya benar
      int xIndex = inputString.indexOf('x');
      int yIndex = inputString.indexOf('y');
      int endIndex = inputString.indexOf('>');

      if (xIndex != -1 && yIndex != -1 && endIndex != -1 && yIndex > xIndex) {
        int xVal = inputString.substring(xIndex + 1, yIndex).toInt();
        int yVal = inputString.substring(yIndex + 1, endIndex).toInt();

        // Serial.print("[Arduino] Diterima x: ");
        // Serial.print(xVal);
        // Serial.print(", y: ");
        // Serial.println(yVal);
        // Serial.print("data basestation = "); Serial.println(inChar);

        x = xVal;
        y = yVal;

        if (x == 0 && y == 0) {
          bola_terdeteksi = false;
        } else {
          bola_terdeteksi = true;
          Serial.println("[Arduino] ==> Bola Terdeteksi!");
        }
      } else {
        // === Format perintah: M1>, m2>, dsb
        d = inputString;  // Simpan ke variabel d
        // komunikasi();     // Panggil logika mode
      }

      // Reset input string
      inputString = "";
    }
  }
}




void UpdatePosisi() {  // Program milis untuk program posisi agar program lain berjalan bersamaan program lainnya (https://mr-leong.com/apa-itu-milis-pada-arduino-dan-cara-penggunaanya/)
  unsigned long currentMillis = millis();
  // unsigned long previousMillis; //uji gpt diapos bae, karna harusnyo dionih diluar void UpdatePosisi
  if (currentMillis - previousMillis >= 10) {
    // Serial.print("|"); 
    posisi();
    serialEvent();
    previousMillis = currentMillis;
  }
}


