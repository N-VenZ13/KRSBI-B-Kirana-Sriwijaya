//----------Program Buatan Komunikasi Data dari Basestation -----------//
void komunikasi() {

  //Program kondisi Moda 1-5 Komunikasi

  //Kondisi misal Basestation ngerem M1 maka Program masuk ke Moda dan langkah = 0
  if (d == "M1>" || d == "m1>"   ) {
    moda1 = true;
    moda2 = false;
    moda3 = false;
    moda4 = false;
    moda5 = false;
  }
  else if (d == "M2>" || d == "m2>"  ) {
    moda1 = false;
    moda2 = true;
    moda3 = false;
    moda4 = false;
    moda5 = false;
  }
  else if (d == "M3>" || d == "m3>" ) {
    moda1 = false;
    moda2 = false;
    moda3 = true;
    moda4 = false;
    moda5 = false;
  }
  else if (d == "M4>" || d == "m4>" ) {
    moda1 = false;
    moda2 = false;
    moda3 = false;
    moda4 = true;
    moda5 = false;
  }
  else if (d == "M5>" || d == "m5>" ) {
    moda1 = false;
    moda2 = false;
    moda3 = false;
    moda4 = false;
    moda5 = true;
  }
  //Kondisi misal Basestation ngerem R1 dan kondisi di langkah = 9 maka program masuk ke langkah= 10 Moda1 untuk melakukan gerakan Retry kembali ke home
  if (d == "R12>" || d == "r12>" ) {    // untuk retry, cek lagi posisiny dmn biar biso tau vballik lewat mano
    if (langkah == 1 ) {
      langkah = 2;
    }
  //   ledData(0, 0, 0, 0, 0, 0);
  //   //BUTUH DI RISET LAGI MENYESUAIKAN GERAKAN DI LAPANGAN NANTI
  // }
  //Kondisi misal Basestation ngerem R2 dan kondisi di langkah2 = 9 maka program masuk ke langkah2= 10 Moda2 untuk melakukan gerakan Retry kembali ke home
  // if (d == "R2>" || d == "r2>"  ) {
    if (langkah2 == 1 ) {
      langkah2 = 2;
    }
    // ledData(0, 0, 0, 0, 0, 0);
    //BUTUH DI RISET LAGI MENYESUAIKAN GERAKAN DI LAPANGAN NANTI
  }

  //Kondisi misal Basestation ngerem R3 dan kondisi di langkah3 = 9 maka program masuk ke langkah3= 10 Moda3 untuk melakukan gerakan Retry kembali ke home
  if (d == "R34>" || d == "r34>"  ) {
    if (langkah3 == 1) {
      langkah3 = 2;
    }
  //   ledData(0, 0, 0, 0, 0, 0);
  //   //BUTUH DI RISET LAGI MENYESUAIKAN GERAKAN DI LAPANGAN NANTI
  // }
  // if (d == "R34>" || d == "r34>" ) {
    if (langkah4 == 1) {
      langkah4 = 2;
    }
    // ledData(0, 0, 0, 0, 0, 0);
    //BUTUH DI RISET LAGI MENYESUAIKAN GERAKAN DI LAPANGAN NANTI
  }

 if (d == "R5>" || d == "r5>" ) {
    if (langkah5 == 1 ) {
      langkah5 = 2;
    }
    // ledData(0, 0, 0, 0, 0, 0);
    //BUTUH DI RISET LAGI MENYESUAIKAN GERAKAN DI LAPANGAN NANTI
  }

  // if (d == "MM>" || d == "mm>"   ) {
    if (d == "RR>" || d == "rr>"   ) {
    langkah = 0;
    langkah2 = 0;
    langkah3 = 0;
    langkah4 = 0;
    langkah5 = 0;
  }
 }


