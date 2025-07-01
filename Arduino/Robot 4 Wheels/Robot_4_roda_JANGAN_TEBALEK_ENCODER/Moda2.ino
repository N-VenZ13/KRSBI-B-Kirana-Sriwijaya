//----------Program MODA1 Kondisi gerakan moda 1 dalam pertandingan -----------//
void Moda2 () {
 komunikasi();  //INI DI EDOPKE MEN NAK MODE KOMUNIKASI
 kompas();
 baca_kamera();
 kejar_bola();
 UpdatePosisi();
 sharpgp();
 bkirifix();
 bkananfix();
 dribble_on1();
 dribble_on2();
 pid_kompas();
 logic_cmps = 1;

  // lcd.setCursor(0, 0); lcd.print("S = ");
  // lcd.setCursor(5, 0); lcd.print(sudut); lcd.print("   ");
  // lcd.setCursor(0, 1); lcd.print("X = ");
  // lcd.setCursor(5, 1); lcd.print(X); lcd.print("   ");
  // lcd.setCursor(0, 2); lcd.print("Y = ");
  // lcd.setCursor(5, 2); lcd.print(Y); lcd.print("   ");
  // lcd.setCursor(10, 2); lcd.print(nyampe); lcd.print("   ");
  // lcd.setCursor(14, 2); lcd.print(step); lcd.print("   ");

 //  lcd.setCursor(0, 0); lcd.print("L1 = ");
 //  lcd.setCursor(5, 0); lcd.print(langkah5); lcd.print("   ");
 //  lcd.setCursor(0, 1); lcd.print("L2 = ");
 //  lcd.setCursor(5, 1); lcd.print(langkah5); lcd.print("   ");
 //  lcd.setCursor(0, 2); lcd.print("L3 = ");
 //  lcd.setCursor(5, 2); lcd.print(langkah5); lcd.print("   ");

 //  Serial.print("S = ");
 //  Serial.println(sudut);
 //  Serial.print("||");
 //  Serial.print("X = ");
 //  Serial.print(X);
 //  Serial.print("||");
 //  Serial.print("Y = ");
 //  Serial.println(Y);

//  if (langkah == 0) {             //Robot Stay Home
//    X = 0;
//    Y = 0;
//    motor(0, 0, 0);
//   //  siap = false;
//    if (d == "S1>" || d == "s1>" || !ok  ) {
//      X = 0;
//      Y = 0;
//      langkah = 1;
//    }
//  }

 //================================== Mode Komunikasi ===============================================//
 //Kondisi misal Basestation ngerem s1 dan kondisi di langkah = 0 maka program masuk ke langkah =1 Moda1

//  if (langkah == 1){
  nyampe = false;
  step = 1;                       //Robot bergerak ke kiri
  while (nyampe == false) {
    int kec = 140;
    if (r <= 3) kec /= 2;
    update_data();
    go_to(0, 18, 0, kec);
  }
  motor(0, 0, 0);
  // delay(500);
  
  nyampe = false;
  step = 2;                       //Robot bergerak maju bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 3) kec /= 2;
    
    go_to(0, X, 25, kec);
  }
  motor(0, 0, 0);
  // delay(500);

  
   nyampe = false;
  step = 3;                       //Robot menerima bola dari R2
  dapetBola = false;
  bkiri = false;
  bkanan = false;
  while (!nyampe) {
  update_data();
  while (!dapetBola) {
    update_data();
    if (bkiri && !bkanan) {
        update_data();
        omni (330,0,150);
        delay(300);
        omni (0,0,0);
      }
      else if (bkanan && !bkiri) {
        update_data();
        omni (60,0,150);
        delay(300);
        omni (0,0,0);
      }
    if (dapetBola) {
    nyampe = true;
  }
 }
}
//  lcd.setCursor(10, 0); lcd.print("DAPET");
 motor(0, 0, 0);
//  delay(500);

