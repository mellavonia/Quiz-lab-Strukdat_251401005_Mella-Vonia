#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int N = 6;
const string NAMA[N] = {"A", "B", "C", "D", "E", "F"};
int matriks[N][N] = {0};   // Adjacency Matrix (0 = tidak ada jalur)

int idx(char v) { return v - 'A'; }

void tambahSisi(char a, char b, int w) {
    matriks[idx(a)][idx(b)] = w;
    matriks[idx(b)][idx(a)] = w;
}

void bfs(int awal) {
    vector<bool> dikunjungi(N, false);
    queue<int> antrean;
    antrean.push(awal);
    dikunjungi[awal] = true;
    cout << "BFS: ";
    while (!antrean.empty()) {
        int u = antrean.front();
        antrean.pop();
        cout << NAMA[u] << " ";
        for (int v = 0; v < N; v++)
            if (matriks[u][v] && !dikunjungi[v]) {
                dikunjungi[v] = true;
                antrean.push(v);
            }
    }
    cout << "\n";
}

void dfs(int u, vector<bool>& dikunjungi) {
    dikunjungi[u] = true;
    cout << NAMA[u] << " ";
    for (int v = 0; v < N; v++)
        if (matriks[u][v] && !dikunjungi[v])
            dfs(v, dikunjungi);
}

void dijkstra(int awal, int tujuan) {
    vector<int> jarak(N, INT_MAX);
    vector<int> prev(N, -1);
    vector<bool> selesai(N, false);
    jarak[awal] = 0;

    for (int iter = 0; iter < N; iter++) {
        
        int u = -1;
        for (int i = 0; i < N; i++)
            if (!selesai[i] && (u == -1 || jarak[i] < jarak[u]))
                u = i;
        if (u == -1 || jarak[u] == INT_MAX) break;
        selesai[u] = true;
        for (int v = 0; v < N; v++)
            if (matriks[u][v] && jarak[u] + matriks[u][v] < jarak[v]) {
                jarak[v] = jarak[u] + matriks[u][v];
                prev[v] = u;
            }
    }

    if (jarak[tujuan] == INT_MAX) {
        cout << "Tidak ada rute dari " << NAMA[awal] << " ke " << NAMA[tujuan] << "\n";
        return;
    }

    vector<string> rute;
    for (int cur = tujuan; cur != -1; cur = prev[cur])
        rute.push_back(NAMA[cur]);

    cout << "Jarak terpendek: " << jarak[tujuan] << "\n";
    cout << "Rute: ";
    for (int i = (int)rute.size() - 1; i >= 0; i--) {
        cout << rute[i];
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    tambahSisi('A', 'B', 4);
    tambahSisi('A', 'C', 2);
    tambahSisi('B', 'C', 1);
    tambahSisi('B', 'D', 5);
    tambahSisi('B', 'E', 3);
    tambahSisi('C', 'D', 8);
    tambahSisi('C', 'E', 6);
    tambahSisi('D', 'E', 2);
    tambahSisi('D', 'F', 4);
    tambahSisi('E', 'F', 3);

    char awal, tujuan;
    cout << "Vertex awal (A-F): ";
    cin >> awal;
    cout << "Vertex tujuan (A-F): ";
    cin >> tujuan;
    awal = toupper(awal);
    tujuan = toupper(tujuan);

    if (awal < 'A' || awal > 'F' || tujuan < 'A' || tujuan > 'F') {
        cout << "Vertex tidak valid\n";
        return 0;
    }

    bfs(idx(awal));
    vector<bool> dikunjungi(N, false);
    cout << "DFS: ";
    dfs(idx(awal), dikunjungi);
    cout << "\n";
    dijkstra(idx(awal), idx(tujuan));
    return 0;
}