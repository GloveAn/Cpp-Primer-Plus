#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    Stonewt poppins(9, 2.8);

    poppins.use_stone();
    cout << poppins;
    poppins.use_int_pound();
    cout << poppins;
    poppins.use_float_pound();
    cout << poppins;

    return 0;
}
