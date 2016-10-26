#include <iostream>

int main()
{
    using namespace std;

    int small, large, sum;
    cout << "Enter the small number: ";
    cin >> small;
    cout << "Enter the large number: ";
    cin >> large;

    for (sum = 0; small <= large; small++)
        sum += small;
    cout << "Sum is " << sum << endl;

    return 0;
}
