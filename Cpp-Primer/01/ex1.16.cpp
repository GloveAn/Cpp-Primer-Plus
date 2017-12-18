#include <iostream>

int main()
{
    int sum = 0;
    int i;
    
    while(std::cin >> i)
    {
        sum += i;
    }
    
    std::cout << "sum is " << sum << std::endl;
    return 0;
}
