#include <iostream>

using namespace std;

// Fungsi untuk menampilkan papan tic-tac-toe
void tampilkanPapan(char papan[3][3]) {
cout << "-------------" << endl;
for (int i = 0; i < 3; i++) {
    cout << "| ";
    for (int j = 0; j < 3; j++) {
    cout << papan[i][j] << " | ";
    }
    cout << endl << "-------------" << endl;
}
}

// Fungsi untuk memeriksa apakah ada pemenang
char periksaPemenang(char papan[3][3]) {
  // Periksa baris
for (int i = 0; i < 3; i++) {
    if (papan[i][0] != ' ' && papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) {
    return papan[i][0];
    }
}

  // Periksa kolom
for (int j = 0; j < 3; j++) {
    if (papan[0][j] != ' ' && papan[0][j] == papan[1][j] && papan[1][j] == papan[2][j]) {
    return papan[0][j];
    }
}

  // Periksa diagonal
if (papan[0][0] != ' ' && papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) {
    return papan[0][0];
}
if (papan[0][2] != ' ' && papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) {
    return papan[0][2];
}

  // Tidak ada pemenang
return ' ';
}

// Fungsi untuk memeriksa apakah papan sudah penuh
bool papanPenuh(char papan[3][3]) {
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    if (papan[i][j] == ' ') {
        return false;
    }
    }
}
return true;
}

int main() {
char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char pemainSaatIni = 'X';
bool permainanBerakhir = false;

while (!permainanBerakhir) {
    tampilkanPapan(papan);

    // Dapatkan input pemain
    int baris, kolom;
    cout << "Giliran pemain " << pemainSaatIni << ". Masukkan baris dan kolom (1-3): ";
    cin >> baris >> kolom;

    // Validasi input
    if (baris < 1 || baris > 3 || kolom < 1 || kolom > 3 || papan[baris - 1][kolom - 1] != ' ') {
    cout << "Input tidak valid. Silakan coba lagi." << endl;
    continue;
    }

    // Tempatkan tanda pemain di papan
    papan[baris - 1][kolom - 1] = pemainSaatIni;

    // Periksa pemenang atau seri
    if (periksaPemenang(papan) != ' ') {
    tampilkanPapan(papan);
    cout << "Pemain " << periksaPemenang(papan) << " menang!" << endl;
    permainanBerakhir = true;
    } else if (papanPenuh(papan)) {
    tampilkanPapan(papan);
    cout << "Permainan seri!" << endl;
    permainanBerakhir = true;
    } else {
      // Ganti giliran pemain
    pemainSaatIni = (pemainSaatIni == 'X') ? 'O' : 'X';
    }
}

return 0;
}
