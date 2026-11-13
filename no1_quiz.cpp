#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string nim, nama;
    int nilai;
    Node* next;
    Node(string n, string na, int v) : nim(n), nama(na), nilai(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void tambah(string nim, string nama, int nilai) {
        Node* baru = new Node(nim, nama, nilai);
        if (!head) { head = baru; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = baru;
    }

    void tampilkan() {
        if (!head) { cout << "Data kosong\n"; return; }
        for (Node* cur = head; cur; cur = cur->next)
            cout << "NIM: " << cur->nim << " | Nama: " << cur->nama
                 << " | Nilai: " << cur->nilai << "\n";
    }

    Node* cariNim(string nim) { 
        for (Node* cur = head; cur; cur = cur->next)
            if (cur->nim == nim) return cur;
        return nullptr;
    }
};

void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int kunci = arr[i];
        int j = (int)i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

int binarySearch(const vector<int>& arr, int target) {
    int kiri = 0, kanan = (int)arr.size() - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (arr[tengah] == target) return tengah;
        if (arr[tengah] < target) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}

int main() {
    LinkedList daftar;
    vector<int> nilaiArray;
    bool sudahUrut = false;
    int pilihan;

    while (true) {
        cout << "\n1. Tambah mahasiswa\n"
             << "2. Cari mahasiswa berdasarkan NIM (Linear Search)\n"
             << "3. Urutkan nilai (Insertion Sort)\n"
             << "4. Cari nilai (Binary Search)\n"
             << "5. Tampilkan semua mahasiswa\n"
             << "6. Keluar\n"
             << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nim, nama;
            int nilai;
            cout << "NIM: "; cin >> nim;
            cout << "Nama: "; cin >> nama;
            cout << "Nilai: "; cin >> nilai;
            daftar.tambah(nim, nama, nilai);
            nilaiArray.push_back(nilai);
            sudahUrut = false;
        } else if (pilihan == 2) {
            string nim;
            cout << "Masukkan NIM: "; cin >> nim;
            Node* hasil = daftar.cariNim(nim);
            if (hasil) cout << "Ditemukan: " << hasil->nama << ", nilai " << hasil->nilai << "\n";
            else cout << "Mahasiswa tidak ditemukan\n";
        } else if (pilihan == 3) {
            insertionSort(nilaiArray);
            sudahUrut = true;
            cout << "Nilai terurut:";
            for (int v : nilaiArray) cout << " " << v;
            cout << "\n";
        } else if (pilihan == 4) {
            if (!sudahUrut) { cout << "Urutkan nilai dulu (menu 3)\n"; continue; }
            int target;
            cout << "Nilai yang dicari: "; cin >> target;
            int idx = binarySearch(nilaiArray, target);
            if (idx != -1) cout << "Nilai " << target << " ditemukan di indeks " << idx << "\n";
            else cout << "Nilai tidak ditemukan\n";
        } else if (pilihan == 5) {
            daftar.tampilkan();
        } else if (pilihan == 6) {
            break;
        }
    }
    return 0;
}