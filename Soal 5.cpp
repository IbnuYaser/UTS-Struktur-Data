#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// Struct untuk Buku
struct Buku {
    string ISBN;
    string judul;
    string pengarang;
    int tahunTerbit;
};

// Struct untuk Pelanggan
struct Pelanggan {
    string nama;
    string ISBNBuku;
};

// Deklarasi Array of Pointers untuk Buku
Buku* koleksiBuku[10];
int jumlahBuku = 0;

// Stack untuk Riwayat Peminjaman Buku
stack<string> riwayatPeminjaman;

// Queue untuk Antrian Peminjaman Buku
queue<Pelanggan> antrianPeminjaman;

// Fungsi Menambah Buku
void tambahBuku() {
    if (jumlahBuku < 10) {
        koleksiBuku[jumlahBuku] = new Buku();
        cout << "Masukkan ISBN: "; cin >> koleksiBuku[jumlahBuku]->ISBN;
        cout << "Masukkan Judul: "; cin.ignore();
        getline(cin, koleksiBuku[jumlahBuku]->judul);
        cout << "Masukkan Pengarang: "; getline(cin, koleksiBuku[jumlahBuku]->pengarang);
        cout << "Masukkan Tahun Terbit: "; cin >> koleksiBuku[jumlahBuku]->tahunTerbit;
        jumlahBuku++;
        cout << "Buku berhasil ditambahkan!\n";
    } else {
        cout << "Koleksi buku penuh!\n";
    }
}

// Fungsi Mencari Buku Berdasarkan ISBN
void cariBuku(string isbn) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (koleksiBuku[i]->ISBN == isbn) {
            cout << "Buku Ditemukan:\n";
            cout << "ISBN: " << koleksiBuku[i]->ISBN << "\n"
                 << "Judul: " << koleksiBuku[i]->judul << "\n"
                 << "Pengarang: " << koleksiBuku[i]->pengarang << "\n"
                 << "Tahun Terbit: " << koleksiBuku[i]->tahunTerbit << "\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Buku tidak ditemukan!\n";
    }
}

// Fungsi Menampilkan Semua Buku
void tampilkanBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam koleksi.\n";
    } else {
        cout << "Daftar Buku:\n";
        for (int i = 0; i < jumlahBuku; i++) {
            cout << i + 1 << ". " << koleksiBuku[i]->judul << " (ISBN: " 
                 << koleksiBuku[i]->ISBN << ")\n";
        }
    }
}

// Fungsi Menambah Antrian Peminjaman Buku
void tambahAntrian() {
    Pelanggan pelanggan;
    cout << "Masukkan Nama Pelanggan: "; cin.ignore();
    getline(cin, pelanggan.nama);
    cout << "Masukkan ISBN Buku yang Ingin Dipinjam: "; cin >> pelanggan.ISBNBuku;
    antrianPeminjaman.push(pelanggan);
    cout << "Pelanggan berhasil ditambahkan ke antrian.\n";
}

// Fungsi Memproses Peminjaman Buku (Dequeue)
void prosesPeminjaman() {
    if (!antrianPeminjaman.empty()) {
        Pelanggan pelanggan = antrianPeminjaman.front();
        antrianPeminjaman.pop();
        riwayatPeminjaman.push(pelanggan.ISBNBuku);
        cout << "Peminjaman untuk pelanggan " << pelanggan.nama 
             << " berhasil diproses. Buku ISBN: " << pelanggan.ISBNBuku << "\n";
    } else {
        cout << "Tidak ada antrian peminjaman.\n";
    }
}

// Fungsi Menampilkan Riwayat Peminjaman
void tampilkanRiwayat() {
    if (riwayatPeminjaman.empty()) {
        cout << "Belum ada peminjaman.\n";
    } else {
        cout << "Riwayat Peminjaman Buku:\n";
        stack<string> temp = riwayatPeminjaman; // Salinan stack untuk ditampilkan
        while (!temp.empty()) {
            cout << "ISBN: " << temp.top() << "\n";
            temp.pop();
        }
    }
}

// Fungsi Menu Utama
void menu() {
    int pilihan;
    do {
        cout << "\n=== Sistem Manajemen Perpustakaan ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Cari Buku Berdasarkan ISBN\n";
        cout << "3. Tampilkan Semua Buku\n";
        cout << "4. Tambah Antrian Peminjaman\n";
        cout << "5. Proses Peminjaman Buku\n";
        cout << "6. Tampilkan Riwayat Peminjaman\n";
        cout << "0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: {
                string isbn;
                cout << "Masukkan ISBN: "; cin >> isbn;
                cariBuku(isbn);
                break;
            }
            case 3: tampilkanBuku(); break;
            case 4: tambahAntrian(); break;
            case 5: prosesPeminjaman(); break;
            case 6: tampilkanRiwayat(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}
