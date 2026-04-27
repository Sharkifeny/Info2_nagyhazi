#pragma once
#include <string>
#include <iostream>
#include "Ido.h"
#include "Eloado.h"
#include <iomanip> // A zenehossz kiiratásához



class Zene
{

    Eloado writer;

    /// Zene cim
    std::string name;
    
    /// Felvétel éve
    unsigned recorded;
    
    /// Típus
    std::string genre;
    
    /// Kedvenc-e
    bool liked;
    
    /// Zene hossza perc:másodperc formátumban
    Ido length;
   

public:
    Zene(std::string pName="nincs", std::string pGenre = "nincs",
        unsigned timeMinutes = 0, unsigned timeSeconds = 0, bool pLiked = 0,
        std::string writerName="nincs", std::string writerNationality = "nincs",
        unsigned pRecorded=0);
    
    Zene(const Zene&);

    std::string getName() const;
    

    std::string getGenre() const;
 


    /// Elõadó név szerinti egyezése
    bool operator==(const std::string) const;
    
    /// Az adatok kiírására használatos
    void kiIr(std::ostream& os) const;
    
    /// Az adatok beolvasására használatos
    void beolvas(std::istream& is);
    
};

/// A kapott zene adatait kiírja
std::ostream& operator<<(std::ostream& os, const Zene& right);
