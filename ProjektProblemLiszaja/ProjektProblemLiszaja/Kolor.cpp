#include "Kolor.h"

void Kolor::UstawKolor(int kol)
{
    HANDLE uchwytKonsoli = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(uchwytKonsoli, kol);
}

void Kolor::OznaczeniaKolorow()
{
    UstawKolor(Domyslny());
    cout << "   GRA SYMULACYJNA - PROBLEM LISZAJA" << endl;

    UstawKolor(Zielony());
    cout << "                                   Komorka zdrowa" << endl;

    UstawKolor(Czerwony());
    cout << "                                   Komorka zakazona" << endl;

    UstawKolor(Niebieski());
    cout << "                                   Komorka chroniona" << endl;

    UstawKolor(Domyslny());
}

int Kolor::Czerwony()
{
    kolor = FOREGROUND_RED;
    return kolor;
}

int Kolor::Zielony()
{
    kolor = FOREGROUND_GREEN;
    return kolor;
}

int Kolor::Niebieski()
{
    kolor = FOREGROUND_BLUE;
    return kolor;
}

int Kolor::Domyslny()
{
    kolor = (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return kolor;
}

