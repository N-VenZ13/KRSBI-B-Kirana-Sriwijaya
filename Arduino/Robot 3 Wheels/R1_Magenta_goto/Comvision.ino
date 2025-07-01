void baca_kamera() {        //Program buatan untuk menjalankan komunikasi serial dari python
  Serial.println("baca kamera");
  while (stringComplete) {
    stringComplete = false;
  }
}


// fungsi sementara
// void tangkapBolaOmniDekat(int knt) {
//   int spid;
//   int arah;
//   baca_kamera();
//   setPoint_k = knt;
//   pid_kompas();
//   if (x >= 630 && x <= 700 && y >= 420 && y <= 450) {   // kirii
//     spid = 100;
//     arah = 90;
//     omni1(arah, pwm_k, spid);
//   }
  
//   else if (x >= 705 && x <= 725 && y >= 380 && y <= 410) {   // tengah
//     spid = 50;
//     arah = 0;
//     omni1(arah, pwm_k, spid);
//   }
//   else if (x >= 730 && x <= 800 && y >= 300 && y <= 360) {    // kanan
//     spid = 100;
//     arah = 270;
//     omni1(arah, pwm_k, spid);
//   }
//   else {
//     motor(0, 0, 0);
//   }
// }


void tangkapBolaOmni(int knt) {
  int spid;
  int arah;
  baca_kamera();
  setPoint_k = knt;
  pid_kompas();
  if (x >= 760 && x <= 900) {   // kiri
    spid = 60;
    arah = 90;
    omni1(arah, pwm_k, spid);
  }
  
  else if (x >= 720 && x <= 759) {   // tengah
    spid = 0;
    arah = 0;
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 550 && x < 715) { // kanan
    spid = 60; 
    arah = 270;
    omni1(arah, pwm_k, spid);
  }
  else {
    motor(0, 0, 0);
  }
}

void kejar_bola_omni() {

  int target_x = 740;
      error = target_x - x;
      P = 3 * error;
      D = 1.5 * (error - last_error);
      last_error = error;
      PD = constrain(P + D, -40, 40);
      // omni(0, PD, speed);
      // Serial.println("Fallback PID koreksi posisi");

  if (bola_terdeteksi) {
    speed = 50;

    // ZONA TENGAH (bola sudah ideal)
    if (x >= 720 && x <= 745 && y >= 32 && y <= 164) {
      omni(0, 0, speed);  // stop, siap tendang
      Serial.println("Bola di TENGAH → SIAP TENDANG");
    }

    // ZONA KIRI
    else if (x >= 746 && x <= 796 && y >= 50 && y <= 184) {
      omni(0, 30, speed);  // belok kanan dikit
      Serial.println("Bola di KIRI");
    }

    // ZONA KIRI-KIRI
    else if (x >= 792 && x <= 824 && y >= 51 && y <= 160) {
      speed = speed - 10;
      omni(0, 40, speed);  // belok kanan lebih besar
      Serial.println("Bola di KIRI-KIRI");
    }

    // ZONA KIRI-KIRI-KIRI
    else if (x >= 825 && x <= 871 && y >= 48 && y <= 154) {
      speed = speed - 20;
      omni(0, 50, speed);  // belok kanan besar
      Serial.println("Bola di KIRI-KIRI-KIRI");
    }

    // ZONA KANAN
    else if (x >= 681 && x <= 719 && y >= 44 && y <= 144) {
      omni(0, -40, speed);  // belok kiri dikit
      Serial.println("Bola di KANAN");
    }

    // ZONA KANAN-KANAN
    else if (x >= 605 && x <= 680 && y >= 31 && y <= 168) {
      speed = speed - 10;
      omni(0, -50, speed);  // belok kiri lebih besar
      Serial.println("Bola di KANAN-KANAN");
    }

    // ZONA KANAN-KANAN-KANAN
    else if (x >= 550 && x <= 600 && y >= 40 && y <= 189) {
      speed = speed - 20;
      omni(0, -60, speed);  // belok kiri besar
      Serial.println("Bola di KANAN-KANAN-KANAN");
    }

    // FALLBACK PID (jika x/y di luar zona)
    // else {
    //   int target_x = 740;
    //   error = target_x - x;
    //   P = 2 * error;
    //   D = 1 * (error - last_error);
    //   last_error = error;
    //   PD = constrain(P + D, -40, 40);
    //   omni(0, PD, speed);
    //   Serial.println("Fallback PID koreksi posisi");
    // }
  } else {
    // Bola tidak terdeteksi → muter cari
    Serial.println("Bola tidak terdeteksi, scanning...");
    if (belok == 1) {
      motor(30, 30, 30);
    } else {
      motor(-30, -30, -30);
    }
  }
}



