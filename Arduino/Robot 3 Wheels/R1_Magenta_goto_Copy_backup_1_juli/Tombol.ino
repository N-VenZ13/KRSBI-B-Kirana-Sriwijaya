//----------Program Buatan Tombol -----------

void homescreen() {

  //PAHAMI FUNGSI WHILE
  //(https://learningoftechnology.blogspot.com/2019/11/program-dasar-arduino-2-perulangan.html)

  while (1) {

    //----------Program Kondisi Tombol -----------

    //Program Misalkan Ditekan Tombol ok(biru) maka program masuk ke mode program komunikasi
    if (!ok) {

      //======== Mode Komunikasi =========//

      //komunikasi();

      //=================================//

      //======== Mode Tombol Moda 1 =========//
           X = 0;
           Y = 0;
           langkah = 1;
      break;
           homescreen();
      //====================================//

    }
    //Program Misalkan Ditekan Tombol back(merah) maka program masuk ke mode Program tombol
    if (!back) {
      homescreen();
    }

    //Program Misalkan Ditekan Tombol UpR(Atas Kanan) maka program masuk ke mode Program Dribel
    else if (!upR) {
     dribble_on1();
     dribble_on2();
            // kickON();
//           operON();
                      //  omni(50, 50, 0); // program maju
    }

    //Program Misalkan Ditekan Tombol UpL(Atas Kiri) maka program masuk ke mode Program penendang kick atau oper
    else if (!upL) {
//      kickON();
motor(50, 50, 50);
//      omni(180, 0, 50); // program mundur
//  omni(0, 0, 50); // program maju
//      operON();
    }

    //Program Misalkan Ditekan Tombol downL(Bawah Kiri) maka program masuk ke mode Program Motor PG45 atau omni
    else if (!downL) {
          //  operON();
      //      motor(50, 50, 50);  
                 omni(180, 0, 50); // Program mundur
      // omni(90, 0, 50); // Program Kiri
    }

    //Program Misalkan Ditekan Tombol downR(Bawah Kanan) maka program masuk ke mode Program Motor PG45 atau omni kebalikan arahnya
    else if (!downR) {
      //  dribble_on1();
      // dribble_on2();
           motor(-50, -50, -50);
      //            omni(0, 0, 50); // Program Mundur
                        // omni(270, 0, 50); // Program Kanan
    }

    //Program Kondisi di mana semua kondisi if tidak terpenuhi maka masuk ke kondisi else
    else {
      motor(0, 0, 0);
      dribble_off();
      kickOFF();
     operOFF();
    }
  }
}
