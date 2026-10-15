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