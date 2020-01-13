#ifndef RESTAURACJA_H
#define RESTAURACJA_H

#include <iostream>
#include <vector>

using namespace std;

class restauracja
{
	class stolik
	{
		bool zarezerwowany;
		string dane_klienta;
		int godzina;
		int liczbaMiejsc;
	public:
		stolik(int liczbaMiejsc);
		void zarezerwuj(string imie, int godzina);
		void zakonczRezerwacje();
		void zmienRezerwacje(string imie, int godzina);
		bool czyZarezerwowany() { return zarezerwowany; }
		int sprawdzLiczbeMiejsc() { return liczbaMiejsc; }
		string sprawdzImieRezerwacji() { return dane_klienta; }
		int sprawdzGodzineRezerwacji() { return godzina; }
	};
	vector <stolik> tablicaStolikow;
public:
	restauracja();
	int sprawdzIloscWolnychMiejsc();
	bool zarezerwujStoliki(int iloscMiejsc, string imie, int godzina);
	void sprawdzInfoOStoliku(int stolik);
	void zmienDaneRezerwacjiStolika(int stolik, string imie, int godzina) { tablicaStolikow[stolik].zmienRezerwacje(imie, godzina); }
	void zakonczRezerwacje(int stolik) { tablicaStolikow[stolik].zakonczRezerwacje(); }
};

#endif // RESTAURACJA_H
