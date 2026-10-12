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