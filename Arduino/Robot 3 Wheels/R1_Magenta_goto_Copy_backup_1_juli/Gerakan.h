//PROGRAM MOTOR PG45
void motor(int L, int R, int B) {
  if (L > 0) {
    analogWrite(pin_MOTOR_DIRL, 0);
    analogWrite(pin_MOTOR_PWML, L);
  } else {
    L = L * (-1);
    analogWrite(pin_MOTOR_DIRL, L);
    analogWrite(pin_MOTOR_PWML, 0);
  }
  //======================================
  if (R > 0) {
    analogWrite(pin_MOTOR_DIRR, 0);
    analogWrite(pin_MOTOR_PWMR, R);
  } else {
    R = R * (-1);
    analogWrite(pin_MOTOR_DIRR, R);
    analogWrite(pin_MOTOR_PWMR, 0);
  }
  //=======================================
  if (B > 0) {
    analogWrite(pin_MOTOR_DIRB, 0);
    analogWrite(pin_MOTOR_PWMB, B);
  } else {
    B = B * (-1);
    analogWrite(pin_MOTOR_DIRB, B);
    analogWrite(pin_MOTOR_PWMB, 0);
  }
}

//----------Program Motor PG45 Gerakan Omni -----------
//fungsi omni bisa di jadikan gerak utama kalau sudah menggunakan kamera jadi tidak perlu encoder lagi
// degree= arah nilainya 0-360 derajat, kec= speed pwm 0-255
void omni(float degree, float heading, int kec) {
  float v0, v1, v2, v, vn;
  v = cos (degree * PI / 180);
  vn = sin(degree * PI / 180);
  v0 = (-sin(PI / 3) * v + cos(PI / 3) * vn) * kec;
  v1 = (-vn) * kec + heading;
  v2 = (sin(PI / 3) * v + cos(PI / 3) * vn) * kec;
  motor(v0, v2, v1);
}

void omni1(float degree, float heading, int kec) {
  float v0, v1, v2, v, vn;
  v = cos (degree * PI / 180);
  vn = sin(degree * PI / 180);
  v0 = (-sin(PI / 3) * v + cos(PI / 3) * vn) * kec + heading;
  v1 = (-vn) * kec + heading;
  v2 = (sin(PI / 3) * v + cos(PI / 3) * vn) * kec + heading;
   v0 = constrain (v0, -255, 255);
   v1 = constrain (v1, -255, 255);
   v2 = constrain (v2, -255, 255);
  motor(v0, v2, v1);
  //L R B
}

// degree= arah nilainya 0-360 derajat, kec= speed pwm 0-255
void omni2(float degree, float heading, int kec) {
  float v0, v1, v2, v, vn, v2r, v0r;
  v = cos (degree * PI / 180);
  vn = sin(degree * PI / 180);
  v0 = (-sin(PI / 3) * v + cos(PI / 3) * vn) * kec;   // Motor L (-)
  v2 = (sin(PI / 3) * v + cos(PI / 3) * vn) * kec;    // Motor R (+)
  v1 = (-vn) * kec + heading;   //  Motor B
  // sebelah kiri + sebelah kanan -
  if (error < -200) {
    v2r = v2 - (kec / 3);
    motor(v0, v2r, v1);
  }
  else if (error > 200) {
    v0r = v0 + (kec / 3);
    motor(v0r, v2, v1);
  }
  else {
    motor(v0, v2, v1);
  }
  //  lcd.setCursor(0, 0); lcd.print("v0="); lcd.setCursor(3, 0); lcd.print(v0); lcd.print("");
  //  lcd.setCursor(11, 0); lcd.print("v0r="); lcd.setCursor(15, 0); lcd.print(v0r); lcd.print("  ");
  //  lcd.setCursor(0, 1); lcd.print("v2="); lcd.setCursor(3, 1); lcd.print(v2); lcd.print("");
  //  lcd.setCursor(11, 1); lcd.print("v2r="); lcd.setCursor(15, 1); lcd.print(v2r); lcd.print("  ");
  //  lcd.setCursor(0, 2); lcd.print("v1= "); lcd.setCursor(4, 2); lcd.print(v1); lcd.print("  ");
  //  lcd.setCursor(0, 3); lcd.print("Error = "); lcd.setCursor(8, 3); lcd.print(error); lcd.print("  ");
}

//PROGRAM DRIBEL BOLA
void dribble_on1() {
  analogWrite(motordribble1, 0);  
  analogWrite(motordribble2, 220);      
}

void dribble_on2() {
  analogWrite(motordribblekanan1, 0);    //yang ini harus 0, karna men idak 0 dribblenyo muter tebalek
  analogWrite(motordribblekanan2, 220);
}

void dribble_off() {
  analogWrite(motordribblekanan1, 0);
  analogWrite(motordribblekanan2, 0);
  analogWrite(motordribble1, 0);
  analogWrite(motordribble2, 0);
}

//void penendang(int n) {
//  dribble_off();
//  dribble_o2ff();
//  analogWrite(motorpenendang1, 0);
//  analogWrite(motorpenendang2, n);
//  delay(500);
//  analogWrite(motorpenendang1, 50);
//  analogWrite(motorpenendang2, 0);
//  delay(200);
//  analogWrite(motorpenendang1, 0);
//  analogWrite(motorpenendang2, 0);
//}

//----------Program Penendang memberi sinyal ke arduino nano untuk tendang -----------
void kickON() {       //Tendang Kuat
  digitalWrite(Selenoid, HIGH);    
  delay(20);
  digitalWrite(Selenoid, LOW);
}

void operON() {       //Tendang Operan`
  digitalWrite(Selenoid, HIGH);
  delay(11);
  digitalWrite(Selenoid, LOW);
}

void ngoperON() {       //Tendang Operan`
  digitalWrite(Selenoid, HIGH);
  delay(15);
  digitalWrite(Selenoid, LOW);
}

void operanON() {       //Tendang Operan
  Serial.println("fix goll");
  digitalWrite(Selenoid, HIGH);
  delay(8);
  digitalWrite(Selenoid, LOW);
}

void siuuON() {       //Tendang Kuat
  digitalWrite(Selenoid, HIGH);    
  delay(50);
  digitalWrite(Selenoid, LOW);
}

void kickOFF() {
  delay(1000);
}

void operOFF() {
  delay(1000);
}

// ==kodingan sebelumnyo untuk deklarasi kick sm oper pakek motor pg45==
// //Tendang Kuat
// void kickON() {
//   digitalWrite(Gkick, HIGH);
//   digitalWrite(oper, LOW);
// }

// void kickOFF() {
//   digitalWrite(Gkick, LOW);
//   digitalWrite(oper, LOW);
// }

// //Tendang Operan
// void operON() {
//   digitalWrite(oper, HIGH);
//   digitalWrite(Gkick, LOW);
// }

// void operOFF() {
//   digitalWrite(oper, LOW);
//   digitalWrite(Gkick, LOW);
// }

//PROGRAM Rotary ENCODER
void leftEncoderEventx() {
  if (digitalRead(enC) == digitalRead(enD))
  {
    leftCountx--;
  }
  else
  {
    leftCountx++;
  }
}

void leftEncoderEventy() {
  if (digitalRead(enA) == digitalRead(enB))
  {
    leftCounty--;
  }
  else {
    leftCounty++;
  }
}
