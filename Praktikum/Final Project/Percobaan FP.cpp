#include <iostream>
#include <string>

using namespace std;

struct Buku
{
    string genre;
    string judul;
    string pengarang;
    int tahun;

    void tampil() const
    {
        cout << "=====" << endl;
        cout << "Genre: " << genre << endl;
        cout << "Judul: " << judul << endl;
        cout << "Pengarang: " << pengarang << endl;
        cout << "Tahun: " << tahun << endl;
    }
};

template <class T>
struct TreeNode
{
    T data;
    TreeNode<T> *kiri, *kanan;

    TreeNode(const T &item) : data(item), kiri(nullptr), kanan(nullptr) {}
};

template <class T>
class PohonBiner
{
private:
    TreeNode<T> *akar;

protected:
    virtual TreeNode<T> *sisipkan(TreeNode<T> *node, const T &item)
    {
        if (!node)
        {
            return new TreeNode<T>(item);
        }

        if (item.judul < node->data.judul)
        {
            node->kiri = sisipkan(node->kiri, item);
        }
        else if (item.judul > node->data.judul)
        {
            node->kanan = sisipkan(node->kanan, item);
        }

        return node;
    }

    virtual bool cari(TreeNode<T> *node, const string &judul) const
    {
        if (!node)
        {
            return false;
        }

        if (judul == node->data.judul)
        {
            node->data.tampil();
            return true;
        }
        else if (judul < node->data.judul)
        {
            return cari(node->kiri, judul);
        }
        else
        {
            return cari(node->kanan, judul);
        }
    }

    virtual TreeNode<T> *hapusNode(TreeNode<T> *node, const string &judul)
    {
        if (!node)
        {
            return nullptr;
        }

        if (judul < node->data.judul)
        {
            node->kiri = hapusNode(node->kiri, judul);
        }
        else if (judul > node->data.judul)
        {
            node->kanan = hapusNode(node->kanan, judul);
        }
        else
        {
            if (!node->kiri)
            {
                TreeNode<T> *temp = node->kanan;
                delete node;
                return temp;
            }
            else if (!node->kanan)
            {
                TreeNode<T> *temp = node->kiri;
                delete node;
                return temp;
            }

            TreeNode<T> *temp = temukanMin(node->kanan);
            node->data = temp->data;
            node->kanan = hapusNode(node->kanan, temp->data.judul);
        }

        return node;
    }

    virtual TreeNode<T> *temukanMin(TreeNode<T> *node)
    {
        while (node->kiri)
        {
            node = node->kiri;
        }
        return node;
    }

    virtual void penelusuranInorder(TreeNode<T> *node) const
    {
        if (node)
        {
            penelusuranInorder(node->kiri);
            node->data.tampil();
            penelusuranInorder(node->kanan);
        }
    }

public:
    PohonBiner() : akar(nullptr) {}

    void sisipkan(const T &item)
    {
        akar = sisipkan(akar, item);
    }

    bool cari(const string &judul) const
    {
        return cari(akar, judul);
    }

    void hapusNode(const string &judul)
    {
        akar = hapusNode(akar, judul);
    }

    void tampilkanSemua() const
    {
        if (!akar)
        {
            cout << "Tidak ada data buku tersimpan." << endl;
            return;
        }

        penelusuranInorder(akar);
    }
};

class PohonAVL : public PohonBiner<Buku>
{
};

class PengelolaBuku
{
public:
    static void kelolaPohonAVL(PohonAVL &pohonAVL)
    {
        int menu;

        while (true)
        {
            cout << "Menu Pohon AVL:\n";
            cout << "1. Tambah Buku\n";
            cout << "2. Cari Buku\n";
            cout << "3. Hapus Buku\n";
            cout << "4. Tampilkan Semua Buku\n";
            cout << "5. Kembali ke Opsi Pohon\n";
            cout << "6. Keluar\n";
            cout << "Pilih menu (1-6): ";

            cin >> menu;
            cin.ignore();

            switch (menu)
            {
            case 1:
                tambahBuku(pohonAVL);
                break;
            case 2:
                cariBuku(pohonAVL);
                break;
            case 3:
                hapusBuku(pohonAVL);
                break;
            case 4:
                pohonAVL.tampilkanSemua();
                break;
            case 5:
                return;
            case 6:
                exit(0);
            default:
                cout << "Opsi tidak valid. Harap masukkan angka dari 1 hingga 6.\n";
            }
        }
    }

