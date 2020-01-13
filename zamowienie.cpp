#include "zamowienie.h"
#include <string>

using namespace std;


void zamowienie::wypiszTrescZamowienia()
{
	for (int i = 0; i < trescZamowienia.size(); i++)
	{
		if (i != 0) cout << ", ";
		switch (trescZamowienia[i])
		{
		case Burger:
			cout << "Burger";
			break;
		case Pierogi:
			cout << "Pierogi ruskie";
			break;
		case Spaghetti:
			cout << "Spaghetti Bologneise";
			break;
		case Bigos:
			cout << "Bigos";
			break;
		case Cola:
			cout << "Cola";
			break;
		case Woda:
			cout << "Woda";
			break;
		case Kompot:
			cout << "Kompot sliwkowy";
			break;
		case Piwo:
			cout << "Piwo";
			break;
		}
	}
}
zamowienie::zamowienie(int numer)
{
	this->numer = numer;
	cout << "MENU:" << endl
		<< "1. Burger" << endl
		<< "2. Pierogi ruskie" << endl
		<< "3. Spaghetti Bologneise" << endl
		<< "4. Bigos" << endl
		<< "5. Cola" << endl
		<< "6. Woda" << endl
		<< "7. Kompot sliwkowy" << endl
		<< "8. Piwo" << endl
		<< "0. Zakoncz zamowienie" << endl
		<< "Podaj tresc swojego zamowienia: ";
	int zam;
	while (cin >> zam)
	{
		if (zam <= 0 || zam > 8) break;
		trescZamowienia.push_back(static_cast<MENU>(zam - 1));
	}
}

int zamowienie::suma_liczb_naszego_enuma()
{
	return MENU(Burger) + MENU(Pierogi) + MENU(Spaghetti) + MENU(Bigos) +MENU(Cola) +MENU(Woda) + MENU(Kompot) +MENU(Piwo); //wykorzystujemy sk³adniki enuma, bez inicjalizacji przyk³adowej zmiennej
}

zamowienie::zamowienie()
{
	
}

void zamowienie::wypiszDaneZamowienia()
{
	cout << "Numer: " << numer << endl;
	cout << "Rzeczy zamowione: ";
	wypiszTrescZamowienia();
	cout << endl;
}

zamowienieNaWynos::zamowienieNaWynos(int numer, string adres) : zamowienie(numer)
{
	this->adres = adres;
}
void zamowienieNaWynos::wypiszDaneZamowienia()
{
	cout << "Numer: " << numer << endl
		<< "Adres: " << adres << endl;
	cout << "Rzeczy zamowione: ";
	wypiszTrescZamowienia();
	cout << endl;
}

zamowienieNaMiejscu::zamowienieNaMiejscu(int numer) : zamowienie(numer)
{

}
void zamowienieNaMiejscu::wypiszDaneZamowienia()
{
	cout << "Numer: " << numer << endl;
	cout << "Rzeczy zamowione: ";
	wypiszTrescZamowienia();
	cout << endl;
}

int systemZamowien::znajdzZamowienieONumerze(int numer)
{
	for (int i = 0; i < tablica.size(); i++)
	{
		if (*tablica[i] == numer) return i;
	}
	return -1;
}
systemZamowien::systemZamowien()
{
	iloscZamowienDzis = 0;
}
systemZamowien::~systemZamowien()
{
	for (int i = 0; i < tablica.size(); i++)
	{
		delete(tablica[i]);
		tablica.clear();
	}
}
int systemZamowien::dodajZamowienie(typZamowienia typ)
{
	switch (typ)
	{
	case NaWynos:
	{
		cout << "Podaj adres dostawy: ";
		string adres;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, adres);
		tablica.push_back(new zamowienieNaWynos(iloscZamowienDzis, adres));
	}
	break;
	case NaMiejscu:
	{
		tablica.push_back(new zamowienieNaMiejscu(iloscZamowienDzis));
	}
	break;
	default:
		cout << "Zly typ zamowienia!" << endl;
		break;
	}
	iloscZamowienDzis++;
	return iloscZamowienDzis - 1;
}
bool systemZamowien::usunZamowienie(int numer)
{
	int nrZam = znajdzZamowienieONumerze(numer);
	if (nrZam < 0)
	{
		cout << "Nie ma zamowienia o takim numerze!" << endl;
		return false;
	}
	else
	{
		delete(tablica[nrZam]);
		tablica.erase(tablica.begin() + nrZam);
		return true;
	}
}
void systemZamowien::wypiszDaneZamowienia(int numer)
{
	int nrZam = znajdzZamowienieONumerze(numer);
	if (nrZam < 0)
	{
		cout << "Nie ma zamowienia o takim numerze!" << endl;
	}
	else
	{
		tablica[nrZam]->wypiszDaneZamowienia();
	}
}
