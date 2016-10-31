#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;

    Sales s[2];
    double ar[] = {2, 3, 4, 5};

    setSales(s[0], ar, 4);
    setSales(s[1]);
    showSales(s[0]);
    showSales(s[1]);

    return 0;
}
