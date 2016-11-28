#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lotto(int n, int c)
{
    vector<int> v(n);
    v[0] = n;
    for(int i = 1; i < n; i++)
        v[i] = i;
    random_shuffle(v.begin(), v.end());
    return vector<int>(v.begin(), v.begin() + c);
}

int main()
{
    vector<int> winners;
    winners = Lotto(51, 6);
    for(int i = 0; i < 6; i++)
        cout << winners[i] << ' ';
    cout << endl;
    return 0;
}
