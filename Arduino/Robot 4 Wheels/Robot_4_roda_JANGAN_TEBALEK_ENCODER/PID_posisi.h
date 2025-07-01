//PAHAMI FUNGSI PID PADA ARDUINO
// (semesin.com/project/2018/03/13/sistem-kontrol-pid-dengan-arduino/)


//----------Program PID kompas -----------
void pid_kompas() {
  error_k = setPoint_k - sudut;
  if (error_k < -180) {           //  Untuk misalnyo di 359 idakdo muter ke 1 (kiri) lagi.. jadi langsung muter ke (0) kanan kalo set point nyo 0.
    error_k = 359 + error_k;
  }
  if (error_k > 180) {
    error_k = -359 + error_k;
  }                               //---------------------------------------------------
  P_k = 3 * error_k;                //Gass Ke set point
  I_k = 0,7 * (error_k + lastError_k); // Ngepaske Setpoint
  D_k = 1 * (error_k - lastError_k); //Rem ke setpoint untuk ngepaske biar idak terlalu ngegas
  lastError_k = error_k;

  pwm_k = P_k + I_k + D_k;   //        // Heading.. PWM kompas, jadi nak ke setpoint dibatesi pwm ny jadi 30. Cari jalan terdekat ke setPoint

  if ((langkah == 1) && (r <= 3) ) {
    pwm_k = constrain (pwm_k, -50, 50);
  }
  else if ((langkah == 1) && (r <= 1) ) {
    pwm_k = constrain (pwm_k, -100, 100);
  }

  else if ((langkah2 == 3) && (r <= 1) ) {
    pwm_k = constrain (pwm_k, -100, 100);
  }
  else if ((langkah3 == 3 ) && (r <= 1) ) {
    pwm_k = constrain (pwm_k, -50, 50);
  }
  else {
    pwm_k = constrain (pwm_k, -30, 30);
    // Heading.. PWM kompas, jadi nak ke setpoint dibatesi pwm ny jadi 30. Cari jalan terdekat ke setPoint
  }
}

//----------Program PID Rotary Encoder nilai Y-----------
void pid_y() {
  error_y = (setPoint_y - Y) * 100; // 100 = ngakali.. jadikan pake satuan Desimeter(DM) , nah kalo error nyo 5 otomatis pwm ny 5 jadi dak ngangkat.. jadi di kalike 100 be
  P_y = 7 * error_y;
  I_y = 1 * (error_y + lastError_y);
  D_y = 3 * (error_y - lastError_y);
  lastError_y = error_y;
  pwm_y = P_y + I_y + D_y;          // -------------------------------------------------------------------------
}


//----------Program PID Rotary Encoder nilai X-----------
void pid_x() {
  error_x = (setPoint_x - X) * 100; // 100 = ngakali.. jadikan pake satuan Desimeter(DM) , nah kalo error nyo 5 otomatis pwm ny 5 jadi dak ngangkat.. jadi di kalike 100 be
  P_x = 7 * error_x;
  I_x = 1 * (error_x + lastError_x);
  D_x = 3 * (error_x - lastError_x);
  lastError_x = error_x;
  pwm_x = P_x + I_x + D_x;          // -------------------------------------------------------------------------
}
