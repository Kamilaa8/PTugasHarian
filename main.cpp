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
    int durasi;
};

vector<Tugas> divideInput(int jumlah) {
    vector<Tugas> daftarTugas;
    char buffer[100];

    for (int i = 0; i < jumlah; i++) {
        clear();
        mvprintw(10, 52, "Masukkan data tugas ke-%d", i + 1);

        mvprintw(12, 40, "Nama tugas: ");
        echo();
        move(12, 52);
        getstr(buffer);
        noecho();
        string nama(buffer);

        mvprintw(14, 40, "Jumlah hari menuju deadline: ");
        echo();
        move(14, 69);
        getstr(buffer);
        noecho();
        int deadline = atoi(buffer);

        mvprintw(16, 40, "Prioritas (1 = tinggi, 2 = sedang, 3 = rendah): ");
        echo();
        move(16, 88);
        getstr(buffer);
        noecho();
        int prioritas = atoi(buffer);

        mvprintw(18, 40, "Durasi (jam): ");
        echo();
        move(18, 54);
        getstr(buffer);
        noecho();
        int durasi = atoi(buffer);

        Tugas t = {nama, deadline, prioritas, durasi};
        daftarTugas.push_back(t);

        mvprintw(20, 40, "Tugas berhasil dimasukkan!");
        refresh();
        Sleep(1000);
    }

    return daftarTugas;
}

void conquerTugas(const vector<Tugas>& input, vector<Tugas>& hasil) {
    hasil = input;
    sort(hasil.begin(), hasil.end(), [](const Tugas& a, const Tugas& b) {
        if (a.hariMenujuDeadline != b.hariMenujuDeadline)
            return a.hariMenujuDeadline < b.hariMenujuDeadline;
        return a.prioritas < b.prioritas;
    });
}

vector<Tugas> combineGreedy(const vector<Tugas>& tugasTerurut, int waktuTersedia) {
	vector<Tugas> hasil;
	int totalWaktu = 0;
	
	for (const Tugas& t : tugasTerurut) {
		if (totalWaktu + t.durasi <= waktuTersedia) {
			hasil.push_back(t);
			totalWaktu += t.durasi;
		}
	}
	return hasil;
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
	mvprintw(13, 50, pesan);	
	refresh();
	Sleep(1000);
	clear();

	do {
		clear();
		mainmenu();
		move(16, 65);
		pilihan = getch(); 
		
		switch (pilihan) {
			case '1': {
				clear();
				mvprintw(10, 34, ">> Daftar tugas yang diurutkan:");
				conquerTugas(daftarTugas, tugasTerurut);
				int y = 12;
				for (const Tugas& t : tugasTerurut) {
					mvprintw(y++, 34, "Tugas: %s | Deadline: %d hari | Prioritas: %d | Durasi: %d jam",
						t.nama.c_str(), t.hariMenujuDeadline, t.prioritas, t.durasi);
				}
			}
			
			case '2': {
				
			}

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

