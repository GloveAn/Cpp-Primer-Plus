#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char *str;
    int ct;
};

char *set(stringy &s, const char *c)
{
    s.ct = strlen(c);
    s.str = new char[s.ct + 1];
    if(s.str)
    {
        strcpy(s.str, c);
        return s.str;
    }
    else
    {
        return 0;
    }
}

void show(const stringy &s, int n = 1)
{
    for(int i = 0; i < n; i++)
        cout << s.str << endl;
}

void show(const char *s, int n = 1)
{
    for(int i = 0; i < n; i++)
        cout << s << endl;
}

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
