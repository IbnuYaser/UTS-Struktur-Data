#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string nama;
    float IPK;
};

void tambahMahasiswa(Mahasiswa* arr[], int& count) {
    if (count < 10) {
        arr[count] = new Mahasiswa();
        cout << "Masukkan NIM: "; cin >> arr[count]->NIM;
        cout << "Masukkan Nama: "; cin >> arr[count]->nama;
        cout << "Masukkan IPK: "; cin >> arr[count]->IPK;
        count++;
    } else {
        cout << "Data mahasiswa penuh!\n";
    }
}

void hapusMahasiswa(Mahasiswa* arr[], int& count) {
    if (count > 0) {
        delete arr[count - 1];
        count--;
        cout << "Mahasiswa terakhir berhasil dihapus.\n";
    } else {
        cout << "Tidak ada data untuk dihapus.\n";
    }
}

void tampilkanMahasiswa(Mahasiswa* arr[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "NIM: " << arr[i]->NIM << ", Nama: " << arr[i]->nama 
             << ", IPK: " << arr[i]->IPK << endl;
    }
}

void urutkanMahasiswa(Mahasiswa* arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->IPK < arr[j + 1]->IPK) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Mahasiswa berhasil diurutkan berdasarkan IPK.\n";
}

int main() {
    Mahasiswa* mahasiswa[10];
    int count = 0;
    int pilihan;
    do {
        cout << "1. Tambah Mahasiswa\n2. Hapus Mahasiswa\n"
             << "3. Tampilkan Mahasiswa\n4. Urutkan Mahasiswa\n0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;
        switch (pilihan) {
            case 1: tambahMahasiswa(mahasiswa, count); break;
            case 2: hapusMahasiswa(mahasiswa, count); break;
            case 3: tampilkanMahasiswa(mahasiswa, count); break;
            case 4: urutkanMahasiswa(mahasiswa, count); break;
        }
    } while (pilihan != 0);
    return 0;
}
