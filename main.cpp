#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Tugas {
    string nama;
    int hariMenujuDeadline;
    int prioritas;
};

vector<Tugas> divideInput(int jumlah) {
    vector<Tugas> daftarTugas;
    cin.ignore(); 
    for (int i = 0; i < jumlah; i++) {
        Tugas t;
        cout << "\nMasukkan nama tugas ke-" << i + 1 << ": ";
        getline(cin, t.nama);

        cout << "Masukkan jumlah hari menuju deadline: ";
        cin >> t.hariMenujuDeadline;

        cout << "Masukkan prioritas (1 = tinggi, 2 = sedang, 3 = rendah): ";
        cin >> t.prioritas;
        cin.ignore();

        daftarTugas.push_back(t);
    }
    return daftarTugas;
}


