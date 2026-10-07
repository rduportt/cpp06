#include "Serializer.hpp"

int main()
{
    Data data;
    Data *ptr = &data;
    uintptr_t ptrr;
    ptr->serial_number = 100;
    std::cout << "Before serialize:" << std::endl;
    std::cout << "ptr address: " << ptr << std::endl;
    std::cout << "ptr->serial_number: " << ptr->serial_number << std::endl << std::endl;
    
    ptrr = Serializer::serialize(ptr);
    std::cout << "After serialize:" << std::endl;
    std::cout << "ptrr value (decimal value of the hexadecimal adress of ptr): " << ptrr << std::endl << std::endl;
    
    ptr = Serializer::deserialize(ptrr);
    std::cout << "After deserialize:" << std::endl;
    std::cout << "ptr address: " << ptr << std::endl;
    std::cout << "ptr->serial_number: " << ptr->serial_number << std::endl;
}