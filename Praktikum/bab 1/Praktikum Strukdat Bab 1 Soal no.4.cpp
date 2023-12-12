#include <iostream>
using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahun;
    Buku* prev;
    Buku* next;
};

Buku* kepala = NULL;

void masukkan() {
    Buku* bukuBaru = new Buku;
    cout << "Masukkan judul buku: ";
    cin >> bukuBaru->judul;
    cout << "Masukkan nama pengarang: ";
    cin >> bukuBaru->pengarang;
    cout << "Masukkan tahun terbit: ";
    cin >> bukuBaru->tahun;
    if (kepala == NULL) {
        kepala = bukuBaru;
        bukuBaru->prev = bukuBaru;
        bukuBaru->next = bukuBaru;
    } else {
        Buku* last = kepala->prev;
        last->next = bukuBaru;
        bukuBaru->prev = last;
        bukuBaru->next = kepala;
        kepala->prev = bukuBaru;
    }
    cout << "Buku berhasil ditambahkan!" << endl;
}

void hapusBuku() {
    if (kepala == NULL) {
        cout << "Daftar kosong." << endl;
        return;
    }
    string judul;
    cout << "Masukkan judul buku yang akan dihapus: ";
    cin >> judul;
    Buku* current = kepala;
    do {
        if (current->judul == judul) {
            if (current->next == current) {
                kepala = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == kepala) {
                    kepala = current->next;
                }
            }
            delete current;
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
        current = current->next;
    } while (current != kepala);
    cout << "Buku tidak ditemukan." << endl;
}

void cari() {
    if (kepala == NULL) {
        cout << "Daftar kosong." << endl;
        return;
    }
    string judul;
    cout << "Masukkan judul buku yang akan dicari: ";
    cin >> judul;
    Buku* current = kepala;
    do {
        if (current->judul == judul) {
            cout << "Buku ditemukan!" << endl;
            cout << "Judul: " << current->judul << endl;
            cout << "Pengarang: " << current->pengarang << endl;
            cout << "Tahun: " << current->tahun << endl;
            return;
        }
        current = current->next;
    } while (current != kepala);
    cout << "Buku tidak ditemukan." << endl;
}

void lihat() {
    if (kepala == NULL) {
        cout << "Daftar kosong." << endl;
        return;
    }
    Buku* current = kepala;
    do {
        cout << "Judul: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Tahun: " << current->tahun << endl;
        current = current->next;
    } while (current != kepala);
}

int main() {
    int pilihan;
    do {
        cout << "Menu:" << endl;
        cout << "1. Masukkan data buku" << endl;
        cout << "2. Hapus data buku" << endl;
        cout << "3. Cari buku" << endl;
        cout << "4. Lihat daftar buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                masukkan();
                break;
            case 2:
                hapusBuku();
                break;
            case 3:
                cari();
                break;
            case 4:
                lihat();
                break;
            case 5:
                cout << "Selamat tinggal!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5);
    return 0;
}