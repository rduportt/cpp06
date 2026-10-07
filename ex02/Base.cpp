#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    Base *baseptr;
    std::srand(std::time(0));
    int i = rand() % 3;

    if (i == 0)
    {
        baseptr = new A();
    }
    else if (i == 1)
    {
        baseptr = new B();
    }
    else
    {
        baseptr = new C();
    }

    return (baseptr);
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "*p : Object is A" << std::endl;
    if(dynamic_cast<B*>(p) != NULL)
        std::cout << "*p : Object is B" << std::endl;
    if(dynamic_cast<C*>(p) != NULL)
        std::cout << "*p : Object is C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)(a);
        std::cout << "&p : Object is A" << std::endl;
        return ;
    }
    catch (const std::exception &exp)
    {
    }

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)(b);
        std::cout << "&p : Object is B" << std::endl;
        return ;
    }
    catch (const std::exception &exp)
    {
    }

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)(c);
        std::cout << "&p : Object is C" << std::endl;
        return ;
    }
    catch (const std::exception &exp)
    {
    }
}