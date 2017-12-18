#include <iostream>

class Complex
{
private:
    double r;
    double i;
public:
    Complex(double d = 0, double o = 0);
    friend Complex operator+(const Complex &a, const Complex &b);
    friend Complex operator-(const Complex &a, const Complex &b);
    friend Complex operator*(const Complex &a, const Complex &b);
    friend Complex operator~(const Complex &a);
    friend std::ostream &operator<<(std::ostream &os, const Complex &a);
    friend std::istream &operator>>(std::istream &is, Complex &a);
};

Complex::Complex(double d, double o)
{
    r = d;
    i = o;
}

Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.r - b.r, a.i - b.i);
}

Complex operator*(const Complex &a, const Complex &b)
{
    return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

Complex operator~(const Complex &a)
{
    return Complex(a.r, -a.i);
}

std::ostream &operator<<(std::ostream &os, const Complex &a)
{
    return os << "(" << a.r << ", " << a.i << "i)";
}

std::istream &operator>>(std::istream &is, Complex &a)
{
    std::cout << "real: ";
    if(is >> a.r)
    {
        std::cout << "imaginary: ";
        is >> a.i;
    }
    return is;
}

int main()
{
    using namespace std;

    Complex a(3.0, 4.0);
    Complex c(10, 12);
    cout << "Enter a complex number (q to quit): \n";
    while(cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit): \n";
    }
    cout << "Done!\n";
    return 0;
}
