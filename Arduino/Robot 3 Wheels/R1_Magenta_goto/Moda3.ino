// //----------Program MODA3 Kondisi gerakan moda 3 dalam pertandingan -----------//
// void Moda3 () {
//  komunikasi();  //INI DI EDOPKE MEN NAK MODE KOMUNIKASI
//  kompas();
//  baca_kamera();
//  kejar_bola();
//  UpdatePosisi();
//  sharpgp();
//  bkirifix();
//  bkananfix();
//  dribble_on1();
//  dribble_on2();
//  pid_kompas();
//  logic_cmps = 1;

//  //  lcd.setCursor(0, 0); lcd.print("L1 = ");
//  //  lcd.setCursor(5, 0); lcd.print(langkah); lcd.print("   ");
//  //  lcd.setCursor(0, 1); lcd.print("L2 = ");
//  //  lcd.setCursor(5, 1); lcd.print(langkah2); lcd.print("   ");
//  //  lcd.setCursor(0, 2); lcd.print("L3 = ");
//  //  lcd.setCursor(5, 2); lcd.print(langkah3); lcd.print("   ");

//  //  lcd.setCursor(0, 2); lcd.print("S = ");
//  //  lcd.setCursor(5, 2); lcd.print(sudut2); lcd.print("   ");
//  //  lcd.setCursor(0, 0); lcd.print("X = ");
//  //  lcd.setCursor(5, 0); lcd.print(X); lcd.print("   ");
//  //  lcd.setCursor(0, 1); lcd.print("Y = ");
//  //  lcd.setCursor(5, 1); lcd.print(Y); lcd.print("   ");

//  //  Serial.print("S = ");
//  //  Serial.println(sudut);
//  //  Serial.print("||");
//  //  Serial.print("X = ");
//  //  Serial.print(X);
//  //  Serial.print("||");
//  //  Serial.print("Y = ");
//  //  Serial.println(Y);

// //  if (langkah3 == 0) {             //Robot Stay Home
// //    //    ledData(1, 0 , 0, 0, 0, 0);
// //    X = 0;
// //    Y = 0;
// //    logic_cmps = 0;
// //    motor(0, 0, 0);
   
// //   //  if (d == "S3>" || d == "s3>" || !ok  ) {
// //      X = 0;
// //      Y = 0;
// //      langkah3 = 1;
// //   //  }
// //  }

//  //================================== Mode Komunikasi ===============================================//
//  //Kondisi misal Basestation ngerem s3 dan kondisi di langkah3 = 0 maka program masuk ke langkah3=1 Moda3

// //  if (langkah3 == 1) {           
//   nyampe = false;
//   step = 1;                       //Robot bergerak ke kanan
//   while (nyampe == false) {
//   update_data();
//   int kec = 140;
//   if (r <= 3) kec /= 2;
//   go_to(0, 15, 0, kec);
//   }
//   motor(0, 0, 0);
//   // delay(800);

//   nyampe = false;
//   step = 2;                       //Robot bergerak ke maju
//   while (nyampe == false) {
//   update_data();
//   int kec = 140;
//   if (r <= 3) kec /= 2;
//   go_to(0, 15, 22, kec);
//   }
//   motor(0, 0, 0);
//   // delay(800);

//   nyampe = false;
//   step = 2.5;                       //Robot bergerak
//   while (nyampe == false) {
//   update_data();
//   int kec = 140;
//   if (r <= 3) kec /= 2;
//   go_to(0, 23, 22, kec);
//   }
//   motor(0, 0, 0);
//   // delay(800);

//   nyampe = false;
//   step = 3;                       //Robot menyesuaikan sudut kearah R1 untuk menangkap bola
//   while (nyampe == false) {
//     update_data();
//     go_to(346, X, Y, 0);
//   }
//   motor(0, 0, 0);
//   // delay(800);

// //   nyampe = false;
// //   step = 4;                       //Robot menerima bola dari R2
// //   dapetBola = false;
// //   bkiri = false;
// //   bkanan = false;
// //   while (!nyampe) {
// //   update_data();
// //   while (!dapetBola) {
// //     update_data();
// //     if (bkiri && !bkanan) {
// //         update_data();
// //         omni (60,0,150);
// //         delay(300);
// //         omni (0,0,0);
// //       }
// //       else if (bkanan && !bkiri) {
// //         update_data();
// //         omni (300,0,150);
// //         delay(300);
// //         omni (0,0,0);
// //       }
// //     if (dapetBola) {
// //     nyampe = true;
// //   }
// //  }
// // }

// //  motor(0, 0, 0);
// //  delay(500);

//   nyampe = false;              
//   step = 4;                       //Robot menangkap bola
//   dapetBola = false;
//   while (!nyampe) {
//     update_data();
//     while (!dapetBola) {
//       update_data(); 
//       nyampe = true;
//   }
//  }
//  lcd.setCursor(10, 0); lcd.print("DAPET");
//  motor(0, 0, 0);
//  delay(500);

