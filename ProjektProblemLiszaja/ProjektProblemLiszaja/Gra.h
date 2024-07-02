#pragma once
#include "Plansza.h"
#include <windows.h>
#include <iostream>
#include "Komorka.h"
#include "ZdrowaKomorka.h"
#include "ZakazonaKomorka.h"
#include <random>

using namespace std;

class Gra
{
	char** tablica;
	int liczbaWierszy;
	int liczbaKolumn;

	int iloscX;
	int* tmp;

	int** tablicaLicznikow;
public:
	Gra(Plansza& p);
	~Gra();

	void InicjowanieTablicyCzasu(Komorka* k);
	void InicjowanieCzasuZakazonejKomorki(Komorka* k);
	void DodajZakazoneKomorki(Komorka *k1, Komorka *k2);
	void PrzypiszDoPola(int x, int y, Komorka* k1, Komorka* k2);
	void ZmianaPolTablic(Komorka *k1, Komorka *k2, Komorka *k3);
	void WypiszTabliceCzasu();

	bool SprawdzCzyTablicaZawieraWartosci(char x);
	int LosowanieLiczby();

};

