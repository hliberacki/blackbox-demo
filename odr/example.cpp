#define private public
#define protected public
#include "json_parser.hpp"
#undef private
#undef protected

#include <iostream>

int main()
{
    JsonParser parser(R"({"key": "value"})");
    std::cout << parser.get_string("key") << std::endl;
    std::cout << parser.data_["key"] << std::endl;
}