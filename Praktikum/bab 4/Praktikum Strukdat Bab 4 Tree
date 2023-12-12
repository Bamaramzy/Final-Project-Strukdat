#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Buku
{
    string genre;
    string judul;
    string pengarang;
    int tahun;
    Buku *left;
    Buku *right;
    int height;
};

class BST
{
public:
    Buku *root;

    BST()
    {
        root = NULL;
    }

    Buku *createNode(string genre, string judul, string pengarang, int tahun)
    {
        Buku *newNode = new Buku;
        newNode->genre = genre;
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahun = tahun;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    Buku *insert(Buku *node, string genre, string judul, string pengarang, int tahun)
    {
        if (node == NULL)
        {
            return createNode(genre, judul, pengarang, tahun);
        }
        if (genre == node->genre)
        {
            node->left = insert(node->left, genre, judul, pengarang, tahun);
        }
        else if (genre == node->genre)
        {
            node->right = insert(node->right, genre, judul, pengarang, tahun);
        }
        return node;
    }

    vector<Buku *> search(Buku *node, string genre)
    {
        vector<Buku *> result;
        if (node == NULL)
        {
            return result;
        }
        if (node->genre == genre)
        {
            result.push_back(node);
        }
        if (genre == node->genre)
        {
            return search(node->left, genre);
        }
        else if (genre == node->genre)
        {
            return search(node->right, genre);
        }
        return result;
    }

    void inOrderTraversal(Buku *node)
    {
        if (node != NULL)
        {
            inOrderTraversal(node->left);
            cout << "genre: " << node->genre << ", judul: " << node->judul << ", pengarang: " << node->pengarang << ", Tahun: " << node->tahun << endl;
            inOrderTraversal(node->right);
        }
    }
};

int main()
{
    BST bst;
    bst.root = bst.insert(bst.root, "Novel", "judul1", "pengarang1", 2022);
    bst.root = bst.insert(bst.root, "Novel", "judul2", "pengarang2", 2023);
    bst.root = bst.insert(bst.root, "Novel", "judul3", "pengarang3", 2022);
    bst.root = bst.insert(bst.root, "Novel", "judul4", "pengarang4", 2022);
    bst.root = bst.insert(bst.root, "Nonfiksi", "judul5", "pengarang5", 2022);
    bst.root = bst.insert(bst.root, "Nonfiksi", "judul6", "pengarang6", 2022);
    bst.root = bst.insert(bst.root, "Fiksi", "judul7", "pengarang7", 2022);
    bst.root = bst.insert(bst.root, "Fiksi", "judul8", "pengarang8", 2022);
    bst.root = bst.insert(bst.root, "Fiksi", "judul9", "pengarang9", 2022);
    bst.root = bst.insert(bst.root, "Fiksi", "judul10", "pengarang10", 2022);

    // search
 vector<Buku *> result = bst.search(bst.root, "Nonfiksi");
    if (!result.empty())
    {
        cout << "Buku Ditemukan: " << endl;
        for (Buku *node : result)
        {
            cout << "genre: " << node->genre << ", judul: " << node->judul << ", pengarang: " << node->pengarang << ", Tahun: " << node->tahun << endl;
        }
    }
    else
    {
        cout << "Buku Tidak Ditemukan" << endl;
    }

    // view
    bst.inOrderTraversal(bst.root);

    return 0;
}
