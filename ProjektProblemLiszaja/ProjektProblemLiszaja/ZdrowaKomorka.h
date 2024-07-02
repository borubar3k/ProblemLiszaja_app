#pragma once
#include "Komorka.h"
#include "Kolor.h"
class ZdrowaKomorka :public Komorka
{
	const int czasKomorki;
	char znakKomorki;
	int kolorKomorki;
public:
	ZdrowaKomorka(char znak, Kolor& k);
	virtual void WpiszZnakKomorki();
	virtual int ZwrocCzasKomorki() const;
	virtual char ZwrocZnakKomorki() const;
	virtual int ZwrocKolorKomorki() const;
};

