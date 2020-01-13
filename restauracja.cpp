#include "restauracja.h"

using namespace std;

restauracja::stolik::stolik(int liczbaMiejsc)
{
	zarezerwowany = false;
	dane_klienta = "";
	this->liczbaMiejsc = liczbaMiejsc;
}

void restauracja::stolik::zarezerwuj(string imie, int godzina)
{
	this->dane_klienta = imie;
	this->godzina = godzina;
	zarezerwowany = true;
}
void restauracja::stolik::zakonczRezerwacje()
{
	dane_klienta = "";
	zarezerwowany = false;
}
void restauracja::stolik::zmienRezerwacje(string imie, int godzina)
{
	this->dane_klienta = imie;
	this->godzina = godzina;
}

restauracja::restauracja()
{
	for (int i = 0; i < 5; i++)
	{
		tablicaStolikow.push_back(stolik(6));
		tablicaStolikow.push_back(stolik(4));
		tablicaStolikow.push_back(stolik(3));
		tablicaStolikow.push_back(stolik(3));
		tablicaStolikow.push_back(stolik(2));
		tablicaStolikow.push_back(stolik(2));
	}
}
int restauracja::sprawdzIloscWolnychMiejsc()
{
	int liczba = 0;
	for (int i = 0; i < tablicaStolikow.size(); i++)
	{
		if (!tablicaStolikow[i].czyZarezerwowany()) liczba += tablicaStolikow[i].sprawdzLiczbeMiejsc();
	}
	return liczba;
}
bool restauracja::zarezerwujStoliki(int iloscMiejsc, string imie, int godzina)
{
	if (sprawdzIloscWolnychMiejsc() < iloscMiejsc) { cout << "Nie mamy wystarczajaco wolnych miejsc!" << endl; return false; }
	bool zarezerwowano = false;
	switch (iloscMiejsc)
	{
	case 2:
		for (int i = 0; i < tablicaStolikow.size(); i++)
		{
			if (!tablicaStolikow[i].czyZarezerwowany())
			{
				if (tablicaStolikow[i].sprawdzLiczbeMiejsc() == 2)
				{
					tablicaStolikow[i].zarezerwuj(imie, godzina);
					cout << "Zarezerwowano stolik numer " << i << endl;
					zarezerwowano = true;
					break;
				}
			}
		}
		if (zarezerwowano) break;
	case 3:
		for (int i = 0; i < tablicaStolikow.size(); i++)
		{
			if (!tablicaStolikow[i].czyZarezerwowany())
			{
				if (tablicaStolikow[i].sprawdzLiczbeMiejsc() == 3)
				{
					tablicaStolikow[i].zarezerwuj(imie, godzina);
					cout << "Zarezerwowano stolik numer " << i << endl;
					zarezerwowano = true;
					break;
				}
			}
		}
		if (zarezerwowano) break;
	case 4:
		for (int i = 0; i < tablicaStolikow.size(); i++)
		{
			if (!tablicaStolikow[i].czyZarezerwowany())
			{
				if (tablicaStolikow[i].sprawdzLiczbeMiejsc() == 4)
				{
					tablicaStolikow[i].zarezerwuj(imie, godzina);
					cout << "Zarezerwowano stolik numer " << i << endl;
					zarezerwowano = true;
					break;
				}
			}
		}
		if (zarezerwowano) break;
	case 5:
	case 6:
		for (int i = 0; i < tablicaStolikow.size(); i++)
		{
			if (!tablicaStolikow[i].czyZarezerwowany())
			{
				if (tablicaStolikow[i].sprawdzLiczbeMiejsc() == 6)
				{
					tablicaStolikow[i].zarezerwuj(imie, godzina);
					cout << "Zarezerwowano stolik numer " << i << endl;
					zarezerwowano = true;
					break;
				}
			}
		}
		if (zarezerwowano) break;
	default:
		cout << "zarezerwowano stoliki numer ";
		for (int i = 0; i < tablicaStolikow.size(); i++)
		{
			if (!tablicaStolikow[i].czyZarezerwowany())
			{
				cout << i;
				tablicaStolikow[i].zarezerwuj(imie, godzina);
				iloscMiejsc -= tablicaStolikow[i].sprawdzLiczbeMiejsc();
				if (iloscMiejsc <= 0) { cout << endl; break; }
				cout << ", ";
			}
		}
	}
	return true;
}
void restauracja::sprawdzInfoOStoliku(int stolik)
{
	if (tablicaStolikow[stolik].czyZarezerwowany())
	{
		cout << "Stolik numer " << stolik << " ma " << tablicaStolikow[stolik].sprawdzLiczbeMiejsc() << " miejsc i posiada rezerwacje na imie " << tablicaStolikow[stolik].sprawdzImieRezerwacji() << " na godzine " << tablicaStolikow[stolik].sprawdzGodzineRezerwacji() << "." << endl;
	}
	else
	{
		cout << "Stolik numer " << stolik << " ma " << tablicaStolikow[stolik].sprawdzLiczbeMiejsc() << " miejsc i nie jest zarezerwowany." << endl;
	}
}
