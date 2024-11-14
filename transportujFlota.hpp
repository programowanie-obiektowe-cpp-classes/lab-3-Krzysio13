#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar) {
    if (towar == 0) {
        return 0;  // Jeżeli towar == 0, nie tworzymy żadnych statków
    }

    unsigned int totalTransported = 0;  // Suma przetransportowanego towaru
    unsigned int numberOfZaglowce = 0;  // Liczba żaglowców
    Stocznia stocznia;  // Fabryka statków

    while (totalTransported < towar) {
        Statek* statek = stocznia();  // Tworzymy nowy statek
        unsigned int transported = statek->transportuj();  // Transportujemy towar
        
        totalTransported += transported;  // Dodajemy do sumy
        if (dynamic_cast<Zaglowiec*>(statek)) {
            numberOfZaglowce++;  // Jeżeli statek jest żaglowcem, inkrementujemy licznik
        }

        delete statek;  // Usuwamy statek po użyciu
    }

    return numberOfZaglowce;  // Zwracamy liczbę żaglowców
}
