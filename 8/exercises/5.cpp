#include <iostream>

template<typename T>
T max(const T t[])
{
    T max = t[0];
    for(int i = 1; i < 5; i++)
        if(t[i] > max)
            max = t[i];
    return max;
}

int main()
{
    using namespace std;

    int i[] = {1, 2, 3, 4, 5};
    double d[] = {5, 4, 3, 2, 1};

    cout << "int max: " << max(i) << endl;
    cout << "double max: " << max(d) << endl;

    return 0;
}
