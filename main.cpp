#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ncurses/curses.h>
#include <windows.h> 
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

void conquerTugas(const vector<Tugas>& input, vector<Tugas>& hasil) {
    hasil = input;
    sort(hasil.begin(), hasil.end(), [](const Tugas& a, const Tugas& b) {
        if (a.hariMenujuDeadline != b.hariMenujuDeadline)
            return a.hariMenujuDeadline < b.hariMenujuDeadline;
        return a.prioritas < b.prioritas;
    });
}


void mainmenu() {
    mvprintw(11, 55, "Menu Utama");
    mvprintw(13, 52, "1. Lihat tugas");
    mvprintw(14, 52, "2. Masukkan tugas baru");
    mvprintw(15, 52, "3. Keluar");
    mvprintw(16, 52, "Pilih Opsi :");
    refresh();
}

int main() {
	initscr();           
    start_color();          
    init_pair(1, COLOR_WHITE, COLOR_WHITE);

    char nama[50], pilihan;
    
	mvprintw(12, 44, "Selamat datang di tracker tugas");
    mvprintw(14, 50, "Masukkan nama anda");
    mvprintw(15, 50, "Username :");

    refresh();

    move(15, 61);
    echo();
    getstr(nama);

    clear();
    char pesan[100];
	sprintf(pesan, "Selamat datang, %s", nama);
	mvprintw(15, 50, pesan);	
    refresh();
    Sleep(1000);
	clear();

	do {
		clear();
    	mainmenu();
		move(16, 65);
    	pilihan = getch(); 
	
		switch (pilihan) {
			case '1':
				clear();
				mvprintw(12, 50, ">> Lihat tugas");
				getch();
				break;

			case '2':
				clear();
				mvprintw(12, 50, ">> Masukkan tugas baru");
				getch();
				break;

			case '3':
				clear();
				mvprintw(15, 50, "Keluar dari program...");
				refresh();
				Sleep(1000);
				break;

			default:
				mvprintw(18, 52, "Input salah. Coba lagi!");
				refresh();
				Sleep(1000);
				break;
				}
			} while (pilihan != '3');

		endwin();
		 
	return 0;
}

