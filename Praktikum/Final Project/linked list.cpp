#include <iostream>
using namespace std;

struct Buku
{
    string genre;
    string judul;
    string pengarang;
    int tahun;
};

void tampil(Buku b)
{
    cout << "Genre: " << b.genre << endl;
    cout << "Judul: " << b.judul << endl;
    cout << "Pengarang: " << b.pengarang << endl;
    cout << "Tahun: " << b.tahun << endl;
}

struct Node
{
    Buku data;
    Node *next;

    Node(Buku book) : data(book), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(Buku book)
    {
        Node *newNode = new Node(book);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayAll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            tampil(temp->data);
            temp = temp->next;
        }
    }

    void searchByGenre(string genre)
    {
        Node *temp = head;
        bool found = false;
        while (temp != nullptr)
        {
            if (temp->data.genre == genre)
            {
                tampil(temp->data);
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Buku dengan genre tersebut tidak ditemukan.\n";
        }
    }

    void deleteByJudul(string judul)
    {
        Node *current = head;
        Node *previous = nullptr;

        if (current != nullptr && current->data.judul == judul)
        {
            head = current->next;
            delete current;
            cout << "Data buku dengan judul tersebut telah dihapus.\n";
            return;
        }

        while (current != nullptr && current->data.judul != judul)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Buku dengan judul tersebut tidak ditemukan.\n";
            return;
        }

        previous->next = current->next;
        delete current;

        cout << "Data buku dengan judul tersebut telah dihapus.\n";
    }
};

int main()
{
    LinkedList linkedList;
    Buku temp;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data Buku\n";
        cout << "2. Hapus Data Buku\n";
        cout << "3. Tampilkan Semua Data Buku\n";
        cout << "4. Cari Data Buku Berdasarkan Genre\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1/2/3/4/5): ";

        int menu;
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            cout << "Genre: ";
            getline(cin, temp.genre);
            cout << "Judul: ";
            getline(cin, temp.judul);
            cout << "Pengarang: ";
            getline(cin, temp.pengarang);
            cout << "Tahun: ";
            cin >> temp.tahun;
            linkedList.insert(temp);
            cin.ignore();
            break;
        case 2:
            cout << "Judul: ";
            getline(cin, temp.judul);
            linkedList.deleteByJudul(temp.judul);
            break;
        case 3:
            linkedList.displayAll();
            break;
        case 4:
            cout << "Genre: ";
            getline(cin, temp.genre);
            linkedList.searchByGenre(temp.genre);
            break;
        case 5:
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan masukkan angka 1, 2, 3, 4, atau 5.\n";
        }
    }

    return 0;
}
