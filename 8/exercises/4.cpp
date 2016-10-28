#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char *str;
    int ct
};

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be. ";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done! ");
    return 0;
}
