#include <iostream>

using namespace std;

double calculate(double a, double b, double (*f)(double, double))
{
    return f(a, b);
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double (*operator_array[])(double, double) = {add, subtract};

int main()
{
    double x, y;

    cout << "Enter a pair of numbers: ";
    while(cin >> x >> y)
    {
        for(int i = 0; i < sizeof(operator_array) / sizeof(void *); i++)
        {
            cout << "result #" << i << ": "
                << calculate(x, y, operator_array[i]) << endl;
        }
        cout << "Enter a pair of numbers: ";
    }

    return 0;
}
