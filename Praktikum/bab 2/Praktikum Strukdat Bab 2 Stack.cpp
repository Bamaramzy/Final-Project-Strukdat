  #include <iostream>
  #include <stack>
  using namespace std;

  struct Buku {
    string judul;
    string pengarang;
    int tahun;
  };

  void tampil(Buku b) {
    cout << "Judul: " << b.judul << endl;
    cout << "Pengarang: " << b.pengarang << endl;
    cout << "Tahun: " << b.tahun << endl;
  }

  class BukuStack {
  public:

    void push(Buku b) {
      data.push(b);
    }

    void pop() {
      if (!isEmpty()) {
        data.pop();
      }
    }

    Buku top() {
      return data.top();
    }

    int size() {
      return data.size();
    }

    bool isEmpty() {
      return data.empty();
    }

    void tampilkanSemua() {
      if (isEmpty()) {
        cout << "Stack kosong. Tidak ada data buku yang ditampilkan." << endl;
      } else {
        stack<Buku> temp; 

        cout << "Data buku dalam stack adalah:\n";
        while (!isEmpty()) {
          Buku b = top();
          tampil(b);
          temp.push(b);
          pop();
        }

        while (!temp.empty()) {
          push(temp.top());
          temp.pop();
        }
      }
    }

  private:
    stack<Buku> data;
  };

  int main() {
    BukuStack s;
    int n;
    Buku temp;

    while (true) {
      cout << "Menu:\n";
      cout << "1. Tambah Data Buku\n";
      cout << "2. Hapus Data Buku\n";
      cout << "3. Tampilkan Semua Data Buku\n";
      cout << "4. Keluar\n";
      cout << "Pilih menu (1/2/3/4): ";

      int menu;
      cin >> menu;
      cin.ignore();

      switch (menu) {
        case 1: 
          cout << "Judul: ";
          getline(cin, temp.judul);
          cout << "Pengarang: ";
          getline(cin, temp.pengarang);
          cout << "Tahun: ";
          cin >> temp.tahun;
          s.push(temp);
          cin.ignore();
          break;
        case 2: 
          s.pop();
          cout << "Data buku atas telah dihapus.\n";
          break;
        case 3: 
          s.tampilkanSemua();
          break;
        case 4: 
          return 0;
        default:
          cout << "Pilihan tidak valid. Silakan masukkan angka 1, 2, 3, atau 4.\n";
      }
    }

    return 0;
  }

