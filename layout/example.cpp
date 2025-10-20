#ifdef TEST_ACCESS_PRIVATE
#define private public
#endif
#include <iostream>

class A
{
private:
    int i;
    char ch;
};

class B : A
{
private:
    char ch;
};

int main()
{
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(A) << std::endl;
}