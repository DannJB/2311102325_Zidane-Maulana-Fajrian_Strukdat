# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Zidane Maulana Fajrian - 2311102325</p>

## Dasar Teori
Abstract Data Type (ADT) adalah tipe data yang terdiri dari definisi tipe (type) dan sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe tersebut. ADT juga mencakup invarian dan aksioma sebagai aturan yang harus dipenuhi. ADT memungkinkan data dikelola melalui operasi tertentu tanpa harus mengetahui detail implementasinya..[1]

Operasi dalam ADT meliputi konstruktor untuk membentuk nilai, selector untuk mengakses komponen, prosedur pengubah nilai, validator untuk memeriksa kesesuaian data, serta operasi input/output dan operator lainnya. Contoh penerapan ADT adalah waktu yang terdiri dari tipe jam dan tanggal, serta garis yang dibentuk dari dua titik (point).[1]

Dalam bahasa C++, ADT dapat diimplementasikan menggunakan struct atau class, dengan operasi yang didefinisikan melalui fungsi dan prosedur. Implementasinya umumnya terdiri dari modul spesifikasi tipe dan operasi (.h), modul realisasi operasi (.c atau .cpp), serta program utama (driver) yang menggunakan ADT tersebut.[1]


## Guided 

### 1. Mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m)
{
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai =";
    cin >> (m).nilai1;
    cout << "input nilai =";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m)
{
    return float(m.nilai1 + m.nilai2) / 2;
}
```
penjelasan code
Kode tersebut memiliki dua fungsi. Fungsi inputMhs(mahasiswa &m) digunakan untuk memasukkan NIM dan dua nilai mahasiswa, yaitu nilai1 dan nilai2. Tanda & berarti data mahasiswa dapat diubah langsung melalui variabel aslinya. Sementara itu, fungsi rata2(mahasiswa m) digunakan untuk menghitung rata-rata dari kedua nilai mahasiswa dengan menjumlahkan nilai1 dan nilai2, kemudian membaginya dengan 2. Hasil perhitungan dikembalikan dalam bentuk tipe data float.

### 2. Mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif

```
penjelasan code
Kode mahasiswa.h merupakan header file yang berfungsi untuk mendefinisikan struktur data dan deklarasi fungsi mahasiswa. #ifndef, #define, dan #endif digunakan untuk mencegah header file diproses berulang kali. struct mahasiswa menyimpan data NIM dalam bentuk array karakter char nim[10] serta dua nilai mahasiswa, yaitu nilai1 dan nilai2, yang bertipe int. Selanjutnya, void inputMhs(mahasiswa &m) mendeklarasikan fungsi untuk memasukkan data mahasiswa, sedangkan float rata2(mahasiswa m) mendeklarasikan fungsi untuk menghitung rata-rata nilai mahasiswa

