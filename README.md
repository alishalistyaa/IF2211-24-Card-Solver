# IF2211-24-Card-Solver
 Project ini merupakan salah satu pemenuhan Tugas Kecil I IF2211 Strategi Algoritma:
<h2 align="center">
  24-Card-Solver<br/>
</h2>

<p> Program berbasis Command-Line Interface (CLI) yang dibuat dalam bahasa C++. Program ini mengkomputasikan semua kemungkinan solusi pada permainan kartu 24. Pada program ini, pengguna dapat memasukkan nilai kartu secara manual ataupun memanfaatkan fungsi random. </p>
<hr>

## Table of Contents
1. [Getting Started](#getting-started)
2. [How to Run](#how-to-run)
3. [Struktur](#struktur)
4. [Tampilan Program](#tampilan)

<a name="getting started"></a>

## Getting Started!

Berikut merupakan cara untuk build project atau menginstall program

1. Clone repo menggunakan command berikut

```
git clone https://github.com/alishalistyaa/IF2211-24-Card-Solver.git
```

2. Setelah masuk ke folder program, jalankan perintah berikut untuk compile program utama!

```
g++ src/main.cpp -o bin/main
```

## How-to-Run

Bagaimana cara menjalankan program? Gunakan command berikut pada folder program untuk menjalankan program utama

```
bin/main
```

<a name="struktur"></a>

## Struktur
```bash
│   README.md
│
├───.vscode
│       settings.json
├───bin
│    └────main
│ 
├───doc
│    ├─── Tucil1-Stima-2023.pdf
│    └─── Tucil1_13521171_K1_Alisha Listya Wardhani
│ 
├───src
│    │   main.c
│    │
│    ├───utils
│    │       cards.cpp
│    │       decorators.cpp
│    │       operators.cpp
│    └────modules
│         
└───test
     ├─── 38KK.txt
     ├─── 5555.txt
     ├─── A234.txt
     ├─── AKAK.txt
     ├─── R_7J89.txt
     ├─── R_76JA.txt
     ├─── R_109J3.txt
     ├─── R_931J.txt
     └─── R_J9AK.txt
```
     
<a name="tampilan"></a>
## Tampilan Program

<img width="610" alt="image" src="https://user-images.githubusercontent.com/73476678/214376664-a1aa4f9f-c45e-4683-a53a-660d6a31bd3e.png">
<img width="460" alt="image" src="https://user-images.githubusercontent.com/73476678/214376734-737aea51-00ce-43db-bd17-c3846f61fd7a.png">
