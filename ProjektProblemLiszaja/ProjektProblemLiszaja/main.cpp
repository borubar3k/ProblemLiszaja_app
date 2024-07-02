#include "Plansza.h"
#include "Czas.h"
#include <iostream>
#include "Gra.h"
#include "Kolor.h"
#include "Komorka.h"
#include "ZdrowaKomorka.h"
#include "ZakazonaKomorka.h"
#include "OchronionaKomorka.h"

using namespace std;

int main()
{
	Plansza tablica = Plansza();
	Czas czas(1);
	Kolor kol;
	ZdrowaKomorka zdrKom('Z',kol);
	ZakazonaKomorka zakKom(6, 'X', kol);
	OchronionaKomorka ochrKom(4, 'O',kol);

	char znakEdycji;
	cout << "Czy chcesz edytowac poczatkowe wartosci przed rozpoczeciem symulacji? (y/n): ";
	do {
		cin >> znakEdycji;
	} while (znakEdycji == 'y' && znakEdycji == 'n');
	if (znakEdycji == 'y')
	{
		tablica.WpiszWymiaryTablicy();
		czas.WpiszCzasUspienia();
		zdrKom.WpiszZnakKomorki();
		zakKom.WpiszCzasIZnakZakazonejKomorki();
		ochrKom.WpiszCzasIZnakOchronionejKomorki();
	}
	else
	{
		cout << "Wartosci ustawione zostana automatycznie" << endl;
	}

	Gra gra(tablica);
	Komorka* komorkaWsk1;
	komorkaWsk1 = &zdrKom;
	Komorka* komorkaWsk2;
	komorkaWsk2 = &zakKom;
	Komorka* komorkaWsk3;
	komorkaWsk3 = &ochrKom;

	tablica.InicjowanieTablicyKomorek(komorkaWsk1);
	tablica.InicjowanieZakazonejKomorki(komorkaWsk2);
	gra.InicjowanieTablicyCzasu(komorkaWsk1);
	gra.InicjowanieCzasuZakazonejKomorki(komorkaWsk2);

	int opcjaWyswietlania = 0;
	cout << "Opcje wyswietlania:" << endl << "   (1) symulacja automatyczna" << endl << "   (2) sterowanie przy pomocy <Enter>" << endl;
	do {
		cin >> opcjaWyswietlania;
	} while (opcjaWyswietlania != 1 && opcjaWyswietlania != 2);

	switch (opcjaWyswietlania)
	{
	case 1:
		while (true)
		{
			if (gra.SprawdzCzyTablicaZawieraWartosci(komorkaWsk1->ZwrocZnakKomorki()) || gra.SprawdzCzyTablicaZawieraWartosci(komorkaWsk2->ZwrocZnakKomorki()))
			{
				tablica.WypiszTabliceKomorek(komorkaWsk1, komorkaWsk2, komorkaWsk3, kol);
				czas.KomunikatNaKoniecSymulacji(kol);
				czas.CzasUspienia();
				break;
			}
			kol.OznaczeniaKolorow();
			czas.WypiszAktualnyKrok();
			tablica.WypiszTabliceKomorek(komorkaWsk1,komorkaWsk2, komorkaWsk3, kol);
			gra.DodajZakazoneKomorki(komorkaWsk1,komorkaWsk2);
			gra.ZmianaPolTablic(komorkaWsk1,komorkaWsk2,komorkaWsk3);
			czas.CzasUspienia();
		}
		break;

	case 2:
		while (true)
		{
			cin.get();
			if (gra.SprawdzCzyTablicaZawieraWartosci(komorkaWsk1->ZwrocZnakKomorki()) || gra.SprawdzCzyTablicaZawieraWartosci(komorkaWsk2->ZwrocZnakKomorki()))
			{
				tablica.WypiszTabliceKomorek(komorkaWsk1, komorkaWsk2, komorkaWsk3, kol);
				czas.KomunikatNaKoniecSymulacji(kol);
				break;
			}
			kol.OznaczeniaKolorow();
			czas.WypiszAktualnyKrok();
			tablica.WypiszTabliceKomorek(komorkaWsk1, komorkaWsk2, komorkaWsk3, kol);
			gra.DodajZakazoneKomorki(komorkaWsk1,komorkaWsk2);
			gra.ZmianaPolTablic(komorkaWsk1, komorkaWsk2, komorkaWsk3);
			//gra.WypiszTabliceCzasu();
		}
		break;
	}
	return 0;
}