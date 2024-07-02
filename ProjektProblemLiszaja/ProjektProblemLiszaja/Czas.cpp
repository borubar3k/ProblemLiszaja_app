#include "Czas.h"

Czas::Czas(int sek): krok(1), interval(sek) {}

void Czas::WpiszCzasUspienia()
{
    cout << "Podaj nowy czas uspienia pomiedzy kolejnymi krokami w symulacji (sek): ";
    chrono::seconds::rep sek;
    cin >> sek;
    interval = chrono::seconds(sek);
}

void Czas::WypiszAktualnyKrok()
{
    cout << "                                                  Krok: " << krok << endl;
    krok++;
}

void Czas::KomunikatNaKoniecSymulacji(Kolor& k)
{
    k.UstawKolor(k.Domyslny());
    cout << "Symulacja zakonczyla sie po " << krok << " krokach!" << endl;
}

void Czas::CzasUspienia()
{
    this_thread::sleep_for(interval);
}

