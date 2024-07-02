#include "ZakazonaKomorka.h"

ZakazonaKomorka::ZakazonaKomorka(int czas, char znak, Kolor& k)
{
	czasKomorki = czas;
	znakKomorki = znak;
	kolorKomorki = k.Czerwony();
}

void ZakazonaKomorka::WpiszCzasIZnakZakazonejKomorki()
{
	int cK;
	cout << "Podaj jaki znak ma miec zakazona komorka: ";
	cin >> znakKomorki;
	cout << "Podaj ilosc czasu przez zakazona komorka ma pozostac: ";
	cin >> cK;
	czasKomorki = abs(cK);
}


int ZakazonaKomorka::ZwrocCzasKomorki() const
{
	return czasKomorki;
}

char ZakazonaKomorka::ZwrocZnakKomorki() const
{
	return znakKomorki;
}
int ZakazonaKomorka::ZwrocKolorKomorki() const
{
	return kolorKomorki;
}
