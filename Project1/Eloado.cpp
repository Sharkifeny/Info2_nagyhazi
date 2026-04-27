#include "Eloado.h"




Eloado::Eloado(std::string name, std::string nationality): name(name), nationality(nationality){}




std::string Eloado::getName() const
{
    return name;
}


std::string Eloado::getNationality() const
{
    return nationality;
}


void Eloado::setName(std::string pName) 
{
    name = pName;
}


void Eloado::setNationality(std::string pNationality)
{
    nationality = pNationality;
}