void kejar_bola_omni_360(){
  if (bola_terdeteksi) {
    // Kalibrasi titik tengah berdasarkan data kamera
    int target_x = 755;
    error = target_x - x;

    // PID
    P = 3 * error;
    I = 0; // bisa dikembangkan jadi integral sesungguhnya
    D = 1.5 * (error - last_error);
    last_error = error;

    // Bola terlihat
    if (y >= 260 && y <= 500) {
      if (x >= 730 && x <= 820 && y >= 400 && y <= 500) {
        // Bola sudah di depan, siap tendang
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);  // Bergerak ke depan
      } else if (x < 664 || x > 820) {
        // Bola terlalu ke kiri atau ke kanan, koreksi besar
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      } else if (x >= 400 && x <= 450 && y >= 400 && y <= 450) {
        // robot gerak kekiri ngambil bola 
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(90, PD, speed);
      } else {
        // Koreksi biasa
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      }
      // dapetBola = true;
    }
  } else {
    // Bola tidak terdeteksi, cari bola
    if (belok == 1) {
      motor(30, 30, 30);  // Putar kanan
    } else {
      motor(-30, -30, -30);  // Putar kiri
    }
  }
}


// yang baru dibuat nooven
// ini menggunakan kamera omni tapo yang di kalibrasi hanya ketika bola berada di depan robot
void kejar_bola_omni_depan() {
  if (bola_terdeteksi) {
    // Kalibrasi titik tengah berdasarkan data kamera
    int target_x = 740;
    error = target_x - x;

    // PID
    P = 3 * error;
    I = 0; // bisa dikembangkan jadi integral sesungguhnya
    D = 1.5 * (error - last_error);
    last_error = error;

    // Bola terlihat
    if (y > 30) {
      if (x >= 720 && x <= 759 && y >= 30 && y <= 180) {
        // Bola sudah di depan, siap tendang
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);  // Bergerak ke depan
      } else if (x < 719 || x > 760) {
        // Bola terlalu ke kiri atau ke kanan, koreksi besar
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      } else {
        // Koreksi biasa
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      }
      // dapetBola = true;
    }
  } else {
    // Bola tidak terdeteksi, cari bola
    if (belok == 1) {
      motor(30, 30, 30);  // Putar kanan
    } else {
      motor(-30, -30, -30);  // Putar kiri
    }
  }
}


void kejar_bola() {
  // Serial.println("kejar bola");
  // Serial.print("Status bola_terdeteksi: ");
  // Serial.println(bola_terdeteksi ? "YA" : "TIDAK");

  if (bola_terdeteksi) {
    // Hitung error
    error = 345 - x;

    // Perhitungan kontrol PID
    P = 3 * error;
    I = 0.5;
    D = 1.5 * (error - last_error);

    last_error = error;

    if (y > 0 && y <= 480) {
      if (error > -100 && error < 100) {
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      } else if (error < -250 || error > 250) {
        PD = constrain(P + D, -50, 50);
        speed = 50;
        omni(0, PD, speed);
      }
      dapetBola = true;
    }
  } else {
    // Bola tidak terdeteksi
    if (belok == 1) {
      motor(30, 30, 30);
    } else {
      motor(-30, -30, -30);
    }
  }
}


// void kejar_bola() {
//   baca_kamera();
//   // Pastikan nilai x dan y dari kamera valid
//   Serial.println("kejar bola");
//   if (x >= 0 && y >= 0) {
//     // Hitung error
//     error = 345 - x;
    
//     // Perhitungan kontrol PID
//     P = 3 * error;
//     I = 0.5; // Sementara tidak ada integrasi
//     D = 1.5 * (error - last_error);
    
//     // Update nilai terakhir error
//     last_error = error;
    
