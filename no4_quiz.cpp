#include <iostream>
#include <string>
using namespace std;

const int UKURAN = 20;

struct Entry {
    int status;
    int nim;
    string nama;
};

Entry tabel[UKURAN];
int jumlahCollision = 0;

int hash1(int key) { return key % 20; }
int hash2(int key) { return 19 - (key % 19); }

void insert(int nim, const string& nama) {
    int h1 = hash1(nim), h2 = hash2(nim);
    for (int i = 0; i < UKURAN; i++) {
        int pos = (h1 + i * h2) % UKURAN;
        if (tabel[pos].status != 1) {
            tabel[pos] = {1, nim, nama};
            cout << "NIM " << nim << " disimpan di indeks " << pos << "\n";
            return;
        }
        if (tabel[pos].nim == nim) {
            tabel[pos].nama = nama;
            cout << "Data NIM " << nim << " diperbarui\n";
            return;
        }
        jumlahCollision++;
        cout << "Collision di indeks " << pos << ", mencoba lagi...\n";
    }
    cout << "Tabel penuh\n";
}

int search(int nim) {
    int h1 = hash1(nim), h2 = hash2(nim);
    for (int i = 0; i < UKURAN; i++) {
        int pos = (h1 + i * h2) % UKURAN;
        if (tabel[pos].status == 0) return -1;
        if (tabel[pos].status == 1 && tabel[pos].nim == nim) return pos;
    }
    return -1;
}

void remove(int nim) {
    int pos = search(nim);
    if (pos == -1) {
        cout << "Data tidak ditemukan\n";
        return;
    }
    cout << "Menghapus " << tabel[pos].nama << " (NIM " << nim << ")\n";
    tabel[pos].status = 2;
}

void display() {
    for (int i = 0; i < UKURAN; i++) {
        cout << i << " ";
        if (tabel[i].status == 0) cout << "-";
        else if (tabel[i].status == 2) cout << "(dihapus)";
        else cout << "(" << tabel[i].nim << ", " << tabel[i].nama << ")";
        cout << "\n";
    }
}

int main() {
    cout << "=== INSERT ===\n";
    insert(101, "Andi");
    insert(121, "Budi");
    insert(141, "Citra");
    insert(161, "Dewi");
    insert(181, "Eka");

    cout << "\n=== DISPLAY ===\n";
    display();

    cout << "\n=== SEARCH ===\n";
    for (int nim : {141, 999}) {
        int pos = search(nim);
        cout << "NIM " << nim << ": "
             << (pos != -1 ? "ditemukan di indeks " + to_string(pos) : "tidak ditemukan") << "\n";
    }

    cout << "\n=== REMOVE ===\n";
    remove(121);
    display();

    cout << "\nTotal collision: " << jumlahCollision << "\n";
    return 0;
}