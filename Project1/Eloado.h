#pragma once
#include <string>
#include <iostream>



/// Zene elõadõjának tárolására
class Eloado
{
    std::string name;
    std::string nationality;

public:
    Eloado( std::string="nincs", std::string="nincs");

   
    std::string getName() const;
    std::string getNationality() const;

    void setName(std::string);
    void setNationality(std::string);
   

};

