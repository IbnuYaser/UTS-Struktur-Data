#include <iostream>
#include <queue>
using namespace std;

struct Pelanggan {
    int nomor;
    int waktuLayanan;
};

int main() {
    queue<Pelanggan> antrian;
    int totalWaktu = 0, jumlahPelanggan = 0;

    // Menambah beberapa pelanggan ke antrian
    for (int i = 1; i <= 5; i++) {
        antrian.push({i, 5});
    }

    while (!antrian.empty()) {
        Pelanggan p = antrian.front();
        antrian.pop();
        cout << "Melayani pelanggan " << p.nomor << " selama " 
             << p.waktuLayanan << " menit.\n";
        totalWaktu += p.waktuLayanan;
        jumlahPelanggan++;
    }

    cout << "Total waktu layanan: " << totalWaktu << " menit\n";
    cout << "Jumlah pelanggan terlayani: " << jumlahPelanggan << endl;
    return 0;
}
