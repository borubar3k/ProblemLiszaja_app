#pragma once
#include "Kolor.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

class Czas
{
	int krok;
	chrono::seconds interval;
public:
	Czas(int sek);
	void WpiszCzasUspienia();
	void WypiszAktualnyKrok();
	void KomunikatNaKoniecSymulacji(Kolor& k);
	void CzasUspienia();
};

