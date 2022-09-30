#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "duomenys.h"
#include "skaiciuokZodzius.h"

unsigned int skaiciuokZodzius(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}