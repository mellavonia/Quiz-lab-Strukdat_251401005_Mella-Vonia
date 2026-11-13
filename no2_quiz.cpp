#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct BSTNode {
    int idBuku;
    BSTNode *left, *right;
    BSTNode(int id) : idBuku(id), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BSTNode* root = nullptr;

    void tambah(int id) { root = _tambah(root, id); }

    bool cari(int id) {
        BSTNode* cur = root;
        while (cur) {
            if (id == cur->idBuku) return true;
            cur = (id < cur->idBuku) ? cur->left : cur->right;
        }
        return false;
    }

    void preOrder(BSTNode* node, vector<int>& hasil) {
        if (!node) return;
        hasil.push_back(node->idBuku);
        preOrder(node->left, hasil);
        preOrder(node->right, hasil);
    }

    void inOrder(BSTNode* node, vector<int>& hasil) {
        if (!node) return;
        inOrder(node->left, hasil);
        hasil.push_back(node->idBuku);
        inOrder(node->right, hasil);
    }

    void postOrder(BSTNode* node, vector<int>& hasil) {
        if (!node) return;
        postOrder(node->left, hasil);
        postOrder(node->right, hasil);
        hasil.push_back(node->idBuku);
    }

private:
    BSTNode* _tambah(BSTNode* node, int id) {
        if (!node) return new BSTNode(id);
        if (id < node->idBuku) node->left = _tambah(node->left, id);
        else if (id > node->idBuku) node->right = _tambah(node->right, id);
        return node;
    }
};

void cetak(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    queue<string> antrean;       
    stack<pair<string, int>> riwayat; 
    BST koleksi;
    int pilihan;

    while (true) {
        cout << "\n1. Tambah buku (ID)\n"
             << "2. Tambah antrean peminjam\n"
             << "3. Layani peminjam (dequeue)\n"
             << "4. Catat pengembalian buku\n"
             << "5. Lihat riwayat pengembalian\n"
             << "6. Cari ID buku\n"
             << "7. Traversal BST (Pre, In, Post)\n"
             << "8. Tampilkan antrean\n"
             << "9. Keluar\n"
             << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "ID buku: "; cin >> id;
            koleksi.tambah(id);
        } else if (pilihan == 2) {
            string nama;
            cout << "Nama peminjam: "; cin >> nama;
            antrean.push(nama);
        } else if (pilihan == 3) {
            if (antrean.empty()) cout << "Antrean kosong\n";
            else {
                cout << "Melayani: " << antrean.front() << "\n";
                antrean.pop();
            }
        } else if (pilihan == 4) {
            string nama;
            int id;
            cout << "Nama peminjam: "; cin >> nama;
            cout << "ID buku: "; cin >> id;
            riwayat.push({nama, id});
            cout << "Pengembalian dicatat\n";
        } else if (pilihan == 5) {
            if (riwayat.empty()) cout << "Riwayat kosong\n";
            // Salin stack agar data asli tidak berubah
            stack<pair<string, int>> salinan = riwayat;
            while (!salinan.empty()) {
                cout << salinan.top().first << " mengembalikan buku "
                     << salinan.top().second << "\n";
                salinan.pop();
            }
        } else if (pilihan == 6) {
            int id;
            cout << "ID buku: "; cin >> id;
            cout << (koleksi.cari(id) ? "Ditemukan\n" : "Tidak ditemukan\n");
        } else if (pilihan == 7) {
            vector<int> pre, in, post;
            koleksi.preOrder(koleksi.root, pre);
            koleksi.inOrder(koleksi.root, in);
            koleksi.postOrder(koleksi.root, post);
            cout << "Pre-Order : "; cetak(pre);
            cout << "In-Order  : "; cetak(in);
            cout << "Post-Order: "; cetak(post);
        } else if (pilihan == 8) {
            if (antrean.empty()) { cout << "Antrean kosong\n"; continue; }
            // Salin queue untuk ditampilkan tanpa menghapus isinya
            queue<string> salinan = antrean;
            cout << "Antrean:";
            while (!salinan.empty()) {
                cout << " " << salinan.front();
                salinan.pop();
            }
            cout << "\n";
        } else if (pilihan == 9) {
            break;
        }
    }
    return 0;
}