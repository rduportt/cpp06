#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdint.h>
#include <iostream>

typedef struct Data
{
    int serial_number;
}Data;

class Serializer
{
    private:
        Serializer();
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif