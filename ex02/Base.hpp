#ifndef BASE_HPP_
#define BASE_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base *generate(void);   //It randomly instantiates A, B, or C 
void identify(Base* p); //It prints the actual type of the object pointed to by p: "A", "B", or "C"
void identify(Base& p); //It prints the actual type of the object referenced by p: "A", "B", or "C".

#endif