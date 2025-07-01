//----------Program MODA5 Kondisi gerakan moda 5 dalam pertandingan -----------//
void Moda5 () {
//  komunikasi();  //INI DI EDOPKE MEN NAK MODE KOMUNIKASI
 kompas();
 baca_kamera();
 UpdatePosisi();
 sharpgp();
 bkirifix();
 bkananfix();
 dribble_on1();
 dribble_on2();
 pid_kompas();
 logic_cmps = 1;

// lcd.setCursor(0, 0); lcd.print("S = ");
//   lcd.setCursor(5, 0); lcd.print(sudut); lcd.print("   ");
//   lcd.setCursor(0, 1); lcd.print("X = ");
//   lcd.setCursor(5, 1); lcd.print(X); lcd.print("   ");
//   lcd.setCursor(0, 2); lcd.print("Y = ");
//   lcd.setCursor(5, 2); lcd.print(Y); lcd.print("   ");
//   lcd.setCursor(10, 2); lcd.print(nyampe); lcd.print("   ");
//   lcd.setCursor(14, 2); lcd.print(step); lcd.print("   ");

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

//  if (langkah5 == 0) {             //Robot Stay Home
//       ledData(1, 0 , 0, 0, 0, 0);
//    X = 0;
//    Y = 0;
   
//    motor(0, 0, 0);

//    if (d == "S5>" || d == "s5>" || !ok  ) {
//      X = 0;
//      Y = 0;
//      langkah5 = 1;
//    }
//  }

 //================================== Mode Komunikasi ===============================================//
 //Kondisi misal Basestation ngerem s5 dan kondisi di langkah5 = 0 maka program masuk ke langkah5 =1 Moda5

// if (langkah2 == 1){
  nyampe = false;
  step = 1;                       //Robot bergerak ke kiri
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 3) kec /= 2;
    go_to(0, 20, Y, kec);
  }
  motor(0, 0, 0);
  // delay(500);
  
  nyampe = false;
  step = 2;                       //Robot bergerak maju bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 3) kec /= 2;
    go_to(0, 20, 23, kec);
  }
  motor(0, 0, 0);
  // delay(500);

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

  nyampe = false;
  step = 4;                        //Robot bergerak ke samping setelah menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 3) kec /= 2;
    go_to(0, 5, 23, kec);
  }
  motor(0, 0, 0);
  // delay(500);

  nyampe = false;
  step = 5;                        //Robot mengubah sudut operan robot
  while (nyampe == false) {
    update_data();
    go_to(85, X, Y, 0);
  }
  motor(0, 0, 0);
  // delay(500);

  nyampe = false;
  step = 6;                         //Robot menendang langsung ke gawang
  dapetBola = false;
  bool sudahKickON = false;
  while (dapetBola == false){
    update_data();
    if (dapetBola) {
    dapetBola = true;
    if (!sudahKickON) {
      delay(800);
      dribble_off();
      delay(800);
      siuuON();
      sudahKickON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
      // lcd.setCursor(10, 1); lcd.print("SDH");
      }
    }
  }
  motor(0, 0, 0);
  delay(500);

  nyampe = false;
  step = 7;                        //Robot bergerak ke samping untuk kembali
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, 12, 23, kec);
  }
  motor(0, 0, 0);
  delay(500);

  nyampe = false;
  step = 8;                        //Robot bergerak mundur untuk kembali ke posisi awal
  while (nyampe == false) {
    int kec = 140;
    if (r <= 2) kec /= 2;
    update_data();
    go_to(0, 12, 0, kec);
  }
  motor(0, 0, 0);
  delay(500);

  nyampe = false;
  step = 9;                              //Robot bergerak mundur ke posisi awal
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, 0, 0, kec);
  }
  motor(0, 0, 0);
  delay(10000);
}

// ================= MODA 5 YANG NGOPER ==================
// if (langkah2 == 1){
  // nyampe = false;
  // step = 1;                       //Robot bergerak ke kiri
  // while (nyampe == false) {
  //   update_data();
  //   int kec = 140;
  //   if (r <= 3) kec /= 2;
  //   go_to(0, 20, Y, kec);
  // }
  // motor(0, 0, 0);
  // // delay(500);
  
  // nyampe = false;
  // step = 2;                       //Robot bergerak maju bersiap menerima bola
  // while (nyampe == false) {
  //   update_data();
  //   int kec = 140;
  //   if (r <= 3) kec /= 2;
  //   go_to(0, X, 23, kec);
  // }
  // motor(0, 0, 0);
  // // delay(500);

  // nyampe = false;
  // step = 3;                           //Robot mengoper bola ke R2
  // dapetBola = false;
  // bool sudahOperON = false;
  // while (!dapetBola){
  //   update_data();
  //   if (dapetBola) {
  //   // lcd.setCursor(10, 0); lcd.print("DAPET");
  //   if (!sudahOperON) {
  //     delay(500);
  //     dribble_off();
  //     delay(800);
  //     operanON();
  //     sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
  //     }
  //   }
  // }
  // motor(0, 0, 0);
  // // delay(1000);

  // nyampe = false;
  // step = 4;                        //Robot bergerak balek
  // while (nyampe == false) {
  //   update_data();
  //   int kec = 140;
  //   if (r <= 2) kec /= 2;
  //   go_to(0, X, 0, kec);
  // }
  // motor(0, 0, 0);
  // // delay(1000);

  // nyampe = false;
  // step = 5;                        //Robot bergerak balek
  // while (nyampe == false) {
  //   update_data();
  //   int kec = 140;
  //   if (r <= 2) kec /= 2;
  //   go_to(0, 0, 0, kec);
  // }
  // motor(0, 0, 0);
  // delay(10000);

//============KONDISI RETRY=============
//  if (langkah2 == 2){
//   nyampe = false;
//   step = 10;
//   while (nyampe == false) {
//     update_data();
//     go_to(0, X, 0, 100);
//     nyampe = true;
//   }
//   motor(0, 0, 0);
//   delay(1000);

//    nyampe = false;
//   step = 11;
//   while (nyampe == false) {
//     update_data();
//     go_to(0, 0, Y, 100);
//     nyampe = true;
//   }
//   motor(0, 0, 0);
//   delay(1000);
//   }

 //  else {
 //    operOFF();
 //    kickOFF();
 //  }
// }
