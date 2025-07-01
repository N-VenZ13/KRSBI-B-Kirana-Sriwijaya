// Fungsi navigasi utama untuk bergerak menuju koordinat target (X, Y) sambil mempertahankan arah heading (kompas)
// - sudut_hadap     : sudut tujuan yang harus dihadapi robot (dalam derajat, 0–359)
// - xxx, yyy        : koordinat tujuan robot
// - speed           : kecepatan maksimum gerakan
// - toleransiJarak  : jarak maksimum dianggap sudah sampai ke target (default = 1.5 satuan)
// - toleransiSudut  : selisih heading maksimum dianggap sudah menghadap benar (default = 10 derajat)

void core_go_to(int sudut_hadap, int xxx, int yyy, int speed, float toleransiJarak = 1.5, int toleransiSudut = 10) {
  
  // PID posisi (untuk perhitungan pwm_x, pwm_y)
  pid_x();                  
  pid_y();
  
  // PID heading (untuk heading/kompas)
  pid_kompas();             

  // Set target tujuan
  setPoint_x = xxx;
  setPoint_y = yyy;
  setPoint_k = sudut_hadap;

  // Hitung selisih posisi
  float error_x = xxx - X;
  float error_y = yyy - Y;

  // Hitung jarak total ke target (r) menggunakan pythagoras
  float r = sqrt(error_x * error_x + error_y * error_y);

  // Hitung sudut arah gerakan yang harus dituju
  float arahGerak = atan2(error_x, error_y) * 180 / PI;

  // Normalisasi sudut agar dalam range 0-359
  if (arahGerak < 0) arahGerak += 360;

  // Koreksi terhadap orientasi robot (karena sudut 0 robot bisa beda arah)
  arahGerak = 360 - arahGerak;

  // Hitung besar pwm gabungan untuk gerak translasi
  int pwm = fabs(pwm_x + pwm_y);  // ambil nilai absolut gabungan PID X dan Y

  // Kurangi kecepatan saat dekat target
  if (r < 10) {
    pwm = map(r, 0, 10, 20, speed);  // kecepatan diperkecil saat mendekati titik
  }

  // Batasi pwm maksimum agar tidak melebihi speed
  pwm = constrain(pwm, 0, speed);

  // Hitung error heading saat ini
  int errorSudut = sudut_hadap - sudut;
  if (errorSudut > 180) errorSudut -= 360;
  if (errorSudut < -180) errorSudut += 360;

  // Kirim gerakan ke omniwheel jika pwm cukup besar
  if (pwm >= 5) {
    omni1(arahGerak, pwm_k, pwm);
  } else {
    motor(0, 0, 0);  // diamkan jika terlalu kecil, biar tidak getar
  }

  // Deteksi jika robot sudah berada di target (jarak dan heading sesuai toleransi)
  if (fabs(errorSudut) <= toleransiSudut && r <= toleransiJarak) {
    if (!nyampe) {
      Serial.println("TARGET TERCAPAI");
    }
    nyampe = true;
  } else {
    nyampe = false;
  }

  // Tambahan: flag nyampe1 bisa digunakan jika kamu butuh logika berbeda
  if (r <= toleransiJarak) {
    nyampe1 = true;
  } else {
    nyampe1 = false;
  }
}