    static void kelolaPohonBiner(PohonBiner<Buku> &pohonBiner)
    {
        int menu;

        while (true)
        {
            cout << "Menu Pohon Biner Pencarian (BST):\n";
            cout << "1. Tambah Buku\n";
            cout << "2. Cari Buku\n";
            cout << "3. Hapus Buku\n";
            cout << "4. Tampilkan Semua Buku\n";
            cout << "5. Kembali ke Opsi Pohon\n";
            cout << "6. Keluar\n";
            cout << "Pilih menu (1-6): ";

            cin >> menu;
            cin.ignore();

            switch (menu)
            {
            case 1:
                tambahBuku(pohonBiner);
                break;
            case 2:
                cariBuku(pohonBiner);
                break;
            case 3:
                hapusBuku(pohonBiner);
                break;
            case 4:
                pohonBiner.tampilkanSemua();
                break;
            case 5:
                return;
            case 6:
                exit(0);
            default:
                cout << "Opsi tidak valid. Harap masukkan angka dari 1 hingga 6.\n";
            }
        }
    }

    static void tambahBuku(PohonBiner<Buku> &pohon)
    {
        cout << "======= \n";
        Buku bukuBaru;
        cout << "Genre: ";
        getline(cin, bukuBaru.genre);
        cout << "Judul: ";
        getline(cin, bukuBaru.judul);
        cout << "Pengarang: ";
        getline(cin, bukuBaru.pengarang);
        cout << "Tahun: ";
        cin >> bukuBaru.tahun;
        pohon.sisipkan(bukuBaru);
        cin.ignore();
    }

    static void cariBuku(const PohonBiner<Buku> &pohon)
    {
        cout << "Judul: ";
        string judul;
        getline(cin, judul);
        if (!pohon.cari(judul))
        {
            cout << "Buku dengan judul tersebut tidak ditemukan.\n";
        }
    }

    static void hapusBuku(PohonBiner<Buku> &pohon)
    {
        cout << "Judul: ";
        string judul;
        getline(cin, judul);
        pohon.hapusNode(judul);
    }

    static void inisialisasiDenganData(PohonAVL &pohonAVL, PohonBiner<Buku> &pohonBiner)
    {
        Buku buku1 = {"Fiksi", "The Great Gatsby", "F. Scott Fitzgerald", 1925};
        Buku buku2 = {"Misteri", "The Hound of the Baskervilles", "Arthur Conan Doyle", 1902};
        Buku buku3 = {"Fiksi Ilmiah", "Dune", "Frank Herbert", 1965};

        pohonAVL.sisipkan(buku1);
        pohonAVL.sisipkan(buku2);
        pohonAVL.sisipkan(buku3);

        pohonBiner.sisipkan(buku1);
        pohonBiner.sisipkan(buku2);
        pohonBiner.sisipkan(buku3);
    }
};

class PengelolaBukuUtama
{
private:
    PohonAVL pohonAVL;
    PohonBiner<Buku> pohonBiner;

public:
    void jalankan()
    {
        PengelolaBuku::inisialisasiDenganData(pohonAVL, pohonBiner);

        int opsiPohon;

        while (true)
        {
            cout << "Menu Opsi Pohon:\n";
            cout << "1. Gunakan Pohon AVL\n";
            cout << "2. Gunakan Pohon Biner Pencarian (BST)\n";
            cout << "3. Lihat Data Buku\n";
            cout << "4. Keluar\n";
            cout << "Pilih opsi pohon (1-4): ";
            cin >> opsiPohon;
            cin.ignore(); // Membersihkan buffer masukan

            if (opsiPohon == 4)
            {
                return;
            }
            else if (opsiPohon == 3)
            {
                tampilkanSemuaBuku();
            }
            else if (opsiPohon == 1)
            {
                PengelolaBuku::kelolaPohonAVL(pohonAVL);
            }
            else if (opsiPohon == 2)
            {
                PengelolaBuku::kelolaPohonBiner(pohonBiner);
            }
            else
            {
                cout << "Opsi tidak valid. Harap masukkan angka dari 1 hingga 4.\n";
            }
        }
    }

private:
    void tampilkanSemuaBuku()
    {
        cout << "Data Buku dalam Pohon AVL:\n";
        pohonAVL.tampilkanSemua();

        cout << "\nData Buku dalam Pohon Biner Pencarian (BST):\n";
        pohonBiner.tampilkanSemua();
    }
};

int main()
{
    PengelolaBukuUtama pengelolaBukuUtama;
    pengelolaBukuUtama.jalankan();

    return 0;
}
