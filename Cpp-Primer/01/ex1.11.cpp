#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl; 
    int n1 = 0, n2 = 10;
    std::cin >> n1 >> n2;

    while (n1 <= n2) {
        std::cout << n1 << std::endl;;
        ++n1;
    }

    return 0;
}
