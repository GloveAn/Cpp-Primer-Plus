#include <iostream>
#include <cstring>

template<typename T>
T maxn(T t[], int l)
{
    T max = t[0];
    for(int i = 1; i < l; i++)
        if(t[i] > max)
            max = t[i];
    return max;
}

template<>
const char * maxn<>(const char * t[], int l)
{
    int max = 0;
    for(int i = 1; i < l; i++)
        if(strlen(t[i]) > strlen(t[max]))
            max = i;
    return t[max];
}

int main()
{
    using namespace std;

    int i[] = {1, 2, 3, 4, 5, 6};
    double d[] = {4, 3, 2, 1};
    const char *c[] = {
        "a",
        "bc",
        "def",
        "ghij",
        "klmno"
    };

    cout << "int max: " << maxn(i, 6) << endl;
    cout << "double max: " << maxn(d, 4) << endl;
    cout << "char * max: " << maxn(c, 5) << endl;

    return 0;
}
