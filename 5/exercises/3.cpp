#include <iostream>

using namespace std;

int main()
{
    double daphne = 100, cleo = 100;
    int i;

    do
    {
        daphne += 10;
        cleo *= 1.05;
        i++;
    }
    while (daphne - cleo > 0.0099);
    cout << "Year " << i << endl;
    cout << "daphne: " << daphne << ", cleo； " << cleo << endl;

    return 0;
}
