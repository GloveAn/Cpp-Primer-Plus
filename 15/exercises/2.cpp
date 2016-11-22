#include <iostream>
#include <stdexcept>
#include <cmath>

double hmean(double a, double b) throw(std::logic_error);
double gmean(double a, double b) throw(std::logic_error);

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
        catch(std::invalid_argument & e)
        {
            cout << e.what() << endl;
            cout << "Try again.\n";
            continue;
        }
        catch(std::domain_error & e)
        {
            cout << e.what() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(std::logic_error)
{
    if(a == -b)
        throw std::invalid_argument("invalid arguments: a = -b");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(std::logic_error)
{
    if(a < 0 || b < 0)
        throw std::domain_error("gmean() arguments should be >= 0");
    return std::sqrt(a * b);
}
