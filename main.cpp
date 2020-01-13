#include <iostream>
#include <vector>
#include "zamowienie.h"
#include "restauracja.h"
#include <string>
#include <limits>

using namespace std;

int main()
{
	cout << "Witaj w restauracji!" << endl
		<< "========================================" << endl
		<< "1. Zloz zamowienie" << endl
		<< "2. Sprawdz dane zamowienia" << endl
		<< "3. Usun zamowienie" << endl
		<< "4. Sprawdz liczbe wolnych miejsc" << endl
		<< "5. Zarezerwuj stoliki" << endl
		<< "6. Sprawdz informacje o stoliku" << endl
		<< "7. Zmien rezerwacje stolika" << endl
		<< "8. Zakoncz rejestracje stolika" << endl
		<< "9. Dokonaj platnosci" <<endl
		<< "0. Zamknij system" << endl
		<< "========================================" << endl << endl;

	//inicializacja zmiennych i obiektow
	bool czySystemDziala = true;
	int wybor;
	systemZamowien syst;
	restauracja rest;

	while (czySystemDziala)
	{

		cout << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			int typZ;
			cout << "Podaj typ zamowienia (1 - na miejscu, 2 - na wynos): ";
			cin >> typZ;
			if (typZ == 1)
			{
				cout << "Numer Twojego zamowienia to: " << syst.dodajZamowienie(systemZamowien::NaMiejscu) << endl;
			}
			else if (typZ == 2)
			{
				cout << "Numer Twojego zamowienia to: " << syst.dodajZamowienie(systemZamowien::NaWynos) << endl;
			}
		}
		break;
		case 2:
		{
			int numZ;
			cout << "Podaj numer zamowienia: ";
			cin >> numZ;
			syst.wypiszDaneZamowienia(numZ);
		}
		break;
		case 3:
		{
			int numZ;
			cout << "Podaj numer zamowienia: ";
			cin >> numZ;
			if (syst.usunZamowienie(numZ)) cout << "Usunieto zamowienie!" << endl;
		}
		break;
		case 4:
		{
			cout << "Ilosc wolnych miejsc: " << rest.sprawdzIloscWolnychMiejsc() << endl;
		}
		break;
		case 5:
		{
			int iloscOsob, godzina = -1;
			string imie;
			cout << "Podaj ilosc miejsc do zarezerwowania: ";
			cin >> iloscOsob;
			do
			{
				cout << "Podaj godzine rezerwacji (miedzy 12 a 22): ";
				cin >> godzina;
				if (godzina < 12 || godzina>22) cout << "Niepoprawna godzina!" << endl;
			} while (godzina < 12 || godzina>22);
			cout << "Podaj imie na ktore ma byc rezerwacja: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, imie);
			rest.zarezerwujStoliki(iloscOsob, imie, godzina);
		}
		break;
		case 6:
		{
			int stolik;
			cout << "Podaj numer stolika: ";
			cin >> stolik;
			rest.sprawdzInfoOStoliku(stolik);
		}
		break;
		case 7:
		{
			int stolik;
			cout << "Podaj numer stolika: ";
			cin >> stolik;
			int godzina = -1;
			string imie;
			do
			{
				cout << "Podaj godzine rezerwacji (miedzy 12 a 22): ";
				cin >> godzina;
				if (godzina < 12 || godzina>22) cout << "Niepoprawna godzina!" << endl;
			} while (godzina < 12 || godzina>22);
			cout << "Podaj imie na ktore ma byc rezerwacja: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, imie);
			rest.zmienDaneRezerwacjiStolika(stolik, imie, godzina);
			cout << "Dane zostaly zmienione" << endl;
		}
		break;
		case 8:
		{
			int stolik;
			cout << "Podaj numer stolika: ";
			cin >> stolik;
			rest.zakonczRezerwacje(stolik);
			cout << "Zakonczono rezerwacje stolika numer " << stolik << endl;
		}
		break;
		case 9:
		{
			syst.wybierz_metode();
		}
		break;
		case 0:
			czySystemDziala = false;
			break;
		default:
			cout << "Zla komenda!" << endl;
			break;
		}
	}
	return 0;
}
