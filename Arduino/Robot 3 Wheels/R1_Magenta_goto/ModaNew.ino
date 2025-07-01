// Dokumentasi riset noven 16 juni 2025 - sampai sekarang
// saya merubah sistem moda dengan logika switch case
// karena saya rasa logika switch case lebih bagus peformanya dari pada logika sebelumnnya
// moda sudah bisa di akses lagi per 18 juni 2025
// fungsi fungsi comvision(kamera) sudah bisa di akses lagi per 19 juni 2025

void ModaNew(){

  pid_kompas();
  sharpgp();
  bkirifix();
  bkananfix();
  UpdatePosisi();
  // baca_kamera();
  // kejar_bola();
  // komunikasi();  //INI DI EDOPKE MEN NAK MODE KOMUNIKASI
  kompas();
  logic_cmps = 1;

  Serial.println("moda masuk siap");
  // delay(5000);
  dribble_on1();
  dribble_on2();

  Serial.print("LANGKAH SEKARANG: ");
  Serial.println(langkah);
  // Serial.print("X: "); Serial.print(X);
  // Serial.print(" Y: "); Serial.print(Y);
  // Serial.print(" Heading: "); Serial.println(heading);

 


   switch (langkah) {
    case 0:
      Serial.println("Langkah 0: Reset posisi");

      X = 0;
      Y = 0;
      motor(0, 0, 0);
      nyampe = false;
      langkah += 1;  // langsung lanjut ke langkah berikutnya
  //     Serial.print("LANGKAH SEKARANG: ");
  // Serial.println(langkah);
      break;

    case 1:
      Serial.println("Langkah 1: Menuju titik (0,10)");
      go_to(0, 0, 3, 50);
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);  // delay singkat untuk memastikan berhenti
        nyampe = false;  // reset untuk langkah selanjutnya
        langkah += 1;
  //       Serial.print("LANGKAH SEKARANG: ");
  // Serial.println(langkah);
      }
      break;

    case 2:
      Serial.println("Langkah 2: Menuju titik (0,0)");
      go_to(0, 5, Y, 50);
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);
        nyampe = false;
        langkah += 1;
      }
      break;

    case 3:
      Serial.println("menendang");
      // go_to(0, X, Y, 50);
      kejar_bola_omni_depan();
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);
        // logika disini 
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
        // nyampe = false;
        // langkah += 1;
      }
      break;

    
    case 4:
      Serial.println("Langkah5");
      go_to(0, 0, Y, 50);
      if (nyampe){
        motor(0, 0, 0);
        delay(300);
        nyampe = false;
        langkah += 1;
      }
      break;
    
    
    
    case 5:
      Serial.println("Langkah nerima bola");
      // tangkapBola(0);
      UpdatePosisi();
      // tangkapBolaOmniDekat(0);
      if (dapetBola == true) {
        omni1 (0, pwm_k, 0);
        delay(500);
        
        motor(0, 0, 0);
        nyampe = false;
        langkah += 1;
      }
      break;

    case 6:
      Serial.println("Langkah5");
      go_to(40, X, Y, 50);
      if (nyampe){
        motor(0, 0, 0);
        delay(300);
        nyampe = false;
        langkah += 1;
      }
      break;
    
    case 7:
      Serial.println("menendang");
      go_to(40, X, Y, 50);
      if (nyampe) {
        motor(0, 0, 0);
        delay(300);
        // logika disini 
        if(dapetBola == true && sudahOperON == false){
          dribble_off();
          delay(500);
          operanON();
          delay(1000);
          sudahOperON = true;
          nyampe = false;
          langkah += 1;
        }
        // nyampe = false;
        // langkah += 1;
      }
      break;


    case 8:
      Serial.println("Selesai");
      motor(0, 0, 0);
      delay(100000);
      break;
  }

  // delay(1000);
  delay(300);


}