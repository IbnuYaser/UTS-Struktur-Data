#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Peralatan {
    string kode;
    string nama;
    int jumlah;
    string kondisi;
};

void tambahPeralatan() {
    Peralatan p;
    ofstream file("inventaris.txt", ios::app);
    cout << "Masukkan kode: "; cin >> p.kode;
    cout << "Masukkan nama: "; cin >> p.nama;
    cout << "Masukkan jumlah: "; cin >> p.jumlah;
    cout << "Masukkan kondisi: "; cin >> p.kondisi;
    file << p.kode << " " << p.nama << " " << p.jumlah << " " << p.kondisi << endl;
    file.close();
}

void tampilkanPeralatan() {
    ifstream file("inventaris.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int pilihan;
    do {
        cout << "1. Tambah Peralatan\n2. Tampilkan Peralatan\n0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;
        if (pilihan == 1) tambahPeralatan();
        else if (pilihan == 2) tampilkanPeralatan();
    } while (pilihan != 0);
    return 0;
}
