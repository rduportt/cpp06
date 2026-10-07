#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <cmath>


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}

void ScalarConverter::convert(std::string string)
{
    char    tochar;
    int     toint;
    float   tofloat;
    double  todouble;
    long double tolongdouble;

    //check if is "a, b, c, etc...."    
    if (string.length() == 1 && !std::isdigit(string[0]))
    {
        char character = string[0];

        std::cout << "char : '" << character << "'" << std::endl;
        std::cout << "int : " << static_cast<int>(character) << std::endl;
        std::cout << "float : " << static_cast<float>(character) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(character) << ".0" << std::endl;
        return;
    }
    int i = check_number(string);
    int j = i;

    if (i == -1)
    {
        std::cout << "char : Wrong syntax" << std::endl
        << "int : Wrong syntax" << std::endl
        << "float : Wrong syntax" << std::endl
        << "double : Wrong syntax" << std::endl;
        return ;
    }


    tolongdouble = strtold(string.c_str(), NULL);
    todouble = static_cast<double>(tolongdouble);
    tochar = static_cast<char>(tolongdouble);
    toint = static_cast<int>(tolongdouble);
    tofloat = static_cast<float>(tolongdouble);

    if (i == -2)
        std::cout << "char : impossible" << std::endl;
    else if(toint < 150 && toint > 0)
    {
        if (std::isprint(toint))
            std::cout << "char : '" << tochar << "'" << std::endl;
        else
            std::cout << "char : Non displayable" << std::endl;
    }
    else
        std::cout << "char : Non displayable" << std::endl;
    if(i == -2)
        std::cout << "int : impossible" << std::endl;
    else if(tolongdouble > std::numeric_limits<int>::max() || tolongdouble < std::numeric_limits<int>::min())
        std::cout << "int : Overflow" << std::endl;
    else
        std::cout << "int : " << toint << std::endl;

    if ((tolongdouble > std::numeric_limits<float>::max() || tolongdouble < -std::numeric_limits<float>::max()) && j != -2)
        std::cout << "float : Overflow" << std::endl;
    else if (j == 0)
        std::cout << "float : " << tofloat << ".0f" << std::endl;
    else
        std::cout << "float : " << tofloat << "f" << std::endl;

    if ((tolongdouble > std::numeric_limits<double>::max() || tolongdouble < -std::numeric_limits<double>::max()) && j != -2)
        std::cout << "double : Overflow" << std::endl;
    else if (j == 0)
        std::cout << "double : " << todouble << ".0" << std::endl;
    else
        std::cout << "double : " << todouble << std::endl;
}

int check_number(std::string string)
{
    bool has_decimal = false;
    int i = 0;
    int j = 0;
    //int k = 0;
    if (string == "nan" || string == "nanf" || string == "+inf" || string == "-inf" || string == "-inff" || string == "+inff")
        return(-2);

    while (static_cast<unsigned long>(i) < string.length())
    {
    if (string[i] == '-' && i == 0)
    {
        i++;
        if (i == static_cast<int>(string.length()))
            return (-1);
    }

    if (string[i] == '.')
    {
        if (has_decimal || i == 0
            || static_cast<unsigned long>(i) == string.length() - 1)
            return (-1);
        has_decimal = true;
    }
    else if (string[i] == 'f')
    {
        if (i != static_cast<int>(string.length()) - 1 || !has_decimal)
            return (-1);
        break;
    }
    else if (!std::isdigit(string[i]))
        return (-1);
    else if (has_decimal && string[i] != '0')
        j = 1;

    i++;
    }
    return j;
}
