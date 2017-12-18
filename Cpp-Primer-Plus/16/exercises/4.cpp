#include <iostream>
#include <algorithm>

using namespace std;

int reduce(long ar[], int n)
{
    sort(ar, ar + n);
    long *e = unique(ar, ar + n);
    return e - ar;
}

int main()
{
    long ar[] = {1, 3, 3, 4, 8, 6, 4, 3, 8, 9};
    int e = reduce(ar, sizeof(ar) / sizeof(long));
    for(int i = 0; i < e; i++)
        std::cout << ar[i] << ' ';
    std::cout << "\n";
    return 0;
}
