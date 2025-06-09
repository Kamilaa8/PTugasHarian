#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah tugas: " << endl;
    cin >> n;
    cin.ignore(); 
    vector<string> urgent, medium, low;

    for (int i = 0; i < n; ++i) {
        string nama;
        int hari;

        cout << "Tugas ke-" << i + 1 << endl;
        cout << "Nama tugas: " << endl;
        getline(cin, nama);
        cout << "Berapa hari lagi menuju deadline? " << endl;
        cin >> hari;
        cin.ignore();

      
        if (hari <= 2) {
            urgent.push_back(nama);
        } else if (hari <= 5) {
            medium.push_back(nama);
        } else {
            low.push_back(nama);
        }
    }


    cout << "Hasil Pembagian Tugas Berdasarkan Urgensi" << endl;

    cout << "Urgent - ≤ 2 hari" << endl;
    for (string& t : urgent) {
        cout << "- " << t << endl;
    }

    cout << "[Medium - 3 sampai 5 hari]" << endl;
    for (string& t : medium) {
        cout << "- " << t << endl;
    }

    cout << "[Low - > 5 hari]" << endl;
    for (string& t : low) {
        cout << "- " << t << endl;
    }
    
    return 0;
}

