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

    ~collection();
    luggage** get_iterator() const {return this->field;}


private:
    luggage **field{nullptr};
    int size;
};

#endif // COLLECTION_H
