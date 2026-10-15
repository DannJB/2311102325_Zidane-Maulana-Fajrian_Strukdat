# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Zidane Maulana Fajrian - 2311102325</p>

## Dasar Teori
Singly Linked List adalah struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Setiap node menyimpan data dan memiliki pointer next untuk menghubungkannya dengan node berikutnya. Node pertama ditunjuk oleh first, sedangkan node terakhir menunjuk ke NULL. Struktur data ini bersifat dinamis sehingga data dapat ditambahkan atau dihapus sesuai kebutuhan. Operasi yang dapat dilakukan pada Singly Linked List meliputi penambahan, penghapusan, penampilan, pencarian, dan perubahan data.[1]

## Guided 

### 1. List.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct LinkedList
{
    address first;
};

bool isEmpty(LinkedList List);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);
void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address nodePrev);
int nbList(LinkedList List);
void deleteList(LinkedList &List);

#endif
```
Penjelasan singkat guided 1 : Kode tersebut merupakan deklarasi struktur data Linked List untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, dan umur. Setiap node memiliki data mahasiswa dan pointer next yang menghubungkannya dengan node berikutnya. Struktur LinkedList menggunakan pointer first untuk menunjuk node pertama. Selain itu, terdapat beberapa fungsi untuk membuat list, mengecek apakah list kosong, mengalokasikan dan membebaskan memori, menampilkan data, menambahkan dan menghapus node di awal, tengah, maupun akhir, menghitung jumlah node, serta menghapus seluruh isi list.

### 2. List.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(LinkedList List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(LinkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    if (node != Nil)
    {
        node->next = Nil;
        delete node;
        node = Nil;
    }
}

void insertFirst(LinkedList &List, address nodeBaru)
{
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev)
{
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(LinkedList &List)
{
    address nodeHapus;

    if (!isEmpty(List))
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List)
{
    address nodeHapus, nodePrev;

    if (!isEmpty(List))
    {
        nodeHapus = List.first;

        if (nodeHapus->next == Nil)
        {
            List.first = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(LinkedList List)
{
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;

        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(LinkedList List)
{
    int count = 0;
    address nodeBantu = List.first;

    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

void deleteList(LinkedList &List)
{
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;

    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
Penjelasan singkat guided 2 : Kode tersebut merupakan implementasi fungsi-fungsi untuk mengelola data mahasiswa menggunakan struktur data Linked List. Fungsi yang tersedia meliputi pembuatan list, pengecekan list kosong, pembuatan dan penghapusan node, serta penambahan data di awal, tengah, dan akhir list. Selain itu, terdapat fungsi untuk menghapus node, menampilkan data mahasiswa, menghitung jumlah node, dan menghapus seluruh isi list. Dengan fungsi-fungsi tersebut, pengelolaan data mahasiswa dapat dilakukan secara dinamis sesuai kebutuhan.

### 3. Main.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DIHAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Penjelasan singkat guided 3 : Program ini digunakan untuk menguji operasi Linked List, mulai dari pembuatan list menggunakan createList(), penambahan lima data mahasiswa dengan fungsi insertFirst(), insertLast(), dan insertAfter(), hingga menampilkan isi list dan jumlah node menggunakan printList() dan nbList(). Selanjutnya, program melakukan penghapusan node menggunakan delFirst(), delLast(), dan delAfter(), kemudian menghapus seluruh isi list dengan deleteList(). Setiap tahap menampilkan isi dan jumlah node untuk mengetahui perubahan data pada Linked List.


## Unguided 

### 1. Singly Linked List dengan Operasi insertFirst()

### Code unguided 1(singlylist.h)
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### Code unguided 1(singlylist.cpp)
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = nullptr;
}

void printInfo(List L)
{
    address P = L.First;

    while (P != nullptr)
    {
        cout << P->info;

        if (P->next != nullptr)
        {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.First;
    L.First = P;
}
```

### Code unguided 1(main.cpp)
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main()
{
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1](https://raw.githubusercontent.com/DannJB/2311102325_Zidane-Maulana-Fajrian_Strukdat/main/Minggu%205/unguided/unguided1/unguided-1.png)


Penjelasan unguided 1 : Program dibuat untuk menerapkan struktur data Singly Linked List menggunakan tiga file, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp. Program dimulai dengan membuat list kosong, kemudian memasukkan lima data, yaitu 2, 0, 8, 12, dan 9. Setiap data dimasukkan ke bagian awal list menggunakan fungsi insertFirst(), sehingga urutan datanya menjadi 9, 12, 8, 0, dan 2. Setelah itu, fungsi printInfo() digunakan untuk menampilkan seluruh data yang tersimpan di dalam list.


### 2. Operasi Penghapusan Node pada Singly Linked List

### Code unguided 2(singlylist.h)
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

### Code unguided 2(singlylist.cpp)
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = nullptr;
}

void printInfo(List L)
{
    address P = L.First;

    while (P != nullptr)
    {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P)
{
    if (L.First != nullptr)
    {
        P = L.First;
        L.First = L.First->next;
        P->next = nullptr;
    }
    else
    {
        P = nullptr;
    }
}

void deleteLast(List &L, address &P)
{
    if (L.First == nullptr)
    {
        P = nullptr;
    }
    else if (L.First->next == nullptr)
    {
        P = L.First;
        L.First = nullptr;
    }
    else
    {
        address Q = L.First;

        while (Q->next->next != nullptr)
        {
            Q = Q->next;
        }

        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    if (Prec != nullptr && Prec->next != nullptr)
    {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
    else
    {
        P = nullptr;
    }
}

int nbList(List L)
{
    int jumlah = 0;
    address P = L.First;

    while (P != nullptr)
    {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L)
{
    address P;

    while (L.First != nullptr)
    {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

### Code unguided 2(main.cpp)
```C++
source code unguided 2(main.cpp)
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main()
{
    List L;
    address P1, P2, P3, P4, P5, Prec;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, P1);
    dealokasi(P1);

    deleteLast(L, P2);
    dealokasi(P2);

    Prec = L.First;

    while (Prec != nullptr && Prec->info != 12)
    {
        Prec = Prec->next;
    }

    if (Prec != nullptr)
    {
        deleteAfter(L, Prec, P3);
        dealokasi(P3);
    }

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);

    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2](https://raw.githubusercontent.com/DannJB/2311102325_Zidane-Maulana-Fajrian_Strukdat/main/Minggu%205/unguided/unguided2/unguided-2.png)


Penjelasan unguided 2 : Program melanjutkan kode sebelumnya dengan menambahkan beberapa fungsi untuk menghapus node. Fungsi deleteFirst() digunakan untuk menghapus data 9 di awal list, deleteLast() untuk menghapus data 2 di akhir list, dan deleteAfter() untuk menghapus data 8 yang berada setelah node 12. Setelah ketiga penghapusan dilakukan, tersisa data 12 dan 0. Fungsi nbList() kemudian menghitung jumlah node yang tersisa, yaitu 2, sedangkan deleteList() digunakan untuk menghapus semua node hingga list kosong dan jumlah node menjadi 0.


## Kesimpulan
...

## Referensi
[1] Modul 4 SINGLY LINKED LIST (BAGIAN PERTAMA)
