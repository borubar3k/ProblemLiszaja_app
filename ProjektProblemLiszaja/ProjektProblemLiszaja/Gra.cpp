#include "Gra.h"

Gra::Gra(Plansza& p)
{
	this->tablica = p.Tablica();
	this->liczbaWierszy = p.LiczbaWierszy();
	this->liczbaKolumn = p.LiczbaKolumn();
}

Gra::~Gra()
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		delete[] tablicaLicznikow[i];
	}
	delete[] tablicaLicznikow;
}

void Gra::InicjowanieTablicyCzasu(Komorka *k)
{
	this->tablicaLicznikow = new int* [liczbaWierszy];
	for (int i = 0; i < liczbaWierszy; i++)
	{
		tablicaLicznikow[i] = new int[liczbaKolumn];
	}
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			tablicaLicznikow[i][j] = k->ZwrocCzasKomorki();
		}
	}
}

void Gra::InicjowanieCzasuZakazonejKomorki(Komorka *k)
{
	tablicaLicznikow[liczbaWierszy / 2][liczbaKolumn / 2] = k->ZwrocCzasKomorki();
}

void Gra::DodajZakazoneKomorki(Komorka *k1,Komorka *k2)
{
	iloscX = 0;

	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			if (tablica[i][j] == k2->ZwrocZnakKomorki())
			{
				iloscX++;
			}
		}
	}
	this->tmp = new int[iloscX * 2];
	int a = 0;
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			if (tablica[i][j] == k2->ZwrocZnakKomorki())
			{
				tmp[a] = i;
				tmp[a + 1] = j;
				//cout << tmp[a] << " " << tmp[a + 1] << endl;
				a += 2;
			}
		}
	}
	for (int a = 0; a <= iloscX * 2; a += 2)
	{
		PrzypiszDoPola(tmp[a] - 1, tmp[a + 1] - 1, k1, k2);
		PrzypiszDoPola(tmp[a] - 1, tmp[a + 1], k1, k2);
		PrzypiszDoPola(tmp[a] - 1, tmp[a + 1] + 1, k1, k2);

		PrzypiszDoPola(tmp[a], tmp[a + 1] - 1, k1, k2);
		PrzypiszDoPola(tmp[a], tmp[a + 1] + 1, k1, k2);

		PrzypiszDoPola(tmp[a] + 1, tmp[a + 1] - 1, k1, k2);
		PrzypiszDoPola(tmp[a] + 1, tmp[a + 1], k1, k2);
		PrzypiszDoPola(tmp[a] + 1, tmp[a + 1] + 1, k1, k2);
	}
	delete[] tmp;
}

void Gra::PrzypiszDoPola(int x,int y, Komorka *k1, Komorka *k2)
{
	if (x >= 0 && x < liczbaWierszy && y >= 0 && y < liczbaKolumn && tablica[x][y] == k1->ZwrocZnakKomorki())
	{
		if (LosowanieLiczby() % 2 == 0)
		{
			tablica[x][y] = k2->ZwrocZnakKomorki();
			tablicaLicznikow[x][y] = k2->ZwrocCzasKomorki();
		}
		else
		{
			tablica[x][y] = k1->ZwrocZnakKomorki();
			tablicaLicznikow[x][y] = k1->ZwrocCzasKomorki();
		}
	}
}

void Gra::ZmianaPolTablic(Komorka *k1, Komorka *k2, Komorka *k3)
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			if (tablicaLicznikow[i][j] > 0)
			{
				tablicaLicznikow[i][j]--;
				if (tablica[i][j] == k2->ZwrocZnakKomorki() && tablicaLicznikow[i][j] == 0)
				{
					tablica[i][j] = k3->ZwrocZnakKomorki();
					tablicaLicznikow[i][j] = k3->ZwrocCzasKomorki();
				}
				else if (tablica[i][j] == k3->ZwrocZnakKomorki() && tablicaLicznikow[i][j] == 0)
				{
					tablica[i][j] = k1->ZwrocZnakKomorki();
					tablicaLicznikow[i][j] = k1->ZwrocCzasKomorki();
				}
			}

			
		}
	}
}

void Gra::WypiszTabliceCzasu()
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			cout << tablicaLicznikow[i][j] << " ";
		}
		cout << endl;
	}
}

bool Gra::SprawdzCzyTablicaZawieraWartosci(char x)
{
	for (int i = 0; i < liczbaWierszy; i++)
	{
		for (int j = 0; j < liczbaKolumn; j++)
		{
			if (tablica[i][j] != x)
			{
				return false;
			}
		}
	}
	return true;
}

int Gra::LosowanieLiczby()
{
	random_device rd;
	mt19937 gen(rd());

	// Utworzenie rozk³adu równomiernego dla liczb ca³kowitych
	uniform_int_distribution<> distrib(1, 10);//rozklad rownomierny
	int losowaLiczba = distrib(gen);
	return losowaLiczba;
}