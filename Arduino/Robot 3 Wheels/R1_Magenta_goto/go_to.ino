//Create By Kak Marcel dan Kak Zafier 2020

//----------Program Buatan Go TO merupakan Program Robot yang bisa berpindah tempat atau bergerak dari titik awal ke titik setpoint yang inginkan  -----------
//Parameter Data Robot yang harus di perhatikan hingga bisa berpindah tempat adalah Nilai Kompas CMPS12, Nilai X dan Y Rotary encoder dan Kecepatan(pwm) MotorPG45

void go_to(int sudut_hadap, int xxx, int yyy, int speed) {
  pid_kompas();               // Panggil PID_kompas() untuk pwm_k (heading ny) pas manggil omni.
  pid_x();                    // Panggil pid_x() untuk pwm_x nyo , gek + pwm_y biar jadi pwm.
  pid_y();                    // Panggil pid_Y() untuk pwm_Y nyo , gek + pwm_X biar jadi pwm.
  setPoint_k = sudut_hadap;   // Paramater sudut_hadap itu adalah setPoint sudut kompas
  setPoint_x = xxx;           // Parameter xxx adalah setPoint Target (X)
  setPoint_y = yyy;           // Parameter xxx adalah setPoint Target (Y)
  xx = xxx - X;               // xx adalah Variabel error_x (kalo di PID) , tujuan nya untuk
  yy = yyy - Y;              // yy adalah Variabel error_y (kalo di PID) , tujuan nya untuk

  float arc_tan = atan2 (xx, yy) * 180 / PI;  // ngubah panjang x dan y dari posisi skrg ke target menjadi sudut
  if (arc_tan < 0) {                    // rumus atan cuma biso dari 1 - 180, lewat dari situ nilai min(-),
    arc_tan = 180 + (179 + arc_tan);    // ngakali ny jadi kalo nilai ny min(-) neruske sampe 360
  }

  int b = 0;                            // Uji marcel kalu dak makek b error dio , nilai nyo beda alias nilai yang dak di pengeni
  arc_tan = arc_tan - b;                // Ini ni samo cak void kompas, guno nyo buat ngubah nilai 0 jadi sudut atas robot
  arc_tan = 360 - arc_tan;
  if (arc_tan < 0) {
    arc_tan = (359 - b) + (b + arc_tan);
  }                                     // ----------------------------------------------------------------------

  pwm = pwm_x + pwm_y;                  // Anggaplah (10,10) tapi X nyo la nyampe , Y nyo masih 10 kan.. mangkonyo dijumlahke
  pwm = fabs(pwm);                      // fabs = nilai mutlak , karena pwm cuma buat dio biar sampe ke setPoint, urusan arah
  xx = xx ;                             // Ntah ngapo
  yy = yy ;                             // Ntah ngapo
  int rxx = xxx * xxx;
  int ryy = yyy * yyy;
  int rx = xx * xx;                     // kuadrat
  int ry = yy * yy;                     // kuadrat
  r = sqrt(ry + rx);                    // radius = jadi idak patokan x smo y.. tapi radius., sqrt = akar.
  int r1 = sqrt(rxx + ryy);
  int pwm1 = r1 - r;
  //  int maxSpeed = 100;
  //  if (pwm1 <= 0.25 && r > 3) {
  //    pwm = constrain(pwm, 0, 41);
  //  }
  //  if (pwm1 > 0.25 && pwm1 <= 0.75 && r > 3) {
  //    pwm = constrain(pwm, 0, 80);
  //  }
  pwm = constrain(pwm, 0, speed);
  //-------------------------------------------------------
  arc_tan = arc_tan - sudut;            // hasil dari arc tan - sudut(skrg)..

  // Serial.println("goto masuk");
  // Serial.println(r);
  omni1(arc_tan, pwm_k, pwm);          // omni(sudut nyo, heading nyo(pid), pwm nyo)
  int stepK = sudut_hadap - sudut;      // kondisi step by step------------------------------------

  // Kondisi pada saat Robot sudah sampai di Setpoint yang di tentukan
  // untuk r itu biso nyesuaike, kalo makek 3 brti pas lah nak 3 nilai nyampe setpoint dio ngerem, kalo 1 brti 1 nilai lgi nyampe setpoint baru ngerem
  if ((stepK <= 10 && stepK >= -10) && (r <= 1))
  {
    nyampe = true;
  // Serial.println("TARGET TERCAPAI");
  // delay(100);
    
  }

  else {
    nyampe = false;
  }

  if ((stepK <= 0 && stepK >= -0) && (r <= 1))
  {
    nyampe1 = true;
  }

  else {
    nyampe1 = false;
  }
}


