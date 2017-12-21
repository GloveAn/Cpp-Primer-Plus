#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("fdsa dsiufeha");

    for(auto &c: s)
        c = 'X';
    cout << s << endl;

    return 0;
}
