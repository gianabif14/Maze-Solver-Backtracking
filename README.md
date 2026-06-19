# 🧩 Maze Solver with Backtracking Algorithm

## 📋 Deskripsi
Program C++ ini mengimplementasikan algoritma *Backtracking Rekursif* untuk menyelesaikan labirin (maze). Program akan mencari jalur dari titik awal (0,0) menuju titik finish yang ditandai dengan nilai 2 pada matriks labirin.

## 🎯 Fitur Utama
- ✅ Pencarian jalur menggunakan algoritma Backtracking
- ✅ Visualisasi labirin dalam bentuk matriks 2D
- ✅ Penandaan jalur solusi dengan simbol *
- ✅ Deteksi jika tidak ada solusi
- ✅ Ukuran labirin fleksibel (dapat diubah)

## 🏗️ Struktur Labirin
Labirin direpresentasikan dalam matriks 6x6 dengan ketentuan:
- 0 = Jalur kosong (bisa dilewati)
- 1 = Dinding/Tembok (tidak bisa dilewati)
- 2 = Titik Finish (target)
- 9 = Jalur yang sedang dikunjungi (untuk tracking)
