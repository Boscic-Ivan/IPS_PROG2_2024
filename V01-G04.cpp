#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include "biblioteka_vrijeme.cc"
using namespace std;

void polje() {
	char polje[5][20] = {"prozor", "svjetiljka", "televizor", "olovka", "monitor"};
	
	for (int i = 0; i < 5; i++)
		cout << polje[i] << endl;
	
	cout << endl;
}

float funkcija(float a, float b) {
	if (a <= 0 || b <= 0)
		return -1;
	
	return ((a*b)/2); 
}

struct autor {
	int s_autora;
	char prezime_ime[240];
	float p_ocjena;
};

void struktura() {
	autor org;
	org.s_autora = 421;
	strcpy(org.prezime_ime, "Matic Melita");
	org.p_ocjena = 4.43;
	
	autor kop;
	
	memcpy(&kop, &org, sizeof(autor));
	
	cout << "Sifra autora: " << kop.s_autora << endl;
	cout << "Prezime i ime autora: " << kop.prezime_ime << endl;
	cout << "Prosjecna ocjena autora: " << kop.p_ocjena << endl;
	cout << endl;
}

void m_vremena() {
	float a, b, c, s, s1, s2, s3, povrsina;
	do {
		vrijeme_pocetak();
		cout << "Unesite stranicu a: ";
		cin >> a;
		cout << "Unesite stranicu b: ";
		cin >> b;
		cout << "Unesite stranicu c: ";
		cin >> c;
		vrijeme_kraj();
		cout << "Vrijeme trajanja unosa: " << (int)vrijeme_proteklo()/10 << " stotinki" << endl;
		s = (a+b+c)/2;
		s1 = s-a;
		s2 = s-b;
		s3 = s-c;
		povrsina = sqrt((s*s1*s2*s3) < 0 ? (s*s1*s2*s3)*-1 : (s*s1*s2*s3));
		if (a+b > c && a+c > b && b+c > a) {
			cout << "Povrsina trokuta je: " << setprecision(2) << povrsina << endl;
		} else {
			cout << "Nemoguce izracunati povrsinu, unesite ponovo!" << endl;
		}
		
	} while(!(a+b > c && a+c > b && b+c > a));
	cout << endl;
}

int main(){
	int br;
	do {
		cout << "1. Polje" << endl;
		cout << "2. Funkcija" << endl;
		cout << "3. Struktura" << endl;
		cout << "4. Mjerenje vremena" << endl;
		cout << "9. Izlaz iz programa" << endl;
		
		cout << "Unesite broj: ";
		cin >> br;
		
		switch(br) {
			case 1: polje(); break;
			case 2:
				float a, b;
				cout << "Unesite duzinu stranice a: "; cin >> a;
				cout << "Unesite duzinu stranice b: "; cin >> b;
				float rez;
				rez = funkcija(a, b);
				
				if (rez < 0) {
					cout << "Nije moguce izracunati povrsinu" << endl;
				} 
				else {
					cout << "Povrsina je: " << rez << endl;
				}

				cout << endl;
				break;

			case 3: struktura(); break;
			case 4: m_vremena(); break;
			case 9:
				break;
			default:
				cout << "Unijeli ste pogresan broj!" << endl;
		}
	} while(br != 9);
	
	system("PAUSE");
	return 0;
}