//     // Pengendalian gerakan berdasarkan koordinat bola
//     if (y > 0 && y <= 480) {
//       if (error > -100 && error < 100) { // Bola jauh
//         PD = constrain(P + D, -50, 50);
//         speed = 50;
//         omni(0, PD, speed);
//       } else if (error < -250 || error > 250) { // Bola dekat atau berada di tepi
//         PD = constrain(P + D, -50, 50); // Sesuaikan batasan sesuai kebutuhan
//         speed = 50;
//         omni(0, PD, speed);
//       }
//       dapetBola = true;
//     }
//     // if (dapetBola) {
//     // dapetBola = true;
//     // }
//   } else {
//     // Jika tidak ada bola terdeteksi, putar robot
//     if (belok == 1) {
//       motor(30, 30, 30);
//     } else {
//       motor(-30, -30, -30);
//     }
//   }
// }
// // yang sebelumnyo
// void kejar_bola() {             //Program untuk ngejer bola pada saat deteksi bola dari python (pastikan nilai x dan y frame kamera sudah masuk di arduino)
//   //  myservo.write(servoBola);
//   baca_kamera();
//   error = 345 - x;    // sebelah kiri + sebelah kanan -
//   P = 3 * error;
//   I = 0 * (error + last_error);
//   D = 2 * (error - last_error);
//   //===========hilang bola===========
//   if (dapetBola == false) {
//     if (x == 0 && y == 0) {   // jika nilai kamera depan 0 atau tidak ada bola
//       if (belok == 1) {
//         motor(30, 30, 30);
//       }
//       else {
//         motor(-30, -30, -30);
//       }
//     }
//     //===========kejar bola=============
//     else {
//       if (y > 0 && y <= 150) {                                        // Bola Jauh
//         if (error > -100 && error < 100) {
//           PD = constrain(P + I + D, -50, 50);
//         }
//         else if (error < -250 || error > 250) {
//           PD = constrain(P + I + D, -50, 50);
//         }
//         last_error = error;
//         speed = 50;
//         omni(0, PD, speed);
//       }
//       else if (y > 100 && y <= 400) {                                // Bola deket 150
//         if (error > -100 && error < 100) {          // Tidak parah
//           PD = constrain(P + I + D, -50, 50);
//         }
//         else if (error < -250 || error > 250) {     // Parah kiri atau kanan
//           PD = constrain(P + I + D, -50, 50);
//         }
//         last_error = error;
//         speed = 50;
//         omni(0, PD, speed);
//       }
//       else if (y > 400 && y <= 480) {                                // Bola deket 400,480
//         if (error > -100 && error < 100) {          // Tidak parah
//           PD = constrain(P + D, -30, 30);
//         }
//         else if (error < -250 || error > 250) {     // Parah kiri atau kanan
//           PD = constrain(P + D, -60, 60);
//         }
//         last_error = error;
//         speed = 50;
//         omni1(0, PD, speed);
//       }
//     }
//   }
// }

  //  else if (langkah == 3 && dapetBola == true) {
  //    motor(0, 0, 0);
  //    //    langkah = 4 ;
  //  }
  //      else if (dapetBola == true) {   // yang normal..
  //        langkah += 1;
  //      }
  //    else if (langkah == 7 && sgp < 500 && Y < 26 && X >= -5) {
  //      langkah = 8;
  //    }
  //    else if (langkah == 7 && sgp < 500 && Y < 26 && X < -5) {
  //      langkah = 8;
  //    }
  //    else if (langkah == 7 && sgp < 500 && Y >= 26 && X >= -5) {
  //      langkah = 20;
  //    }
  //    else if (langkah == 7 && sgp < 500 && Y >= 26 && X < -5) {
  //      langkah = 21;
  //    }


void tangkapBola(int knt) {
  int spid;
  int arah;
  baca_kamera();
  setPoint_k = knt;
  pid_kompas();
  if (x >= 300 && x <= 470 && y >= 170 && y <= 400) {   //
    spid = 50;
    arah = 90;
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 645 && x <= 670 && y >= 170 && y <= 500) {   //
    spid = 50;
    arah = 0;
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 870 && x <= 990 && y >= 170 && y <= 400) {
    spid = 50;
    arah = 270;
    omni1(arah, pwm_k, spid);
  }
  else {
    motor(0, 0, 0);
  }
}


void tangkapBolaModa2(int knt) {
  int spid;
  int arah;
  baca_kamera();
  setPoint_k = knt;
  pid_kompas();
  // Pengecekan posisi bola berdasarkan nilai x dari kamera
  if (x > 0 && x < 499) {   // Bola di sebelah kiri
    spid = 60;            // Kecepatan
    arah = 90;            // Sudut
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 500 && x < 700) {   // Bola berada di tengah
    spid = 0;             // Kecepatan dihentikan
    arah = 0;             // Sudut diarahkan ke depan
    omni1(arah, pwm_k, spid);
    siap = true;          // Robot siap menangkap bola
  }
  else if (x >= 701 && x < 1275) {    // Bola di sebelah kanan
    spid = 60;            // Kecepatan
    arah = 270;           // Sudut
    omni1(arah, pwm_k, spid);
  }
  else {
    motor(0, 0, 0);       // Jika tidak ada bola terdeteksi, hentikan robot
  }
}


void tangkap_fuzzy(int knt) {  // Program Pergerakan Robot Dalam Menangkap / menerima Bola
  int spid;
  int arah;
  //  dribble_on2();
  //  myservo.write(servoBola);   // bola = 120, magenta = 100
  baca_kamera();
  error_k = 0;
  setPoint_k = knt;
  //  pid_kompas();
  //  if (!dapetBola) {
  if (y < 180) {
    if (x > 0 && x < 330) {
      spid = 100;
      arah = 90;
      omni1(arah, 0, spid);
    }
    else if (x >= 330 && x < 410) {
      spid = 0;
      arah = 0;
      motor(0, 0, 0);
      //      siap = true;
    }
    else if (x >= 410 && x < 640) {
      spid = 100;
      arah = 270;
      omni1(arah, 0, spid);
    }
    else {
      motor(0, 0, 0);
    }
  }
  else {
    motor(0, 0, 0);
  }
  //  }
  //  else {
  //    langkah += 1;
  //  }
}
