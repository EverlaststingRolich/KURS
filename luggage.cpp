#include "luggage.h"
#include <iostream>
#include <string>

using namespace std;

luggage::luggage()
{
    this->owner = "";
    this->dest = "";
    this->weight = 0;
    this->price = 0;
}

int find_price(int weight)
{
    int price = 0;
    if (weight <= 50)
        price = price + (weight/10) + 1;
    else
        if (weight > 50)
            price = price + (2*(weight/10)) + 1;
    return price;
}

luggage::luggage(string owner, string dest, int weight)
{
    this->owner = std::move(owner);
    this->dest = std::move(dest);
    if (weight > 0)
        this->weight = weight;
    else
        this->weight = 1;
    this->price = find_price(weight);
}

luggage::luggage(const luggage& other)
{
    this->owner = other.owner;
    this->dest = other.dest;
    this->weight = other.weight;
    this->price = other.price;
}

const string &luggage::get_owner() const
{
    return this->owner;
}

const string &luggage::get_dest() const
{
    return this->dest;
}

int luggage::get_weight() const
{
    return this->weight;
}

int luggage::get_price() const
{
    return this->price;
}

void luggage::set_owner(const string& value)
{
    this->owner = std::move(value);
}

void luggage::set_dest(const string& value)
{
    this->dest = std::move(value);
}

void luggage::set_weight(const int& value)
{
    if (value > 0)
        this->weight = value;
    else
        this->weight = 1;
}

void luggage::set_price(const int& value)
{
    this->price = value;
}
