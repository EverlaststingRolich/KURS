#ifndef LUGGAGE_H
#define LUGGAGE_H

#include <iostream>
#include <string>

using namespace std;

class luggage
{
public:
    int price;
    luggage();
    luggage(string owner, string dest, int weight);
    luggage(const luggage& other);

    const string& get_owner() const;
    const string& get_dest() const;
    int get_weight() const;
    int get_price() const;

    virtual string get_data(const string& type) const;

    void set_owner(const string& value);
    void set_dest(const string& value);
    void set_weight(const int& value);
    void set_price(const int& value);

private:
    string owner;
    string dest;
    int weight;

};

#endif // LUGGAGE_H
