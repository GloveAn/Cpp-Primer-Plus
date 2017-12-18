#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

class base_error: public std::logic_error
{
protected:
    double a;
    double b;
public:
    base_error(double v1, double v2, const char * s)
        : logic_error(s), a(v1), b(v2) {};
    virtual void report() = 0;
};

class hmean_error: public base_error
{
public:
    hmean_error(double v1, double v2)
        : base_error(v1, v2, "invalid arguments: a = -b") {};
    void report()
        { std::cout << "hmean(" << a << ", " << b << "): "
            << "invalid arguments: a = -b\n"; }
};

class gmean_error: public base_error
{
public:
    gmean_error(double v1, double v2)
        : base_error(v1, v2, "arguments should be >= 0") {};
    void report()
        { std::cout << "gmean(" << a << ", " << b << "): "
            << "arguments should be >= 0\n"; }
};

double hmean(double a, double b) throw(hmean_error);
double gmean(double a, double b) throw(gmean_error);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch(base_error & e)
        {
            cout << e.what() << endl;
            e.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(hmean_error)
{
    if(a == -b)
        throw hmean_error(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(gmean_error)
{
    if(a < 0 || b < 0)
        throw gmean_error(a, b);
    return std::sqrt(a * b);
}
