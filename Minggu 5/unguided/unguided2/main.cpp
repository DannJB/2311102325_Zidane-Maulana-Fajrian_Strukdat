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