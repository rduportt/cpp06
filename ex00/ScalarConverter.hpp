#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    public:
        static void convert(std::string string);
};

int check_number(std::string string);

#endif