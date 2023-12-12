#include <iostream>
#include <string>

using namespace std;

struct Buku
{
    string genre;
    string judul;
    string pengarang;
    int tahun;
    int height;
};

void tampil(Buku b)
{
    cout << "===== " << endl;
    cout << "Genre: " << b.genre << endl;
    cout << "Judul: " << b.judul << endl;
    cout << "Pengarang: " << b.pengarang << endl;
    cout << "Tahun: " << b.tahun << endl;
    cout << "Tinggi: " << b.height << endl;
}

struct AVLNode
{
    Buku data;
    AVLNode *left, *right;
    int height;

    AVLNode(Buku book) : data(book), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    AVLNode *root;

    int getHeight(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *rightRotate(AVLNode *node)
    {
        AVLNode *y = node->left;
        AVLNode *T2 = y->right;

        y->right = node;
        node->left = T2;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode *leftRotate(AVLNode *node)
    {
        AVLNode *y = node->right;
        AVLNode *T2 = y->left;

        y->left = node;
        node->right = T2;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode *insert(AVLNode *node, Buku book)
    {
        if (node == nullptr)
            return new AVLNode(book);

        if (book.judul < node->data.judul)
            node->left = insert(node->left, book);
        else
            node->right = insert(node->right, book);

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Right Right Case
        if (balance > 1 && book.judul < node->left->data.judul)
            return rightRotate(node);

        // Right Left Case
        if (balance > 1 && book.judul > node->left->data.judul)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Left Left Case
        if (balance < -1 && book.judul > node->right->data.judul)
            return leftRotate(node);

        // Left Right Case
        if (balance < -1 && book.judul < node->right->data.judul)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode *deleteNode(AVLNode *root, string judul)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (judul < root->data.judul)
        {
            root->left = deleteNode(root->left, judul);
        }
        else if (judul > root->data.judul)
        {
            root->right = deleteNode(root->right, judul);
        }
        else
        {
            if (root->left == nullptr)
            {
                AVLNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                AVLNode *temp = root->left;
                delete root;
                return temp;
            }

            AVLNode *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.judul);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        if (balance > 1 && getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void displayAll(AVLNode *node)
    {
        if (node == nullptr)
            return;

        displayAll(node->left);
        tampil(node->data);
        displayAll(node->right);
    }

    AVLNode *minValueNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

public:
    AVLTree() : root(nullptr) {}

    AVLNode *getRoot()
    {
        return root;
    }

    void insert(Buku book)
    {
        root = insert(root, book);
    }

    void deleteNode(string judul)
    {
        root = deleteNode(root, judul);
    }

    void displayAll()
    {
        displayAll(root);
    }

    AVLNode *searchNode(string judul)
    {
        return searchNode(root, judul);
    }

    AVLNode *searchNode(AVLNode *node, string judul)
    {
        if (node == nullptr || node->data.judul == judul)
        {
            return node;
        }

        if (judul < node->data.judul)
        {
            return searchNode(node->left, judul);
        }
        return searchNode(node->right, judul);
    }
};

void searchAndDisplay(AVLTree &avlTree, string judul)
{
    AVLNode *result = avlTree.searchNode(judul);

    if (result != nullptr)
    {
        cout << "Buku Ditemukan:\n";
        tampil(result->data);
    }
    else
    {
        cout << "Buku Dengan Judul '" << judul << "' Tidak Ditemukan.\n";
    }
}

int main()
{
    AVLTree avlTree;
    Buku temp;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data Buku\n";
        cout << "2. Hapus Data Buku\n";
        cout << "3. Tampilkan Semua Data Buku\n";
        cout << "4. Cari Data Buku Berdasarkan Judul (AVL)\n";
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
            avlTree.insert(temp);
            cin.ignore();
            break;

        case 2:
            cout << "Judul: ";
            getline(cin, temp.judul);
            avlTree.deleteNode(temp.judul);
            break;

        case 3:
            avlTree.displayAll();
            break;

        case 4:
            cout << "Judul: ";
            getline(cin, temp.judul);
            searchAndDisplay(avlTree, temp.judul);
            break;

        case 5:
            return 0;

        default:
            cout << "Pilihan tidak valid. Silakan masukkan angka 1, 2, 3, 4, atau 5.\n";
        }
    }

    return 0;
}
