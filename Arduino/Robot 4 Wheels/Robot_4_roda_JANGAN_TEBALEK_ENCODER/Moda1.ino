//----------Program MODA2 Kondisi gerakan moda 2 dalam pertandingan -----------//
 void Moda1 () {
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

  //  if (langkah2 == 0) {             //Robot Stay Home
  //    motor(0, 0, 0);
  //    siap = false;
  //    if (d == "S2>" || d == "s2>" || !ok  ) {
  //      X = 0;
  //      Y = 0;
  //      langkah2 = 1;
  //    }
  //  }

 //================================== Mode Komunikasi ===============================================//
 //Kondisi misal Basestation ngerem s2 dan kondisi di langkah2 = 0 maka program masuk ke langka2 = 1 Moda2

 //  if (langkah2 == 1){
  nyampe = false;
  step = 1;                       //Robot bergerak ke kiri
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 3) kec /= 2;
    go_to(0, 18, 0, kec);
  }
  motor(0, 0, 0);
  // delay(800);
  
  nyampe = false;
  step = 2;                       //Robot bergerak maju bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 130;
    if (r <= 3) kec /= 2;
    go_to(0, 18, 35, kec);
  }
  motor(0, 0, 0);
  // delay(800);

  nyampe = false;
  step = 3;                           //Robot mengoper bola ke R2
  dapetBola = false;
  bool sudahOperON = false;
  while (!dapetBola){
    update_data();
    if (dapetBola) {
    // lcd.setCursor(10, 0); lcd.print("DAPET");
    if (!sudahOperON) {
      delay(500);
      dribble_off();
      delay(800);
      operanON();
      sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
      }
    }
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 4;                        //Robot bergerak ke samping bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 120;
    if (r <= 2) kec /= 2;
    go_to(0, 18, 23, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 5;                        //Robot bergerak ke samping bersiap menerima bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, 10, 23, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  // nyampe = false;
  // step = 6;                       //Robot menerima bola dari R2
  // dapetBola = false;
  // while (!nyampe) {
  //   update_data();
  //   while (!dapetBola) {
  //     update_data();
  //     nyampe = true;
  //   }
  // }
  // // lcd.setCursor(10, 0); lcd.print("DAPET");
  // motor(0, 0, 0);
  // // delay(1000);

   nyampe = false;
  step = 6;                       //Robot menerima bola dari R2
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
 motor(0, 0, 0);


  nyampe = false;
  step = 7;                        //Robot bergerak ke samping kanan untuk mengoper bola
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, -2.5, 23, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 8;                         //Robot mengoper bola lagi ke R2
  dapetBola = false;
  sudahOperON = false;
  while (dapetBola == false){
    update_data();
    if (dapetBola) {
    dapetBola = true;
    if (!sudahOperON) {
      dribble_off();
      delay(800);
      operanON();
      sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
      // lcd.setCursor(10, 1); lcd.print("SDH");
      }
    }
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 9;                        //Robot bergerak ke samping kanan untuk menerima bola
    while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, -15, 23, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  // nyampe = false;
  // step = 10;                           //Robot menerima bola dari R2
  // dapetBola = false;
  // while (!nyampe) {
  // update_data();
  // while (!dapetBola) {
  //   update_data();
  //   nyampe = true;
  //  }
  // }
  // // lcd.setCursor(10, 0); lcd.print("DAPET");
  // motor(0, 0, 0);
  // // delay(1000);


   nyampe = false;
  step = 10;                       //Robot menerima bola dari R2
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
  step = 11;                        //Robot bergerak ke samping kanan untuk mengoper bola
    while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 2) kec /= 2;
    go_to(0, -20, 23, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 12;                          //Robot mengubah sudut untuk ngeGOAL!!!
  while (nyampe == false) {
    update_data();
    // int kec = 140;
    // if (r <= 2) kec /= 2;
    go_to(65, X, Y, 0);
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 13;                          //Robot ngeGOAL!!!
  dapetBola = false;
  bool sudahKickON = false;
  while (dapetBola == false){
    update_data();
    if (dapetBola) {
    dapetBola = true;
    if (!sudahKickON) {
      dribble_off();
      delay(800);
      kickON();
      sudahKickON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
      // lcd.setCursor(10, 1); lcd.print("SDH");
      }
    }
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 14;                              //Robot bergerak mundur
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 5) kec /= 2;
    go_to(0, X, 0, kec);
  }
  motor(0, 0, 0);
  // delay(1000);

  nyampe = false;
  step = 15;                              //Robot bergerak ke kanan mencari posisi semula
  while (nyampe == false) {
    update_data();
    int kec = 140;
    if (r <= 5) kec /= 2;
    go_to(0, -5, Y, kec);
  }
  motor(0, 0, 0);
  delay(10000);
 }

   //============KONDISI RETRY=============
  //  if (langkah2 == 2){
  //   nyampe = false;
  //   step = 16;
  //   while (nyampe == false) {
  //     update_data();
  //     go_to(0, X, 0, 100);
  //     nyampe = true;
  //   }
  //   motor(0, 0, 0);
  //   delay(1000);

  //    nyampe = false;
  //   step = 17;
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
