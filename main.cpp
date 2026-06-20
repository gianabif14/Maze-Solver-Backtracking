#include <iostream>
using namespace std;

// Mendefinisikan ukuran labirin
const int BARIS = 6;
const int KOLOM = 6;

// Representasi Labirin (Matriks 2D):
// 0 = Jalur kosong (bisa dilewati)
// 1 = Dinding/Tembok (tidak bisa dilewati)
// 2 = Titik Finish (Target)
// 9 = Jalur yang sedang aktif dikunjungi
int labirin[BARIS][KOLOM] = {
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 2, 1} // Petak [5][4] bernilai 2 adalah FINISH
};

// Fungsi untuk mengoutputkan kondisi labirin ke layar
void cetakLabirin() {
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (labirin[i][j] == 9) {
                cout << "* "; // Menampilkan jalur sukses dengan tanda bintang
            } else {
                cout << labirin[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

// Fungsi utama Rekursif Backtracking untuk menyelesaikan labirin
bool solveMaze(int x, int y) {
    
    // 1. Validasi Batasan (Constraint): Apakah koordinat keluar dari bingkai labirin?
    if (x < 0 || x >= BARIS || y < 0 || y >= KOLOM) {
        return false; 
    }

    // 2. Jika mencapai titik FINISH (Nilai 2), pencarian sukses!
    if (labirin[x][y] == 2) {
        return true; 
    }

    // 3. Validasi Batasan: Menabrak dinding (1) atau sudah pernah dikunjungi (9)
    if (labirin[x][y] == 1 || labirin[x][y] == 9) {
        return false; 
    }

    // Tandai petak saat ini sebagai jalur yang sedang dikunjungi (Nilai 9)
    labirin[x][y] = 9;
    
    // Tampilkan visualisasi setiap kali melangkah maju
    cout << "Melangkah ke koordinat (" << x << ", " << y << "):\n";
    cetakLabirin();

    // 4. Rekursi: Coba bergerak ke 4 arah dengan urutan prioritas: Kanan -> Bawah -> Kiri -> Atas
    
    // Coba Kanan (Kolom bertambah 1)
    if (solveMaze(x, y + 1)) return true;

    // Coba Bawah (Baris bertambah 1)
    if (solveMaze(x + 1, y)) return true;

    // Coba Kiri (Kolom berkurang 1)
    if (solveMaze(x, y - 1)) return true;

    // Coba Atas (Baris berkurang 1)
    if (solveMaze(x - 1, y)) return true;

    // 5. MEKANISME BACKTRACK: Jika ke-4 arah di atas buntu (semua mengembalikan false),
    // bersihkan kembali nilai petak ini menjadi 0, lalu mundur (return false)
    labirin[x][y] = 0; 
    
    // Tampilkan visualisasi ketika jalan buntu dan melakukan runut balik (backtrack)
    cout << "BUNTU! Mundur (Backtrack) dari koordinat (" << x << ", " << y << "):\n";
    cetakLabirin();
    
    return false;
}

int main() {
    cout << "=== LABIRIN AWAL ===\n";
    cetakLabirin();

    // Memulai pencarian dari titik Start di koordinat (0, 0)
    if (solveMaze(0, 0)) {
        cout << "\n=== JALUR SOLUSI DITEMUKAN ===\n";
        cout << "Tanda (*) melambangkan rute menuju finish:\n\n";
        cetakLabirin();
    } else {
        cout << "\nJalur keluar tidak ditemukan/tidak ada solusi.\n";
    }

    return 0;
}
