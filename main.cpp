#include <iostream>
#include <vector>
#include "zamowienie.h"
#include "restauracja.h"
#include <string>

using namespace std;

int main()
{
	
	cout << "Witaj w restauracji!" << endl
		<< "========================================" << endl
		<< "1. Zloz zamowienie" << endl
		<< "2. Sprawdz dane zamowienia" << endl
		<< "3. Usun zamowienie" << endl
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
