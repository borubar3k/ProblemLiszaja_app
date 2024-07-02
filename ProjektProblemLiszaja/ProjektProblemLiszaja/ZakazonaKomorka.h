#pragma once
#include "Komorka.h"
#include "Kolor.h"
class ZakazonaKomorka :public Komorka
{
	int czasKomorki;
	char znakKomorki;
	int kolorKomorki;
public:
	ZakazonaKomorka(int czas, char znak, Kolor& k);
	virtual void WpiszCzasIZnakZakazonejKomorki();
	virtual int ZwrocCzasKomorki() const;
	virtual char ZwrocZnakKomorki() const;
	virtual int ZwrocKolorKomorki() const;
};

