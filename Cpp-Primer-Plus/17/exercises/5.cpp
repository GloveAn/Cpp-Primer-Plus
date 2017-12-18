#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    ifstream fmat("mat.dat");
    ifstream fpat("pat.dat");
    ofstream fall("matnpat.dat");

    set<string> mat;
    set<string> pat;
    set<string> all;
    set<string>::iterator it;

    string name;

    if(!fmat.is_open() || !fpat.is_open() || !fall.is_open())
    {
        if(fmat.is_open()) fmat.close();
        if(fpat.is_open()) fpat.close();
        if(fall.is_open()) fall.close();
    }

    while(!fmat.eof())
    {
        getline(fmat, name);
        if(name.size())
            mat.insert(name);
    }
    cout << "Mat's friends:\n";
    for(it = mat.begin(); it != mat.end(); it++)
        cout << *it << endl;
    cout << endl;
    while(!fpat.eof())
    {
        getline(fpat, name);
        if(name.size())
            pat.insert(name);
    }
    cout << "Pat's friends:\n";
    for(it = pat.begin(); it != pat.end(); it++)
        cout << *it << endl;
    cout << endl;

    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(),
        insert_iterator<set<string> >(all, all.begin()));
    cout << "Friends of all:\n";
    for(it = all.begin(); it != all.end(); it++)
    {
        cout << *it << endl;
        fall << *it << endl;
    }
    cout << endl;

    fmat.close();
    fpat.close();
    fall.close();
    return 0;
}
