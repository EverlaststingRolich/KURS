#include "collection.h"
#include <iostream>
#include <fstream>
#include <string.h>

collection::collection()
{
    this->field = nullptr;
    this->size = 0;
}

collection::collection(const collection& other)
{

    if(other.field)
    {
        this->field = new luggage*[other.size];
        this->size = other.size;
        for(int i = 0; i < this->size; i++)
            this->field[i] = other.field[i];
    }
    else
    {
        this->field = nullptr;
        this->size = 0;
    }
}

int collection::add_elem(luggage &ob)
{
    if (this->field && this->get_size() != 0)
        {
            if ((ob.get_weight() != 0))
            {
                this->size++;
                luggage **pc = new luggage*[this->size];
                for(int i = 0; i < this->size - 1; i++)
                    pc[i] = this->field[i];
                delete [] this->field;
                pc[this->size - 1] = &ob;
                this->field = pc;
            }
        }
        else
        {
            this->size++;
            luggage **pc = new luggage*[this->size];
            pc[this->size - 1] = &ob;
            this->field = pc;
        }
        return 1;
}

int collection::get_size()
{
    return this->size;
}

int collection::clear()
{
    if (this->field)
        {
            delete [] this->field;
            this->field = nullptr;
            this->size = 0;
        }
        return 1;
}

collection::~collection()
{
    this->size = 0;
    delete [] this->field;
    this->field = nullptr;
}
