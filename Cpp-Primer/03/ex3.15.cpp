#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string s;
    vector<string> vs;

    while(cin >> s)
        vs.push_back(s);
    for(auto t: vs)
        cout << t << endl;

    return 0;
}
