**Identitas Diri**
Nama: Mella Vonia
NIM: 251401005
Lab: 3

**Ringkasan Tiap Program**

**no1_quiz.cpp (Pengelolaan Data Mahasiswa)**
Program ini menyimpan data mahasiswa berupa NIM, nama, dan nilai menggunakan Single Linked List. Nilai-nilai tersebut kemudian diurutkan dari yang terkecil hingga terbesar dengan Insertion Sort, yang dijalankan pada Dynamic Array. Program juga bisa mencari data dengan dua cara, yaitu Linear Search dan Binary Search.

**no2_quiz.cpp (Sistem Manajemen Perpustakaan)**
Program ini meniru alur layanan perpustakaan kampus. Antrean peminjaman buku dikelola dengan Queue (FIFO), riwayat pengembalian buku disimpan dengan Stack (LIFO), dan ID buku dikelola serta dicari menggunakan Binary Search Tree (BST) supaya datanya lebih tertata.

**no3_quiz.cpp (Penelusuran Rute dan Jalur Kampus)**
Program ini memodelkan peta antar titik di area kampus dalam bentuk Adjacency Matrix. Penelusuran jalur dilakukan dengan BFS (Breadth-First Search) dan DFS (Depth-First Search), sedangkan rute terpendek antar lokasi dicari menggunakan algoritma Dijkstra.

**no4_quiz.cpp (Hash Table Data Mahasiswa)**
Program ini mengelola data NIM dan nama mahasiswa dalam jumlah besar menggunakan Hash Table berukuran 20. Tabrakan data (collision) ditangani dengan metode Double Hashing, dan penghapusan data dilakukan secara aman dengan lazy deletion.

**Struktur Folder Proyek**
```
Quiz-lab-Strukdat_251401005_Mella-Vonia/
├── README.md
├── no1_quiz.cpp
├── no2_quiz.cpp
├── no3_quiz.cpp
└── no4_quiz.cpp
```

**Cara Menjalankan Program**
Cara termudah adalah dengan menekan ikon panah (Run) di VS Code saat file kodenya dibuka. Atau bisa juga lewat terminal:

**1. Kompilasi dan jalankan Soal 1**
```
g++ no1_quiz.cpp -o no1_quiz
./no1_quiz
```

**2. Kompilasi dan jalankan Soal 2**
```
g++ no2_quiz.cpp -o no2_quiz
./no2_quiz
```

**3. Kompilasi dan jalankan Soal 3**
```
g++ no3_quiz.cpp -o no3_quiz
./no3_quiz
```

**4. Kompilasi dan jalankan Soal 4**
```
g++ no4_quiz.cpp -o no4_quiz
./no4_quiz
```

**Tautan Video Penjelasan YouTube**
https://youtu.be/_tG5ahZ7lKI?si=OJQJu74SmtkgkRqe
