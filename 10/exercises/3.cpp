#include <iostream>
#include <cstring>

class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf();
    Golf(const char *name, int hc);
    void set_handicap(int hc);
    void showgolf() const;
};

Golf::Golf()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter full name: ";
    cin.getline(fullname, Len);
    if(!cin || !strlen(fullname))
        strcpy(fullname, "no name");
    cout << "Enter handicap: ";
    cin >> handicap;
    cin.get();
}

Golf::Golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf() const
{
    using std::cout;
    using std::endl;

    cout << fullname << ": " << handicap << endl;
}

int main()
{
    using namespace std;

    Golf ga[3] = {
        Golf("ab cd", 0),
        Golf("ef gh", 1),
        Golf("ij kl", 2)
    };

    for(int j = 0; j < 3; j++)
        ga[j].showgolf();
    ga[0].set_handicap(3);
    ga[0].showgolf();

    return 0;
}
