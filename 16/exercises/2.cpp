#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool is_palindrome(const string & s)
{
    string p;
    int i;
    int j;

    remove_copy_if(s.begin(), s.end(), back_inserter(p),
                    ptr_fun<int, int>(&ispunct));
    transform(p.begin(), p.end(), p.begin(), ::tolower);
    for(i = 0, j = p.length() - 1; i < j; i++, j--)
        if(p[i] != p[j])
            break;
    return i >= j;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << is_palindrome(s) << endl;
    return 0;
}
