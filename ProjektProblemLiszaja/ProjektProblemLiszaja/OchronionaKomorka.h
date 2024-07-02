#pragma once
#include "Komorka.h"
#include "Kolor.h"
class OchronionaKomorka :public Komorka
{
	int czasKomorki;
	char znakKomorki;
	int kolorKomorki;
public:
	OchronionaKomorka(int czas, char znak, Kolor& k);
	virtual void WpiszCzasIZnakOchronionejKomorki();
	virtual int ZwrocCzasKomorki() const;
	virtual char ZwrocZnakKomorki() const;
	virtual int ZwrocKolorKomorki() const;
};

