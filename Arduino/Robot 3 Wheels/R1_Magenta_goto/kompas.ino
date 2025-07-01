void kompas2() {
  valor = 0;
  Serial3.write(0x31);
  while (valor == 0) {
    if (Serial3.available()) {
      valorbyte[contador] = Serial3.read();
      contador = (contador + 1) % 8;
      if (contador == 0) {
        heading2 = (valorbyte[2] - 48) * 100 + (valorbyte[3] - 48) * 10 + (valorbyte[4] - 48);
        valor = 1;
        if (logic_gy == 0) {
          gyFix = heading2;
        }
        if (logic_gy == 1) {
          gyFix = gyFix;
        }
        //  cmpsFix = 53;

        sudut2 = (heading2 - 1) - gyFix;
        if (sudut2 < 0) {
          sudut2 = (360 - gyFix) + (gyFix + sudut2);
        }
        sudut2 = map(sudut2, 0, 359, 0, 359);

      }
    }
  }
  //  Serial.println(heading2);
}


//----------Program Buatan Kompas CMP12 -----------
void kompas() {
  Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
  Wire.write(ANGLE_8);                     //Sends the register we wish to start reading from
  Wire.endTransmission();

  Wire.requestFrom(CMPS11_ADDRESS, 3);
    lcd.setCursor(15, 2);
  lcd.print("x");
  while (Wire.available() < 3)
    ;  // Wait for all bytes to come back
  lcd.setCursor(15, 2);
  lcd.print("y");

  while (Wire.available() < 3);       // Wait for all bytes to come back

  angle8 = Wire.read();               // Baca 3 Byte data kompas
  high_byte = Wire.read();
  low_byte = Wire.read();

  angle16 = high_byte;                 // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;
  heading = (angle16 / 10); //+ (angle16 % 10);

    if (logic_cmps == 0) {
      cmpsFix = heading;
    }
    if (logic_cmps == 1) {
      cmpsFix = cmpsFix;
    }
  //  cmpsFix = 53;
  
    sudut = (heading - 1) - cmpsFix;
    if (sudut < 0) {
      sudut = (360 - cmpsFix) + (cmpsFix + sudut);
    }
    sudut = map(sudut, 0, 359, 359, 0);
}
