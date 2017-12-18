#include <iostream>
#include "stonewt.h"

using namespace std;

int main()
{
    Stonewt s[6] =
    {
        Stonewt(1),
        Stonewt(3),
        Stonewt(5)
    };
    Stonewt fair(11);
    Stonewt *min = s, *max = s;
    int count = 0;
    double weight;

    for(int i = 3; i < 6; i++)
    {
        cout << "Enter weight in pounds: ";
        cin >> weight;
        s[i] = weight;
    }

    for(int i = 1; i < 6; i++)
    {
        if(*min > s[i]) min = s + i;
        if(*max < s[i]) max = s + i;
        if(s[i] >= fair) count++;
    }

    cout << "min: ";
    min->show_lbs();
    cout << "max: ";
    max->show_lbs();
    cout << count << " over 11 pounds\n";

    return 0;
}
