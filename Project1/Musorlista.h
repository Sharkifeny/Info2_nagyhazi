#pragma once
#include "Zene.h"
#include "tarolo.h"
#include <fstream>



class Musorlista
{
protected:
    Tarolo<Zene> playList;

public:
    /// konstruktor, itt történik a fájlból beolvasás
    Musorlista(); 
    
    /// Üresség vizsgálata
    bool empty() const;
    
    /// Zene hozzáadása
    void addMusic(const Zene&);


    /// A tömb  méretének lekérdezése
    unsigned getSize() const;

    /// Zene visszaadása
    Zene& operator[](unsigned index) const;

    /// Zene törlése cím szerint
    void deleteMusic();
    
    /// Keresés a mûsorlistában
    void eloadoKeres() const;
    void cimKeres() const;
    void mufajKeres() const;

    /// Itt történik a fájlba mentés is
    ~Musorlista();
};

/// Mûsorlista kiírása 
std::ostream& operator<<(std::ostream& os, Musorlista& m);
/// Mûsorlista beolvasása fájlba
std::istream& operator>>(std::istream& is, Zene& z);