#include "zamowienie.h"
#include <string>

using namespace std;


void zamowienie::wypiszTrescZamowienia()
{
	int kwota=0;
	for (int i = 0; i < trescZamowienia.size(); i++)
	{
		if (i != 0) cout << ", ";
		switch (trescZamowienia[i])
		{
		case Burger:
			cout << "Burger";
			kwota += 10;
			break;
		case Pierogi:
			cout << "Pierogi ruskie";
			kwota += 10;
			break;
		case Spaghetti:
			cout << "Spaghetti Bologneise";
			kwota += 10;
			break;
		case Bigos:
			cout << "Bigos";
			kwota += 10;
			break;
		case Cola:
			cout << "Cola";
			kwota += 10;
			break;
		case Woda:
			cout << "Woda";
			kwota += 10;
			break;
		case Kompot:
			cout << "Kompot sliwkowy";
			kwota += 5;
			break;
		case Piwo:
			cout << "Piwo";
			kwota += 10;
			break;
		}
	}

	cout << "\nKwota zamowienia wynosi: " << kwota <<" zl"<< endl;
}
zamowienie::zamowienie(int numer)
{
	this->numer = numer;
	cout << "MENU:" << endl
		<< "1. Burger - 10zl" << endl
		<< "2. Pierogi ruskie - 10zl" << endl
		<< "3. Spaghetti Bologneise - 10zl" << endl
		<< "4. Bigos - 10zl" << endl
		<< "5. Cola - 10zl" << endl
		<< "6. Woda - 10z;" << endl
		<< "7. Kompot sliwkowy - 5zl" << endl
		<< "8. Piwo - 10zl" << endl
		<< "0. Zakoncz zamowienie" << endl
		<< "Podaj tresc swojego zamowienia: ";
	int zam;
	while (cin >> zam)
	{
		if (zam <= 0 || zam > 8) break;
		trescZamowienia.push_back(static_cast<MENU>(zam - 1));
	}
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

int zamowienie::suma_liczb_naszego_enuma()
{
	return MENU(Burger) + MENU(Pierogi) + MENU(Spaghetti) + MENU(Bigos) + MENU(Cola) + MENU(Woda) + MENU(Kompot) + MENU(Piwo); //wykorzystujemy sk³adniki enuma, bez inicjalizacji przyk³adowej zmiennej
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

zamowienieNaMiejscu::zamowienieNaMiejscu(int numer, int stolik) : zamowienie(numer)
{
	this->stolik = stolik;
}
void zamowienieNaMiejscu::wypiszDaneZamowienia()
{
	cout << "Numer: " << numer << endl
		<< "Stolik: " << stolik << endl;
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
		cout << "Podaj numer stolika: ";
		int numer;
		cin >> numer;
		tablica.push_back(new zamowienieNaMiejscu(iloscZamowienDzis, numer));
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

void karta::wypisz_potwierdzenie()
{
	cout << "Platnosc karta zostala przyjeta!";
	cout << endl;
}

void blik::wypisz_potwierdzenie()
{

	cout << "Platnosc Blikiem zostala przyjeta!";
	cout << endl;
}

void gotowka::wypisz_potwierdzenie()
{

	cout << "Platnosc gotowka zostala przyjeta!";
	cout << endl;
}

void systemZamowien::wybierz_metode()
{
	cout << "Wybierz metode platnosci za zamowienie: " << endl;
	cout << " \n 1 - platnosc karta \n 2 - platnosc Blikiem \n 3 - platnosc gotowka" << endl;
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		
		int numer;
		cout << "Wybrano platnosc karta!" << endl;
		cout << "Podaj numer swojego zamowienia: " << endl;
		cin >> numer;
		int nr = znajdzZamowienieONumerze(numer);
		if (nr < 0)
		{
			cout << "Nie ma zamowienia o takim numerze!" << endl;
		}
		else
		{
			wypiszDaneZamowienia(numer);
			cout << "Platnosc powiodla sie!" << endl;
			usunZamowienie(numer);
			
		}
	}
	break;
	case 2:
	{
		int numer;
		cout << "Wybrano platnosc Blikiem!" << endl;
		cout << "Podaj numer swojego zamowienia: " << endl;
		cin >> numer;
		int nr = znajdzZamowienieONumerze(numer);
		if (nr < 0)
		{
			cout << "Nie ma zamowienia o takim numerze!" << endl;
		}
		else
		{
			wypiszDaneZamowienia(numer);
			cout << " Platnosc powiodla sie!" << endl;
			usunZamowienie(numer);
		}
	}
	break;
	case 3:
	{
		int numer;
		cout << "Wybrano platnosc gotowka!" << endl;
		cout << " Podaj numer swojego zamowienia: " << endl;
		cin >> numer;
		int nr = znajdzZamowienieONumerze(numer);
		if (nr < 0)
		{
			cout << "Nie ma zamowienia o takim numerze!" << endl;
		}
		else
		{
			wypiszDaneZamowienia(numer);
			cout << " Platnosc powiodla sie!" << endl;
			usunZamowienie(numer);
		}
		
	}
	break;
	}
}