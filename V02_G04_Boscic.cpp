#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

struct Inventar {
	int sifra;
	char naziv[100];
	int komad;
	Inventar* sljedeci = NULL;
};



void unos(Inventar* lista) 
{
	Inventar* tekuci = lista;

	while (tekuci->sljedeci != NULL)
		tekuci = tekuci->sljedeci;

	tekuci->sljedeci = new Inventar;
	tekuci = tekuci->sljedeci;

	cout << "Unesite sifru inventara: "; cin >> tekuci->sifra;
	cout << "Unesite naziv inventara: "; cin >> tekuci->naziv;
	cout << "Unesite broj komada: "; cin >> tekuci->komad;
}

void ispis(Inventar* lista) 
{
	Inventar* tekuci = lista;
	int sum = 0;
	
	while (tekuci->sljedeci != NULL)
	{
		tekuci = tekuci->sljedeci;
		sum += tekuci->sifra;

		cout << "Sifra inventara: " << tekuci->sifra << endl;
		cout << "Naziv inventara: " << tekuci->naziv << endl;
		cout << "Broj komada: " << tekuci->komad << endl;
		cout << "Vrijednost pokazivaca sljedeci: " << tekuci->sljedeci << endl;
		cout << endl;
	}

	cout << "Suma primarnih kljuceva (sifri) iznosi: " << sum << endl;
}

void trazi(Inventar* lista) 
{
	int pk;
	cout << "Primarni kljuc elementa (sifra inventara): ";
	cin >> pk;

	bool pronadjen = false;
	Inventar* tekuci = lista;

	while (tekuci->sljedeci != NULL) 
	{
		tekuci = tekuci->sljedeci;

		if (tekuci->sifra == pk) {
			pronadjen = true;
			break;
		}
	}

	if (pronadjen) {
		cout << "Sifra inventara: " << tekuci->sifra << endl;
		cout << "Naziv inventara: " << tekuci->naziv << endl;
		cout << "Broj komada: " << tekuci->komad << endl;
		cout << "Vrijednost pokazivaca sljedeci: " << tekuci->sljedeci << endl;
		cout << endl;
	}
	else cout << "Element s tim primarnim kljucem ne postoji!" << endl;
}

void brisi(Inventar* lista) 
{
	int pk;
	cout << "Primarni kljuc elementa (sifra inventara): ";
	cin >> pk;

	bool pronadjen = false;
	Inventar* tekuci = lista;
	Inventar* prethodni = NULL;

	while (tekuci->sljedeci != NULL) 
	{
		prethodni = tekuci;
		tekuci = tekuci->sljedeci;

		if (tekuci->sifra == pk) {
			pronadjen = true;
			break;
		}
	}

	if (pronadjen) {
		prethodni->sljedeci = tekuci->sljedeci;
		delete tekuci;
		cout << "Element sa kljucem " << pk << " izbrisan!" << endl;
	}
	else cout << "Element sa tim kljucem ne postoji!" << endl;
}



int main() 
{
	Inventar* glava = new Inventar;

	int izbor;
	do {
		cout << "Unesite izbor:" << endl;
		cout << "1. Unos novog elementa vezane liste" << endl;
		cout << "2. Ispis sadrzaja vezane liste" << endl;
		cout << "3. Pretrazivanje vezane liste" << endl;
		cout << "4. Brisanje elementa iz liste" << endl;
		cout << "9. Izlaz iz programa" << endl;

		cin >> izbor;
		cout << endl;

		switch (izbor) {
			case 1: unos(glava); break;
			case 2: ispis(glava); break;
			case 3: trazi(glava); break;
			case 4: brisi(glava); break;
			case 9: cout << "Izlazim..."; break;
			default: cout << "Pogresan unos!" << endl; break;
		}
		cout << endl;
	} while (izbor != 9);

	system("PAUSE");
	return 0;
}
