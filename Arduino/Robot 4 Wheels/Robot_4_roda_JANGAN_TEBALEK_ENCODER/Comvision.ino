void baca_kamera() {        //Program buatan untuk menjalankan komunikasi serial dari python
  while (stringComplete) {
    stringComplete = false;
  }
}

void kejar_bola() {             //Program untuk ngejer bola pada saat deteksi bola dari python (pastikan nilai x dan y frame kamera sudah masuk di arduino)
  //  myservo.write(servoBola);
  baca_kamera();
  error = 345 - x;    // sebelah kiri + sebelah kanan -
  P = 3 * error;
  I = 0 * (error + last_error);
  D = 2 * (error - last_error);
  //===========hilang bola===========
  if (dapetBola == false) {
    if (x == 0 && y == 0) {   // jika nilai kamera depan 0 atau tidak ada bola
      if (belok == 1) {
        motor(30, 30, 30);
      }
      else {
        motor(-30, -30, -30);
      }
    }
    //===========kejar bola=============
    else {
      if (y > 0 && y <= 150) {                                        // Bola Jauh
        if (error > -100 && error < 100) {
          PD = constrain(P + I + D, -50, 50);
        }
        else if (error < -250 || error > 250) {
          PD = constrain(P + I + D, -50, 50);
        }
        last_error = error;
        speed = 50;
        omni(0, PD, speed);
      }
      else if (y > 100 && y <= 400) {                                // Bola deket 150
        if (error > -100 && error < 100) {          // Tidak parah
          PD = constrain(P + I + D, -50, 50);
        }
        else if (error < -250 || error > 250) {     // Parah kiri atau kanan
          PD = constrain(P + I + D, -50, 50);
        }
        last_error = error;
        speed = 50;
        omni(0, PD, speed);
      }
      else if (y > 400 && y <= 480) {                                // Bola deket 400,480
        if (error > -100 && error < 100) {          // Tidak parah
          PD = constrain(P + D, -30, 30);
        }
        else if (error < -250 || error > 250) {     // Parah kiri atau kanan
          PD = constrain(P + D, -60, 60);
        }
        last_error = error;
        speed = 50;
        omni1(0, PD, speed);
      }
    }
  }
//  else if (langkah == 3 && dapetBola == true) {
//    motor(0, 0, 0);
//    //    langkah = 4 ;
//  }
  //    else if (dapetBola == true) {   // yang normal..
  //      langkah += 1;
  //    }
  //  else if (langkah == 7 && sgp < 500 && Y < 26 && X >= -5) {
  //    langkah = 8;
  //  }
  //  else if (langkah == 7 && sgp < 500 && Y < 26 && X < -5) {
  //    langkah = 8;
  //  }
  //  else if (langkah == 7 && sgp < 500 && Y >= 26 && X >= -5) {
  //    langkah = 20;
  //  }
  //  else if (langkah == 7 && sgp < 500 && Y >= 26 && X < -5) {
  //    langkah = 21;
  //  }
}

void tangkapBola(int knt) {
  int spid;
  int arah;
  baca_kamera();
  setPoint_k = knt;
  pid_kompas();
  if (x > 0 && x < 300) {   //
    spid = 50;
    arah = 90;
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 300 && x < 400) {   //
    spid = 50;
    arah = 0;
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 400 && x < 640) {
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
  if (x > 0 && x < 300) {   //
    spid = 60;            //kecepatan
    arah = 90;            // sudut
    omni1(arah, pwm_k, spid);
  }
  else if (x >= 300 && x < 400) {   //
    spid = 0;
    arah = 0;
    omni1(arah, pwm_k, spid);
    siap = true;
  }
  else if (x >= 400 && x < 640) {
    spid = 60;
    arah = 270;
    omni1(arah, pwm_k, spid);
  }
  else {
    motor(0, 0, 0);
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
