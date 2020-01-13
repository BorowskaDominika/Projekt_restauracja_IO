#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class zamowienie
{
protected:
	int numer; //inaczej ID_zamowienia
	enum MENU { Burger, Pierogi, Spaghetti, Bigos, Cola, Woda, Kompot, Piwo }; //danie + dodac ceny
	vector <MENU> trescZamowienia; //inaczej opis_zamowienia
	void wypiszTrescZamowienia(); //wypiszTresc()
	friend class systemZamowien; //zaprzyjazniona klasa system zamowieñ
public:
	int suma_liczb_naszego_enuma();
	zamowienie();
	zamowienie(int numer); //konstruktor
	operator int() { return numer; } //operator
	virtual void wypiszDaneZamowienia(); 
};

class zamowienieNaWynos : public zamowienie
{
	string adres;
public:
	zamowienieNaWynos(int numer, string adres);
	void wypiszDaneZamowienia();
};

class zamowienieNaMiejscu : public zamowienie
{
public:
	zamowienieNaMiejscu(int numer);
	void wypiszDaneZamowienia();
};

class systemZamowien
{
	vector<zamowienie*> tablica;
	int znajdzZamowienieONumerze(int numer);
public:
	int iloscZamowienDzis;
	enum typZamowienia { NaWynos, NaMiejscu };
	systemZamowien();
	~systemZamowien();
	int dodajZamowienie(typZamowienia typ);
	bool usunZamowienie(int numer);
	void wypiszDaneZamowienia(int numer);
};

#endif // ZAMOWIENIE_H
