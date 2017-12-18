#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int n;

    cout << "enter a number: ";
    for (cin >> n; n; cin >> n)
    {
        sum += n;
        cout << "sum = " << sum << endl;
        cout << "enter a number: ";
    }
}
