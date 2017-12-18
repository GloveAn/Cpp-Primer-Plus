#include <iostream>
const int Max = 5;

double *fill_array(double *begin, double *end);
void show_array(const double *begin, const double *end);
void revalue(double r, double *begin, double *end);

int main()
{
    using namespace std;
    double properties[Max];

    double *end = fill_array(properties, properties + Max - 1);
    show_array(properties, end);
    cout << "Enter revaluation factor: ";
    double factor;
    cin >> factor;
    revalue(factor, properties, end);
    show_array(properties, end);
    cout << "Done.\n";
    return 0;
}

double *fill_array(double *begin, double *end)
{
    using namespace std;
    double temp;
    int i;
    for(double *l = begin; l <= end; l++)
    {
        cout << "Enter value #" << (l - begin + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input: input process terminated.\n";
            return l - 1;
        }
        else if (temp < 0)
            return l - 1;
        *l = temp;
    }
    return end;
}

void show_array(const double *begin, const double *end)
{
    using namespace std;
    for (const double *l = begin; l <= end; l++)
    {
        cout << "Property #" << (l - begin + 1) << ": $";
        cout << *l << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    for (double *l = begin; l <= end; l++)
    {
        *l *= r;
    }
}
