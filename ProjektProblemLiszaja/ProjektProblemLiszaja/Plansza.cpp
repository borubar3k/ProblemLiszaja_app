  #include "Plansza.h"

Plansza::Plansza(int wiersze, int kolumny) : liczbaWierszy(wiersze), liczbaKolumn(kolumny)
{
	this->tablica = new char* [liczbaWierszy];
	for (int i = 0; i < liczbaWierszy; i++)
	{
		tablica[i] = new char[liczbaKolumn];
	}
}

Plansza::~Plansza()
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		delete[] tablica[i];
	}
	delete[] tablica;
}

void Plansza::WpiszWymiaryTablicy()
{
	int lW, lK;
	cout << "Podaj nowe wymiary tablicy komorek (wiersze kolumny): ";
	cin >> lW >> lK;
	liczbaWierszy = abs(lW);
	liczbaKolumn = abs(lK);
}

int Plansza::LiczbaWierszy() const
{
	return liczbaWierszy;
}

int Plansza::LiczbaKolumn() const
{
	return liczbaKolumn;
}

char** Plansza::Tablica() const
{
	return this->tablica;
}

void Plansza::InicjowanieTablicyKomorek(Komorka *k)
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			tablica[i][j] = k->ZwrocZnakKomorki();
		}
	}
}

void Plansza::InicjowanieZakazonejKomorki(Komorka* k)
{
	tablica[liczbaWierszy / 2][liczbaKolumn / 2] = k->ZwrocZnakKomorki();
}

void Plansza::WypiszTabliceKomorek(Komorka *k1, Komorka *k2, Komorka *k3, Kolor& k)
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			if (tablica[i][j] == k1->ZwrocZnakKomorki())
			{
				k.UstawKolor(k1->ZwrocKolorKomorki());
				cout << tablica[i][j] << " ";
			}
			else if (tablica[i][j] == k2->ZwrocZnakKomorki())
			{
				k.UstawKolor(k2->ZwrocKolorKomorki());
				cout << tablica[i][j] << " ";
			}
			else if (tablica[i][j] == k3->ZwrocZnakKomorki())
			{
				k.UstawKolor(k3->ZwrocKolorKomorki());
				cout << tablica[i][j] << " ";
			}
			else
			{
				k.UstawKolor(k.Domyslny());
			}
		}
		cout << endl;
	}
	cout << endl;
}