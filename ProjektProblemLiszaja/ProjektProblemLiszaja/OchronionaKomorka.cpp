#include "OchronionaKomorka.h"

OchronionaKomorka::OchronionaKomorka(int czas, char znak, Kolor& k)
{
	czasKomorki = czas;
	znakKomorki = znak;
	kolorKomorki = k.Niebieski();
}

void OchronionaKomorka::WpiszCzasIZnakOchronionejKomorki()
{
	int cK;
	cout << "Podaj jaki znak ma miec ochroniona komorka: ";
	cin >> znakKomorki;
	cout << "Podaj ilosc czasu przez ochroniona komorka ma pozostac: ";
	cin >> cK;
	czasKomorki = abs(cK);
}

int OchronionaKomorka::ZwrocCzasKomorki() const
{
	return czasKomorki;
}

char OchronionaKomorka::ZwrocZnakKomorki() const
{
	return znakKomorki;
}
int OchronionaKomorka::ZwrocKolorKomorki() const
{
	return kolorKomorki;
}
