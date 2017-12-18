#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<string> mat;
    set<string> pat;
    set<string> all;
    set<string>::iterator it;
    string name;

    cout << "Enter Mat's friends name('end' to end):\n";
    while(cin >> name && name != "end")
        mat.insert(name);
    cout << "Mat's friends:\n";
    for(it = mat.begin(); it != mat.end(); it++)
        cout << *it << ' ';
    cout << endl;
    cout << "Enter Pat's friends name('end' to end): \n";
    while(cin >> name && name != "end")
        pat.insert(name);
    cout << "Pat's friends:\n";
    for(it = pat.begin(); it != pat.end(); it++)
        cout << *it << ' ';
    cout << endl;

    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(),
        insert_iterator<set<string> >(all, all.begin()));
    cout << "Friends of all:\n";
    for(it = all.begin(); it != all.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
