#include <iostream>
#include "golf.h"

using namespace std;

int main()
{
    golf ga[3];
    int i, j;

    setgolf(ga[0], "ab cd", 2);
    for(i = 1; i < 3; i++)
        if(setgolf(ga[i]))
            break;
    for(j = 0; j < i; j++)
        showgolf(ga[j]);
    handicap(ga[0], 3);
    showgolf(ga[0]);

    return 0;
}
