#ifndef CARGO_H
#define CARGO_H
#include <string.h>
#include "luggage.h"


class cargo : public luggage
{
public:
    cargo();
    cargo(const string &owner, const string &dest, const int &weight, const int &volume);
    cargo(const cargo &other);

    int get_volume() const;
    void set_volume(const int& value);

private:
    int volume;

};

#endif // CARGO_H
