# 📘 Petunjuk & Panduan Penggunaan Program Robot 3 Roda Magenta

> **⚠️ Harap dibaca dengan saksama sebelum melakukan pengujian atau modifikasi!**  
> Disusun oleh **Noven (2025)**

---

## 📦 Daftar Isi

1. [Pendahuluan](#pendahuluan)  
2. [Setup dan Konfigurasi Hardware](#setup-dan-konfigurasi-hardware)  
3. [Konfigurasi Pin Arduino](#konfigurasi-pin-arduino)  
4. [Panduan Pengujian Komponen Robot](#panduan-pengujian-komponen-robot)  
   - [Tes Dribble](#tes-dribble)  
   - [Tes Motor](#tes-motor)  
   - [Tes Omni](#tes-omni)  
   - [Tes Kompas & Encoder](#tes-kompas--encoder)  
   - [Tes Sensor Sharp GP](#tes-sensor-sharp-gp)  
5. [Keselamatan dan Perhatian](#keselamatan-dan-perhatian)

---

## 📍 Pendahuluan

Dokumentasi ini dibuat sebagai panduan penggunaan dan pengujian program robot berkaki tiga dengan sistem omniwheel. Diperuntukkan bagi anggota tim baru atau pengguna pemula yang ingin memahami alur kerja dasar dari robot ini.

---

## ⚙️ Setup dan Konfigurasi Hardware

### 🔌 Wiring

- Pastikan **semua socket dan pin terpasang dengan benar** sesuai dengan layout pada PCB/shield robot.
- **Jangan sampai ada pin yang tertukar atau longgar.**
- Cek ulang koneksi sebelum menyalakan sistem.
- Gunakan baterai dengan tegangan **22V - 23.7V**.
- Jika menggunakan **kamera**, pastikan sudah terhubung ke laptop atau mini-PC.

---

## 🧩 Konfigurasi Pin Arduino

Berikut adalah konfigurasi pin Arduino yang digunakan pada robot:

```cpp
// === ENCODER ===
#define enA 16  // Encoder X
#define enB 18
#define enC 17  // Encoder Y
#define enD 19

// === MOTOR DRIBBLE ===
#define motordribble1 4
#define motordribble2 5

// (Legacy Pins - Tidak digunakan, tapi masih aktif)
#define motordribblekanan1 2
#define motordribblekanan2 3

// === SOLENOID KICKER ===
#define Selenoid 12
bool sudahOperON = false;

// === MOTOR PG45 ===
#define pin_MOTOR_DIRL 10
#define pin_MOTOR_PWML 11
#define pin_MOTOR_DIRR 8
#define pin_MOTOR_PWMR 9
#define pin_MOTOR_DIRB 6
#define pin_MOTOR_PWMB 7

// === SENSOR SHARP GP ===
#define sharpGP A1  // Depan
#define bkn A0      // Kanan
#define bkr A2      // Kiri
```

---

## 🧪 Panduan Pengujian Komponen Robot

### ✅ Tes Dribble

```cpp
// Aktifkan fungsi berikut di void loop:
dribble_on1();
dribble_on2();
```

Dribble akan menyala. Jika arah putaran terbalik, **cek kembali polaritas pin motor** dan **tukar pin** jika perlu.

---

### ✅ Tes Motor

```cpp
// Aktifkan fungsi berikut di void loop:
motor(50, 50, 50);    // Maju atau kanan
delay(2000);
motor(-50, -50, -50); // Mundur atau kiri
delay(2000);
```

Perhatikan arah gerakan robot. Jika tidak sesuai, **lakukan pengecekan ulang pada wiring pin motor.**

---

### ✅ Tes Omni

```cpp
// Aktifkan fungsi berikut di void loop:
omni(0, 0, 100);    // Maju
delay(2000);
omni(180, 0, 100);  // Mundur
delay(2000);
omni(90, 0, 100);   // Kiri
delay(2000);
omni(270, 0, 100);  // Kanan
delay(2000);
```

Robot seharusnya bergerak sesuai arah yang ditentukan. Jika tidak, kemungkinan pin salah atau polaritas salah.

---

### ✅ Tes Kompas & Encoder

```cpp
// Aktifkan fungsi berikut di void loop:
kompas();
logic_cmps = 1;
UpdatePosisi();
Serial.print("S = ");
Serial.print(sudut);
Serial.print(" || X = ");
Serial.print(X);
Serial.print(" || Y = ");
Serial.println(Y);
delay(50);
```

Lakukan:

- Putar robot → nilai **sudut (S)** harus berubah.  
- Dorong robot ke depan → nilai **Y** berubah.  
- Dorong ke samping → nilai **X** berubah.

**Pastikan nilai X dan Y tidak saling bertabrakan**.

> 🟡 Encoder hanya berfungsi optimal jika **tegangan baterai ≥ 22V**.

---

### ✅ Tes Sensor Sharp GP

```cpp
// Aktifkan fungsi berikut di void loop:
Serial.print("S = ");
Serial.println(sgp);
Serial.print("|| BKI = ");
Serial.print(bahukiri);
Serial.print(" || BKN = ");
Serial.println(bahukanan);
delay(50);
```

Contoh logika deteksi bola:
```cpp
void sharpgp() {
  if (sgp > 500 && sgp < 700) {
    dapetBola = true;
  } else {
    dapetBola = false;
  }
}
```

- Nilai 500–700 menunjukkan bola berada dalam jangkauan.
- Lakukan tes dengan bola di depan robot & dribble aktif.
- Jangan terlalu sempit atau lebar dalam menentukan range.

---

## ⚠️ Keselamatan dan Perhatian

> **‼️ WAJIB DIPERHATIKAN‼️**

- Lakukan **tes satu per satu**, jangan memanggil banyak fungsi sekaligus.
- Hindari menyalakan **solenoid** sembarangan—bisa berbahaya.
- Jangan sembarangan mengubah kode. **Konsultasikan dengan senior** jika ingin mengubah logika program.
- Selalu periksa tegangan dan **pastikan polaritas benar** saat memberi power.
- Jangan ragu untuk bertanya pada senior jika ada yang tidak dimengerti.
- **Keselamatan dan peralatan adalah prioritas utama.**

---

## 👨‍🏫 Catatan Penutup

Dokumentasi ini akan terus diperbarui seiring perkembangan dan perbaikan robot.  
Silakan kontribusi dan diskusikan jika ada hal baru yang perlu ditambahkan.  
**Semangat, dan jaga performa robot kita! 🤖**
