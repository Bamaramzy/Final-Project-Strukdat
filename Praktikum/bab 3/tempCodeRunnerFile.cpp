#include <iostream>
#include <queue>
using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahun;
};

int main(){
    queue<Buku> antrianBuku;

//Enqueue
Buku buku1 = {"Judul1", "Pengarang1", 2022};
antrianBuku.push(buku1);

Buku buku2 = {"Judul2", "Pengarang2", 2020};
antrianBuku.push(buku2);

//Dequeue
if (!antrianBuku.empty()) {
    Buku bukuDepan = antrianBuku.front();
    cout << "Buku yang dikeluarkan: " << bukuDepan.judul << endl;
    antrianBuku.pop();
} else {
    cout << "Antrian Kosong" << endl;

}
return 0;
}