#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string & s)
{
    int i = 0;
    int j = s.length() - 1;
    for(; i < j; i++, j--)
        if(s[i] != s[j])
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
