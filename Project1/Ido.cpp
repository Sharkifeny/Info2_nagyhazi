#include "Ido.h"


Ido::Ido(unsigned minutes, unsigned seconds): minute(minutes), second(seconds){}



unsigned Ido::getSeconds() const
{
    return second;
}

unsigned Ido::getMinutes() const
{
    return minute;
}

void Ido::setSeconds(unsigned ps)
{
    second=ps;
}

void Ido::setMinutes(unsigned pm)
{
    minute = pm;
}

