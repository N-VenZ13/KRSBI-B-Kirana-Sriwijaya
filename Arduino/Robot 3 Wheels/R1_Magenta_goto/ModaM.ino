//----------Program MODA M digunakan untuk ngetes mengetes -----------//
void ModaM() {
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

  // if (langkahM == 0) {             //Robot Stay Home
  //   //    ledData(1, 0 , 0, 0, 0, 0);
  //   X = 0;
  //   Y = 0;
  //   logic_cmps = 0;
  //   motor(0, 0, 0);
  //   siap = false;
  //   langkahM = 1;
  //   }
  
  //================================== Mode Mengetes Bejalan makai kodingan lamo===============================================//

  // if (langkahM == 1) {           //Robot Gerak ke Center
  //   logic_cmps = 1;
  //   int kec = 150;
  //   if (r <= 3) kec /= 4;
  //   go_to (0, 10, 0, kec);
  //   if (nyampe == true) {
  //     motor(0, 0, 0);
  //     langkahM  += 1 ;
  //   }
  // }

  // if (langkahM == 2) {           //Robot Gerak maju ke Center
  //   int kec = 150;
  //   if (r <= 5) kec /= 4;
  //   go_to (0, 10, 8, kec);
  //   if (nyampe == true) {
  //     motor(0, 0, 0);
  //     langkahM  += 1 ;
  //   }
  // }

  // if (langkahM == 3) {           //Robot Gerak maju ke Center
  //   int kec = 170;
  //   if (r <= 3) kec /= 4;
  //   go_to (180, 10, 8, kec);
  //   if (nyampe == true) {
  //     motor(0, 0, 0);
  //     langkahM  = 0 ;
  //   }
  // }  
  //================================== Mode Mengetes Tendangan Maut===============================================//

  // if (langkahM == 1) {
  //   if (dapetBola == true) {
  //     delay(1000);
  //     langkahM += 1;
  //   }
  // }

  // if (langkahM == 2) {
  //   dribble_off();
  //   langkahM += 1;
  // }

  // if (langkahM == 3) {
  //     delay(1000);
  //     operON();        //pilih salah satu aja ya shay
  //     kickON();        //kalo idup 2 2 nyo gek kaget
  //     delay(500);
  //     langkahM = 0;
  //   }

//   else {
//     operOFF();
//     kickOFF();
//   }
}
