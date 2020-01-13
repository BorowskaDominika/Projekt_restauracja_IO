#include "pch.h"
#include "CppUnitTest.h"
#include "../Restauracja - zaj2/restauracja.h"
#include "../Restauracja - zaj2/zamowienie.h"
#include "../Restauracja - zaj2/zamowienie.cpp"
#include "../Restauracja - zaj2/restauracja.cpp"
#include "../Restauracja - zaj2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			zamowienie order;
			int licznik = order.suma_liczb_naszego_enuma(); //suma wynosi 28 bo mamy produkty od 0 do 7
			Assert::AreEqual(28, licznik);
			//Assert::AreEqual(1, liczba_zamowien);

		}


		TEST_METHOD(TestMethod3)
		{
			//sprawdzam czy rzeczywiscie jak na razie nie ma zadnych zamowien
			systemZamowien syst;
			//syst.dodajZamowienie(systemZamowien::NaWynos);
			//int licznik= syst.znajdzZamowienieONumerze(0);
			Assert::AreEqual(0, syst.iloscZamowienDzis);

		}

	};
}
