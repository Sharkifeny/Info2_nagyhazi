#pragma once


/// A zenehoszzak eltárolására
class Ido
{
protected:
    unsigned second;
    unsigned minute;
    

public:

    Ido(unsigned=0, unsigned=0);
   

    unsigned getSeconds() const;
    unsigned getMinutes() const;
  
   

    void setSeconds(unsigned);
    void setMinutes(unsigned);
    
};

