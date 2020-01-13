#include "pch.h"
#include "CppUnitTest.h"
#include "../Restauracja_zaj1/restauracja.h"
#include "../Restauracja_zaj1/zamowienie.h"
#include "../Restauracja_zaj1/zamowienie.cpp"
#include "../Restauracja_zaj1/restauracja.cpp"
#include "../Restauracja_zaj1/main.cpp"

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
	};
}
