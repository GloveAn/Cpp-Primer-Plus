#include <iostream>

namespace SALES
{
    using namespace std;

    const int QUARTERS = 4;

    class Sales
    {
    private:
        int count;
        double sales[QUARTERS];
    public:
        Sales();
        Sales(const Sales &);
        Sales(const double ar[], int n);
        void show_sales() const;
    };

    Sales::Sales()
    {
        count = 0;
        for(int i = 0; i < QUARTERS; i++)
            sales[i] = 0;
    }

    Sales::Sales(const Sales & s)
    {
        count = s.count;
        for(int i = 0; i < count; i++)
            sales[i] = s.sales[i];
        for(int i = count; i < QUARTERS; i++)
            sales[i] = 0;
    }

    Sales::Sales(const double ar[], int n)
    {
        count = n;

        for(int i = 0; i < n; i++)
            sales[i] = ar[i];
        for(int i = n; i < QUARTERS; i++)
            sales[i] = 0;
    }

    void Sales::show_sales() const
    {
        if(count == 0) return;

        double min = sales[0];
        double max = sales[0];
        double ave = sales[0];

        for(int i = 1; i < count; i++)
        {
            if(min > sales[i]) min = sales[i];
            if(max < sales[i]) max = sales[i];
            ave += sales[i];
        }
        ave /= count;

        cout << "Sales: ";
        for(int i = 0; i < count; i++)
            cout << sales[i] << " ";
        cout << endl;
        cout << "Max: " << max << ", Min: " << min << ", Ave:" << ave << endl;
    }
}

int main()
{
    using namespace SALES;

    double ar[] = {1, 2, 3, 4};
    Sales a;
    Sales b(ar, 4);
    Sales c(b);

    a.show_sales();
    b.show_sales();
    c.show_sales();
}
