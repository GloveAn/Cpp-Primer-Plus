#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double field_total, field_choices, special_total, special_choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed "
            "for field number and special number:\n";
    cin >> field_total >> field_choices >> special_total >> special_choices;
    cout << "You have one chance in ";
    cout << probability(field_total, field_choices)
            * probability(special_total, special_choices);
    cout << " of winning.\n";
    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
