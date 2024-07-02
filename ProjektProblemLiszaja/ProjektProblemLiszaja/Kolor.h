#pragma once
#include <iostream>
#include <windows.h>
#include "Komorka.h"

using namespace std;

class Kolor
{
	int kolor;
public:
	void UstawKolor(int kol);
	void OznaczeniaKolorow();

	int Czerwony();
	int Zielony();
	int Niebieski();
	int Domyslny();

};

