#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include  "luggage.h"
using namespace std;

class collection
{
public:
    collection();
    collection(const collection& other);

    int add_elem(luggage &ob);
    int get_size();
    int clear();
    int remove(int num);

    ~collection();
    luggage** get_iterator() const {return this->field;}

    int from_file(const string &name);
    int to_file(const string &name);


private:
    luggage **field{nullptr};
    int size;
};

#endif // COLLECTION_H
