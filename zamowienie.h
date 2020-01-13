#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class zamowienie
{
protected:
	int numer;
	enum MENU { Burger, Pierogi, Spaghetti, Bigos, Cola, Woda, Kompot, Piwo };
	vector <MENU> trescZamowienia;
	void wypiszTrescZamowienia();
	friend class systemZamowien;
public:
	zamowienie();
	int suma_liczb_naszego_enuma();
	zamowienie(int numer);
	operator int() { return numer; }
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
	int stolik;
public:
	zamowienieNaMiejscu(int numer, int stolik);
	void wypiszDaneZamowienia();
};

class systemZamowien
{
	vector<zamowienie*> tablica;
	
public:
	int znajdzZamowienieONumerze(int numer);
	int iloscZamowienDzis;
	enum typZamowienia { NaWynos, NaMiejscu };
	systemZamowien();
	~systemZamowien();
	int dodajZamowienie(typZamowienia typ);
	bool usunZamowienie(int numer);
	void wypiszDaneZamowienia(int numer);
	void wybierz_metode(); //do platnosci
protected:
	int kwota; //do platnosci
	int id_platnosci; //do platnosci
};

class karta : public systemZamowien
{
public:
	void wypisz_potwierdzenie();
};

class blik : public systemZamowien
{
public:
	void wypisz_potwierdzenie();
};

class gotowka : public systemZamowien
{
public:
	void wypisz_potwierdzenie();
};

#endif // ZAMOWIENIE_H


