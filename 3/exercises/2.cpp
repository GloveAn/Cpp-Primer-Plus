#include <iostream>

using namespace std;

const double FOOT2INCH = 12;
const double INCH2METER = 0.0254;
const double KG2POUND = 2.2;

int main()
{
    double foot, inch, pound;
    double bmi;

    cout << "Enter your height:" << endl;
    cin >> foot;
    cin >> inch;
    cout << "Enter yout weight: ";
    cin >> pound;

    bmi = foot * FOOT2INCH + inch;
    bmi = bmi * bmi;
    bmi = pound / KG2POUND / bmi;
    cout << "Your BMI is " << bmi << endl;

    return 0;
}
