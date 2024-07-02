#pragma once
#include "Kolor.h"
#include <iostream>
#include "Komorka.h"

using namespace std;

class Plansza
{
	int liczbaWierszy;
	int liczbaKolumn;
	char** tablica;

public:
	Plansza(int wiersze=11, int kolumny=11);
	~Plansza();
	void WpiszWymiaryTablicy();

	int LiczbaWierszy()const;
	int LiczbaKolumn() const;
	char** Tablica() const;

	void InicjowanieZakazonejKomorki(Komorka *k);
	void InicjowanieTablicyKomorek(Komorka *k);
	void WypiszTabliceKomorek(Komorka *k1, Komorka *k2, Komorka *k3, Kolor& k);
};