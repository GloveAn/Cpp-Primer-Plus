#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    //std::cout << /* "*/" */;  // ERROR
    std::cout << /*  "*/" /* "/*"  */;

    return 0;
}
