#include <iostream>

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess = 3.9832;
    int debt = 7.2E12; // warning: overflow in implicit constant conversion [-Woverflow]
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    return 0;
}
