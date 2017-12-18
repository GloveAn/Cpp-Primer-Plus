#include <iostream>
//#include <sstream>

using namespace std;

int main()
{
    //stringbuf s;
    //cin.get(s, '$');
    //cout << s.str().size() << endl;

    int count = 0;
    while(cin.peek() != '$' && cin.good())
    {
        cin.get();
        count++;
    }
    cout << count << endl;

    return 0;
}
