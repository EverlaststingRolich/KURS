#include "collection.h"
#include "cargo.h"
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

int collection::remove(int numb)
{
    if (this->size > 0 && this->size > numb)
    {
        if (numb == 0)
        {
            if (this->size > 1)
            {
                this->size--;
                luggage **pc = new luggage*[this->size];
                for(int i = 0; i < this->size; i++)
                    pc[i] = this->field[i+1];
                delete [] this->field;
                this->field = pc;
            }
            else
            {
                this->size = 0;
                this->field = nullptr;
            }
        }
        else    
        {
            if (numb + 1 == this->size)
            {
                this->size--;
                luggage **pc = new luggage*[this->size];
                for(int i = 0; i < this->size; i++)
                    pc[i] = this->field[i];
                delete [] this->field;
                this->field = pc;
            }
            else
            {
                int def = this->size;
                this->size--;
                luggage **pc = new luggage*[this->size];
                for(int i = 0; i < numb; i++)
                    pc[i] = this->field[i];

                for(int i = numb+1; i < def; i++)
                    pc[i-1] = this->field[i];

                delete [] this->field;
                this->field = pc;
            }
        }
    }
    return 1;
}


collection::~collection()
{
    this->size = 0;
    delete [] this->field;
    this->field = nullptr;
}

int collection::to_file(const string &fname)
{
    ofstream fout(fname);
    for(int i = 0;i < this->size;i++)
    {
        fout << "#" << i+1 << endl;
        fout << this->field[i]->get_data("owner")<< endl;
        fout << this->field[i]->get_data("dest") << endl;
        fout << this->field[i]->get_data("weight") << endl;
        fout << this->field[i]->get_data("volume") << endl;
        fout << this->field[i]->get_data("price") << endl;
    }
    fout.close();
    return 1;
}

int collection::from_file(const string &fname)
{
    string owner;
    string dest;
    int weight;
    int volume;

    ifstream file(fname);
    if(this->field)
    {
        delete [] this->field;
        this->field = nullptr;
        this->field = 0;
    }

    if (file.is_open())
    {
        while(!file.eof())
        {
            file >> owner;
            file >> dest;
            file >> weight;
            file >> volume;

            auto ca = new cargo(owner, dest, weight, volume);
            if (((ca->get_weight()) > 0) && ((ca->get_volume()) > 0))
                this->add_elem(*ca);
        }
        file.close();
    }
    return 1;
}
