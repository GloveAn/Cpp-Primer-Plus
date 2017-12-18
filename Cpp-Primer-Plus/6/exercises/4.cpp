#include <iostream>

using namespace std;

const int strsize = 24;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

int main()
{
    bop bops[] =
    {
        {"alice", "aa", "ecila", 0},
        {"bob", "bb", "bob", 1},
        {"cain", "cc", "niac", 2},
        {"david", "dd", "divad", 0}
    };
    char c;

    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display a nme      b. display by title" << endl;
    cout << "c. display a bopname  d. display by preference" << endl;
    cout << "e. quit" << endl;
    cout << "Enter your choice: ";
    while(cin >> c && c != 'q')
    {
        switch(c)
        {
            case 'a':
                for(int i = 0; i < sizeof(bops) / sizeof(bop); i++)
                    cout << bops[i].fullname << endl;
                break;
            case 'b':
                for(int i = 0; i < sizeof(bops) / sizeof(bop); i++)
                    cout << bops[i].title << endl;
                break;
            case 'c':
                for(int i = 0; i < sizeof(bops) / sizeof(bop); i++)
                    cout << bops[i].bopname << endl;
                break;
            case 'd':
                for(int i = 0; i < sizeof(bops) / sizeof(bop); i++)
                    switch(bops[i].preference)
                    {
                        case 0:
                            cout << bops[i].fullname << endl;
                            break;
                        case 1:
                            cout << bops[i].title << endl;
                            break;
                        case 2:
                            cout << bops[i].bopname << endl;
                            break;
                    }
                break;
        }
        cout << "Next choice: ";
    }
    cout << "Bye" << endl;

    return 0;
}
