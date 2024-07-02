#include "ZdrowaKomorka.h"

ZdrowaKomorka::ZdrowaKomorka(char znak,Kolor& k): czasKomorki(0)
{
	znakKomorki = znak;
	kolorKomorki = k.Zielony();
}

void ZdrowaKomorka::WpiszZnakKomorki()
{
	cout << "Podaj jaki znak ma miec zdrowa komorka: ";
	cin >> znakKomorki;
}

int ZdrowaKomorka::ZwrocCzasKomorki() const
{
	return czasKomorki;
}

char ZdrowaKomorka::ZwrocZnakKomorki() const
{
	return znakKomorki;
}
int ZdrowaKomorka::ZwrocKolorKomorki() const
{
	return kolorKomorki;
}