//   nyampe = false;
//   step = 3;                       //Robot menerima bola dari R1
//   dapetBola = false;
//   while (!nyampe) {
//   update_data();
//   while (!dapetBola) {
//     update_data(); 
//     nyampe = true;
//   }
//  }
// //  lcd.setCursor(10, 0); lcd.print("DAPET");
//  motor(0, 0, 0);
// //  delay(500);

  nyampe = false;
  step = 4;                        //Robot bergerak ke samping kanan untuk mengoper bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, 10, 23, kec);
  }
  motor(0, 0, 0);
  // delay(500);

 nyampe = false;
 step = 5;                         //Robot mengoper bola ke R1
 dapetBola = false;
 bool sudahOperON = false;
 while (!nyampe) {
  update_data();
  if (dapetBola && !sudahOperON) {
    dribble_off();
    delay(800);
    operON();
    sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
    // lcd.setCursor(10, 1); lcd.print("SDH");
    nyampe = true;
  }
 }
 motor(0, 0, 0);
//  delay(500);

  nyampe = false;
  step = 6;                        //Robot bergerak ke samping bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, -3, Y, kec);
  }
  motor(0, 0, 0);
  // delay(500);

  nyampe = false;
  step = 7;                       //Robot menerima bola dari R2
  dapetBola = false;
  bkiri = false;
  bkanan = false;
  while (!nyampe) {
  update_data();
  while (!dapetBola) {
    update_data();
    if (bkiri && !bkanan) {
        update_data();
        omni (330,0,150);
        delay(300);
        omni (0,0,0);
      }
      else if (bkanan && !bkiri) {
        update_data();
        omni (60,0,150);
        delay(300);
        omni (0,0,0);
      }
    if (dapetBola) {
    nyampe = true;
  }
 }
}
//  lcd.setCursor(10, 0); lcd.print("DAPET");
 motor(0, 0, 0);
//  delay(500);

//   nyampe = false;
//   step = 7;                       //Robot menerima bola dari R1
//   dapetBola = false;
//   while (!nyampe) {
//   update_data();
//   while (!dapetBola) {
//     update_data();
//     nyampe = true;
//     // lcd.setCursor(10, 0); lcd.print("DAPET");
//   }
//  }
//  //  lcd.setCursor(10, 0); lcd.print("DAPET");
//   motor(0, 0, 0);
//  //  delay(500);

  nyampe = false;
  step = 8;                        //Robot bergerak ke samping kanan untuk mengoper bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, -14, Y, kec);
  }
  motor(0, 0, 0);
  // delay(500);

 nyampe = false;
 step = 9;                          //Robot mengoper bola lagi ke R1
 dapetBola = false;
 sudahOperON = false;
 while (!nyampe) {
  update_data();
  if (dapetBola && !sudahOperON) {
    // lcd.setCursor(10, 0); lcd.print("DAPET");
    dribble_off();
    delay(800);
    operON();
    sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
    // lcd.setCursor(10, 1); lcd.print("SDH");
    nyampe = true;
  }
 }
 motor(0, 0, 0);
//  delay(500);

  nyampe = false;
  step = 10;                        //Robot bergerak mundur
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, X, 0, kec);
  }
  motor(0, 0, 0);
  // delay(500);

  nyampe = false;
  step = 11;                        //Robot bergerak ke kiri mencari posisi semula
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, 0, 0, kec);
  }
  motor(0, 0, 0);
  delay(10000);
}

 // ============KONDISI RETRY=============
//  if (langkah == 2){
//   nyampe = false;
//   step = 12;
//   while (nyampe == false) {
//     update_data();
//     go_to(0, X, 0, 100);
//     nyampe = true;
//   }
//   motor(0, 0, 0);
//   delay(1000);

//    nyampe = false;
//   step = 13;
//   while (nyampe == false) {
//     update_data();
//     go_to(0, 0, Y, 100);
//     nyampe = true;
//   }
//   motor(0, 0, 0);
//   delay(1000);
//   }

//   else {
//     operOFF();
//     kickOFF();
//   }
// }
