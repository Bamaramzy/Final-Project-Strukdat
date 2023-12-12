#include <iostream>
using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahun;
    Buku* next; //pointer
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
    bukuBaru->next = kepala;
    kepala = bukuBaru;
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
    Buku* saatIni = kepala;
    Buku* sebelumnya = NULL;
    while (saatIni != NULL) {
        if (saatIni->judul == judul) {
            if (sebelumnya == NULL) {
                kepala = saatIni->next;
            } else {
                sebelumnya->next = saatIni->next;
            }
            delete saatIni;
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
        sebelumnya = saatIni;
        saatIni = saatIni->next;
    }
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
    Buku* saatIni = kepala;
    while (saatIni != NULL) {
        if (saatIni->judul == judul) {
            cout << "Buku ditemukan!" << endl;
            cout << "Judul: " << saatIni->judul << endl;
            cout << "Pengarang: " << saatIni->pengarang << endl;
            cout << "Tahun: " << saatIni->tahun << endl;
            return;
        }
        saatIni = saatIni->next;
    }
    cout << "Buku tidak ditemukan." << endl;
}

void lihat() {
    if (kepala == NULL) {
        cout << "Daftar kosong." << endl;
        return;
    }
    Buku* saatIni = kepala;
    while (saatIni != NULL) {
        cout << "Judul: " << saatIni->judul << endl;
        cout << "Pengarang: " << saatIni->pengarang << endl;
        cout << "Tahun: " << saatIni->tahun << endl;
        saatIni = saatIni->next;
    }
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