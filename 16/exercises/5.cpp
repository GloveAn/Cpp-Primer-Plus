#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <class T>
int reduce(T ar[], int n)
{
    sort(ar, ar + n);
    T *e = unique(ar, ar + n);
    return e - ar;
}

int main()
{
    long ar[] = {1, 3, 3, 4, 8, 6, 4, 3, 8, 9};
    string sr[] = {"hello", "fine", "cloud", "glove", "ok", "fine"};
    int e = reduce(ar, sizeof(ar) / sizeof(ar[0]));
    for(int i = 0; i < e; i++)
        std::cout << ar[i] << ' ';
    std::cout << "\n";
    e = reduce(sr, sizeof(sr) / sizeof(sr[0]));
    for(int i = 0; i < e; i++)
        std::cout << sr[i] << ' ';
    std::cout << "\n";
    return 0;
}
