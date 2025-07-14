// //----------Program MODA1 Kondisi gerakan moda 1 dalam pertandingan -----------//
void Moda2 () {
 
  pid_kompas();
  sharpgp();
  bkirifix();
  bkananfix();
  UpdatePosisi();   // fungsi ini wajib dipanggil
  // komunikasi();  //ini di aktifkan jika komunikasi basestation 
  kompas();
  dribble_on1();
  dribble_on2();
  logic_cmps = 1;   //ini diperlukan untuk mengaktifkan cmps(lihat difungsi kompas)

  switch (langkah) {   
    case 0:
      // Serial.println("Langkah 0: Reset posisi");

      X = 0;
      Y = 0;
      motor(0, 0, 0);
      nyampe = false;
      // if(d == "S1>" || d == "s1>" || !ok){     //ini logic untuk nerima data di basestation
      langkah += 1;  // langsung lanjut ke langkah berikutnya
      // }
      break;  
    
    case 1:
      Serial.println("Langkah 1: robot kekanan");
      int kec = 50;
      go_to(0, 5, 0, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  // delay singkat untuk memastikan berhenti
        nyampe = false;  // reset untuk langkah selanjutnya
        langkah += 1;
      }
      break;

    case 2:
      Serial.println("Langkah 2: robot kedepan");
      kec = 50;
      go_to(0, X, 7, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  // delay singkat untuk memastikan berhenti
        nyampe = false;  // reset untuk langkah selanjutnya
        langkah += 1;
      }
      break;
    
    case 3:
      Serial.println("Langkah 3: robot kejar bola dan mengoper");
      kejar_bola_omni_depan();  //fungsi kamera untuk mengejar bola
      if(dapetBola == true && sudahOperON == false){
          dribble_off();
          delay(500);
          operanON();
          delay(1000);
          sudahOperON = true;
          nyampe = false;
          langkah += 1;
        }
        sudahOperON = false;
      break;
    
    case 4:
      Serial.println("Langkah 4: robot geser kesamping");
      kec = 50;
      go_to(0, 2, Y, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;
    
    case 5:
      Serial.println("Langkah 5: robot menangkap bola dari Robot");
      
      tangkapBolaOmni(0);
      if (dapetBola == true){
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;
    
    case 6:
      Serial.println("Langkah 6: robot geser kesamping");
      kec = 50;
      go_to(0, -1, Y, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

    case 7:
      Serial.println("Langkah 7: robot mengoper bola");
      
      if(dapetBola == true && sudahOperON == false){
          dribble_off();
          delay(500);
          operanON();
          delay(1000);
          sudahOperON = true;
          nyampe = false;
          langkah += 1;
        }
        sudahOperON = false;
      break;

    case 8:
      Serial.println("Langkah 8: robot geser kesamping");
      kec = 50;
      go_to(0, 2, Y, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

    case 9:
      Serial.println("Langkah 9: robot menangkap bola dari Robot");
      
      tangkapBolaOmni(0);
      if (dapetBola == true){
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

    case 10:
      Serial.println("Langkah 10: robot geser kearah gawang");
      kec = 50;
      go_to(35, 3, Y, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

    case 11:
      Serial.println("Langkah 11: robot menendang bola");
      
      if(dapetBola == true && sudahOperON == false){
          dribble_off();
          delay(500);
          // kickON();
          operanON();
          delay(1000);
          sudahOperON = true;
          nyampe = false;
          langkah += 1;
        }
        sudahOperON = false;
      break;

    case 12:
      Serial.println("Langkah 12: robot balik kebase");
      kec = 50;
      go_to(35, X, 0, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

    case 13:
      Serial.println("Langkah 13: robot balik kebase");
      kec = 50;
      go_to(35, 0, Y, kec);
      // if (r > 5){
      //   kec /= 2;
      // } else if (r < 5){
      //   kec /= 4;
      // }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        langkah += 1;
      }
      break;

//  perlu riset komunikasi variabel ketemu masih bingung cak mno logika agar robot nahan dan stay at home dan dia pindah ke langkah
    case 14:
      Serial.println("Langkah 14: robot stayyy");
      
      motor(0, 0, 0);
    
      break;

    case 15:
      Serial.println("Langkah 15: kondisi robot retry");
      
      kec = 50;
      go_to(0, 0, 0, kec);
      if (r > 5){
        kec /= 2;
      } else if (r < 5){
        kec /= 4;
      }
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  
        nyampe = false;  
        
      }
      break;
    
    
  }
}