### 3. Main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata =" << rata2(mhs);
    return 0;
}
```
penjelasan code
Kode main() merupakan program utama yang menjalankan fungsi-fungsi dari mahasiswa.h. Variabel mhs dibuat dengan tipe data mahasiswa, kemudian fungsi inputMhs(mhs) dipanggil untuk memasukkan NIM dan dua nilai mahasiswa. Setelah itu, fungsi rata2(mhs) dipanggil untuk menghitung dan menampilkan nilai rata-rata mahasiswa menggunakan cout. Program diakhiri dengan return 0 yang menandakan program selesai dijalankan.


## Unguided 

### 1. Menyimpan data mahasiswa

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

int main()
{
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> n;
    cin.ignore();

    if (n < 1 || n > 10)
    {
        cout << "Jumlah mahasiswa harus 1 sampai 10!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        getline(cin, mhs[i].nama);

        cout << "NIM   : ";
        getline(cin, mhs[i].nim);

        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;
        cin.ignore();

        mhs[i].nilaiAkhir =
            0.3 * mhs[i].uts +
            0.4 * mhs[i].uas +
            0.3 * mhs[i].tugas;
    }

    cout << "\n========== DATA MAHASISWA ==========\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/DannJB/2311102325_Zidane-Maulana-Fajrian_Strukdat/main/Minggu%204/unguided1/ss-output-unguided1.png)

penjelasan unguided 1
Kode tersebut digunakan untuk menginput dan menampilkan data mahasiswa yang terdiri dari nama, NIM, nilai UTS, UAS, dan tugas menggunakan struct Mahasiswa dan array dengan kapasitas maksimal 10 mahasiswa. Program menghitung nilai akhir setiap mahasiswa menggunakan rumus UTS 30%, UAS 40%, dan tugas 30%. Setelah semua data dimasukkan, program menampilkan kembali seluruh data mahasiswa beserta nilai akhirnya dengan dua angka di belakang koma menggunakan iomanip dan setprecision(2). Berdasarkan output, mahasiswa pertama bernama Dedi memperoleh nilai akhir 83,20, sedangkan mahasiswa kedua bernama Lia memperoleh nilai akhir 80,50.


### 2. Pelajaran

```Pelajaran.h
s#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran
{
    string namapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

```Pelajaran.cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran pel;

    pel.namapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

```Main.cpp
#include <iostream>
#include <string>
#include "pelajaran.h"

using namespace std;

int main()
{
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2](https://raw.githubusercontent.com/DannJB/2311102325_Zidane-Maulana-Fajrian_Strukdat/main/Minggu%204/unguided2/ss-output-unguided2.png)

penjelasan unguided 2
Program ini digunakan untuk membuat dan menampilkan data pelajaran dengan menerapkan konsep Abstract Data Type (ADT) menggunakan struct dan fungsi yang dipisahkan ke dalam file main.cpp, pelajaran.cpp, dan pelajaran.h. Pada pelajaran.h, didefinisikan struktur pelajaran yang memiliki atribut namapel dan kodeMapel, beserta deklarasi fungsi. Pada pelajaran.cpp, fungsi create_pelajaran() digunakan untuk membuat objek pelajaran dan mengisi atributnya, sedangkan tampil_pelajaran() digunakan untuk menampilkan data pelajaran. Sementara itu, main.cpp menentukan nama pelajaran Struktur Data dan kode STD, kemudian memanggil kedua fungsi tersebut. Berdasarkan output, program berhasil menampilkan nama pelajaran Struktur Data dan kode pelajaran STD.


### 3. Program 

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3],
                int baris, int kolom)
{
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{

    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}};

    int x = 100;
    int y = 200;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampilArray(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    cout << "\nNilai sebelum pointer ditukar:" << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "\nNilai setelah pointer ditukar:" << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    return 0;
}
```
### Output Unguided 3 :

![Screenshot Output Unguided 3](https://raw.githubusercontent.com/DannJB/2311102325_Zidane-Maulana-Fajrian_Strukdat/main/Minggu%204/unguided3/ss-output-unguided3.png)

penjelasan unguided 3
Program ini bertujuan untuk menunjukkan proses pertukaran nilai pada array dua dimensi dan pointer dalam C++. Fungsi tampilArray() digunakan untuk menampilkan isi array A dan B berukuran 3×3, sedangkan fungsi tukarArray() menukar elemen pada indeks baris 1 dan kolom 1, yaitu nilai 5 pada array A dengan nilai 50 pada array B. Setelah ditukar, nilai tersebut berubah menjadi 50 pada array A dan 5 pada array B. Selanjutnya, fungsi tukarPointer() menukar nilai variabel yang ditunjuk oleh pointer p1 dan p2, sehingga nilai awal 100 dan 200 berubah menjadi 200 dan 100. Berdasarkan output, program berhasil melakukan pertukaran elemen array dan nilai melalui pointer sesuai dengan yang diharapkan.


## Kesimpulan

Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data dalam C++ dapat digunakan untuk menyimpan, mengelola, dan mengolah data dengan lebih terstruktur. Pada bagian Guided, dipelajari penggunaan struct dan fungsi untuk memasukkan data mahasiswa serta menghitung rata-rata nilai. Pada bagian Unguided, materi tersebut dikembangkan dengan membuat program untuk menyimpan data beberapa mahasiswa dan menghitung nilai akhir, mengelola data pelajaran menggunakan konsep ADT, serta menukar nilai pada array dua dimensi dan pointer. Melalui praktikum ini, pemahaman mengenai penggunaan struct, fungsi, array, dan pointer dalam C++ menjadi lebih baik, serta dapat diterapkan untuk membuat program yang lebih terorganisasi dan mudah dipahami.


## Referensi
[1] Modul 3 ABSTRACT DATA TYPE (ADT) 