//   nyampe = false;
//   step = 5;                       //Robot bergeser ke kanan
//   while (nyampe == false) {
//     update_data();
//     int kec = 140;
//     if (r <= 3) kec /= 2;
//     go_to(0, 3, 23, kec);
//   }
//   motor(0, 0, 0);
//   // delay(80000);

//   nyampe = false;
//   step = 6;                         //Robot mengoper bola ke R1
//   dapetBola = false;
//   bool sudahOperON = false;
//   while (dapetBola == false){
//     update_data();
//     if (dapetBola) {
//     dapetBola = true;
//     if (!sudahOperON) {
//       dribble_off();
//       delay(1000);
//       operON();
//       sudahOperON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
//       // lcd.setCursor(10, 1); lcd.print("SDH");
//       }
//     }
//   }
//   motor(0, 0, 0);
//   // delay(1000);

//   nyampe = false;
//   step = 7;                       //Robot bergerak ke maju
//   while (nyampe == false) {
//   update_data();
//   int kec = 140;
//   if (r <= 3) kec /= 2;
//   go_to(0, 15, 22, kec);
//   }
//   motor(0, 0, 0);
//   // delay(800);

// //   nyampe = false;
// //   step = 8;                       //Robot menerima bola dari R2
// //   dapetBola = false;
// //   bkiri = false;
// //   bkanan = false;
// //   while (!nyampe) {
// //   update_data();
// //   while (!dapetBola) {
// //     update_data();
// //     if (bkiri && !bkanan) {
// //         update_data();
// //         omni (60,0,150);
// //         delay(300);
// //         omni (0,0,0);
// //       }
// //       else if (bkanan && !bkiri) {
// //         update_data();
// //         omni (300,0,150);
// //         delay(300);
// //         omni (0,0,0);
// //       }
// //     if (dapetBola) {
// //     nyampe = true;
// //   }
// //  }
// // }

// //  motor(0, 0, 0);
// //  delay(500);

//   nyampe = false;
//   step = 8;                       //Robot menerima bola dari R2
//   dapetBola = false;
//   while (!nyampe) {
//     update_data();
//     while (!dapetBola) {
//       update_data();
//       nyampe = true;
//     }
//   }
//   lcd.setCursor(10, 0); lcd.print("DAPET");
//   motor(0, 0, 0);
//   delay(1000);

//   nyampe = false;
//   step = 9;                       //Robot nendang
//   while (nyampe == false) {
//     update_data();
//     go_to(300, X, Y, 0);
//   }
//   motor(0, 0, 0);
//   // delay(800);

//   nyampe = false;
//   step = 10;                          //Robot ngeGOAL!!!
//   dapetBola = false;
//   bool sudahKickON = false;
//   while (dapetBola == false){
//     update_data();
//     if (dapetBola) {
//     dapetBola = true;
//     if (!sudahKickON) {
//       dribble_off();
//       delay(1000);
//       kickON();
//       sudahKickON = true; // Setelah dipanggil, tandai bahwa operON() sudah dipanggil
//       // lcd.setCursor(10, 1); lcd.print("SDH");
//       }
//     }
//   }
//   motor(0, 0, 0);
//   // delay(1000);

//   nyampe = false;
//   step = 10.5;                       //Robot menyesuaikan sudut kearah R1 untuk menangkap bola
//   while (nyampe == false) {
//     update_data();
//     go_to(0, X, Y, 0);
//   }
//   motor(0, 0, 0);
//   // delay(800);

//   nyampe = false;
//   step = 11;                              //Robot bergerak mundur
//   while (nyampe == false) {
//     update_data();
//     int kec = 140;
//     if (r <= 3) kec /= 2;
//     go_to(0, X, 0, kec);
//   }
//   motor(0, 0, 0);
//   // delay(1000);

//   nyampe = false;
//   step = 12;                              //Robot bergerak ke kiri mencari posisi semula
//   while (nyampe == false) {
//     update_data();
//     int kec = 140;
//     if (r <= 3) kec /= 2;
//     go_to(0, 0, Y, kec);
//   }
//   motor(0, 0, 0);
//   delay(10000);
//   }

//    //============KONDISI RETRY=============
//   //  if (langkah3 == 2){
//   //   nyampe = false;
//   //   step = 15;
//   //   while (nyampe == false) {
//   //     update_data();
//   //     go_to(0, X, 0, 100);
//   //     nyampe = true;
//   //   }
//   //   motor(0, 0, 0);
//   //   delay(1000);

//   //    nyampe = false;
//   //   step = 16;
//   //   while (nyampe == false) {
//   //     update_data();
//   //     go_to(0, 0, Y, 100);
//   //     nyampe = true;
//   //   }
//   //   motor(0, 0, 0);
//   //   delay(1000);
//   //   }

//   //   else {
//   //     operOFF();
//   //     kickOFF();
//   //   }
//   // }8+++--