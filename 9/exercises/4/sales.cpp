#include <iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        s.average = 0;
        s.max = ar[0];
        s.min = ar[0];
        for(int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            s.average += ar[i];
            if(ar[i] > s.max)
                s.max = ar[i];
            if(ar[i] < s.min)
                s.min = ar[i];
        }
        s.average /= n;
        for(int i = n; i < QUARTERS; i++)
        {
            s.sales[i] = 0;
        }
    }

    void setSales(Sales & s)
    {
        using std::cin;
        using std::cout;

        double ar[QUARTERS];
        int i;

        for(i = 0; i < QUARTERS; i++)
        {
            cout << "Enter sales: ";
            if(!(cin >> ar[i]))
                break;
        }
        setSales(s, ar, i);
    }

    void showSales(const Sales & s)
    {
        using std::cout;

        cout << "Sales: ";
        for(int i = 0; i < QUARTERS; i++)
            cout << s.sales[i] << " ";
        cout << "\n";
        cout << "ave: " << s.average << ", ";
        cout << "max: " << s.max << ", ";
        cout << "min: " << s.min << ".\n";
    }
}
