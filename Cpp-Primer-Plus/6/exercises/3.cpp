#include <iostream>

using namespace std;

int main()
{
    const char *words[] =
    {
        "carnivore",
        "pianist",
        "tree",
        "game"
    };
    char c;
    int i;

    cout << "Please enter one of the following choices:" << endl;
    cout << words[0][0] << ") " << words[0] << "\t"
        << words[1][0] << ") " << words[1] << "\n";
    cout << words[2][0] << ") " << words[2] << "\t\t"
        << words[3][0] << ") " << words[3] << "\n";

    while(true)
    {
        cin >> c;
        for(i = 0; i < 4; i++)
            if(c == words[i][0])
                break;
        if(i < 4)
        {
            cout << "You choosed " << words[i] << "." << endl;;
            break;
        }
        else
        {
            cout << "Please enter a "
                << words[0][0] << ", "
                << words[1][0] << ", "
                << words[2][0] << ", "
                << "or " << words[3][0]
                << ": ";
        }
    }

    return 0;
}
