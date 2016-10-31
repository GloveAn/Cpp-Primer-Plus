#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter full name: ";
    cin.getline(g.fullname, Len);
    if(!cin || !strlen(g.fullname))
        return 1;
    cout << "Enter handicap: ";
    cin >> g.handicap;
    cin.get();

    return 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;
    using std::endl;

    cout << g.fullname << ": " << g.handicap << endl;
}
