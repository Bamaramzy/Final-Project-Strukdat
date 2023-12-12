#include <iostream>
#include <string>

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
    cout << "=====" << endl;
    cout << "Genre: " << b.genre << endl;
    cout << "Judul: " << b.judul << endl;
    cout << "Pengarang: " << b.pengarang << endl;
    cout << "Tahun: " << b.tahun << endl;
}

struct BSTNode
{
    Buku data;
    BSTNode *left, *right;

    BSTNode(Buku book) : data(book), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    BSTNode *root;

public:
    BST() : root(nullptr) {}

    void insert(Buku book)
    {
        root = insertRecursive(root, book);
    }

    BSTNode *insertRecursive(BSTNode *node, Buku book)
    {
        if (!node)
        {
            return new BSTNode(book);
        }

        if (book.judul < node->data.judul)
        {
            node->left = insertRecursive(node->left, book);
        }
        else if (book.judul > node->data.judul)
        {
            node->right = insertRecursive(node->right, book);
        }

        return node;
    }

    bool search(string judul)
    {
        return searchRecursive(root, judul);
    }

    bool searchRecursive(BSTNode *node, string judul)
    {
        if (!node)
        {
            return false;
        }

        if (judul == node->data.judul)
        {
            tampil(node->data);
            return true;
        }
        else if (judul < node->data.judul)
        {
            return searchRecursive(node->left, judul);
        }
        else
        {
            return searchRecursive(node->right, judul);
        }
    }

    void deleteNode(string judul)
    {
        root = deleteRecursive(root, judul);
    }

    BSTNode *deleteRecursive(BSTNode *node, string judul)
    {
        if (!node)
        {
            return nullptr;
        }

        if (judul < node->data.judul)
        {
            node->left = deleteRecursive(node->left, judul);
        }
        else if (judul > node->data.judul)
        {
            node->right = deleteRecursive(node->right, judul);
        }
        else
        {
            if (!node->left)
            {
                BSTNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }

            BSTNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data.judul);
        }

        return node;
    }

    BSTNode *findMin(BSTNode *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    void displayAll()
    {
        if (!root)
        {
            cout << "Tidak ada data buku yang tersimpan." << endl;
            return;
        }

        inorderTraversal(root);
    }

    void inorderTraversal(BSTNode *node)
    {
        if (node)
        {
            inorderTraversal(node->left);
            tampil(node->data);
            inorderTraversal(node->right);
        }
    }
};

int main()
{
    BST binarySearchTree;
    Buku temp;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data Buku\n";
        cout << "2. Cari Data Buku (BST)\n";
        cout << "3. Hapus Data Buku (BST)\n";
        cout << "4. Tampilkan Semua Data Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1/2/3/4/5): ";

        int menu;
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            cout << "======= \n";
            cout << "Genre: ";
            getline(cin, temp.genre);
            cout << "Judul: ";
            getline(cin, temp.judul);
            cout << "Pengarang: ";
            getline(cin, temp.pengarang);
            cout << "Tahun: ";
            cin >> temp.tahun;
            binarySearchTree.insert(temp);
            cin.ignore();
            break;

        case 2:
            cout << "Judul: ";
            getline(cin, temp.judul);
            if (!binarySearchTree.search(temp.judul))
            {
                cout << "Buku dengan judul tersebut tidak ditemukan.\n";
            }
            break;

        case 3:
            cout << "Judul: ";
            getline(cin, temp.judul);
            binarySearchTree.deleteNode(temp.judul);
            break;

        case 4:
            binarySearchTree.displayAll();
            break;

        case 5:
            return 0;

        default:
            cout << "Pilihan tidak valid. Silakan masukkan angka 1, 2, 3, 4, atau 5.\n";
        }
    }

    return 0;
}
