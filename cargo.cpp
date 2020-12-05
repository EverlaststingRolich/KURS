#include "cargo.h"
#include <ctype.h>
#include <string.h>


cargo::cargo()
{
    this->volume = 0;
}

int find_price(int volume, int weight)
{
   int price = 0;
   price = price + (weight/10) + 2 + (volume/10);
   return price;
}


cargo::cargo(const string &owner, const string &dest, const int &weight, const int &volume):luggage(owner, dest, weight)
{
    if (volume > 0)
        this->volume = volume;
    else
        this->volume = 1;
    this->price = find_price(volume, weight);
}


cargo::cargo(const cargo &other):luggage(other)
{
    this->volume = other.volume;
}


int cargo::get_volume() const
{
    return this->volume;
}

void cargo::set_volume(const int &value)
{
    if (value >= 0)
        this->volume = value;
    else
        this->volume = 1;
}
