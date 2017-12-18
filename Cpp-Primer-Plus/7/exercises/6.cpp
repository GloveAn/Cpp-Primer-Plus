#include <iostream>

using namespace std;

int fill_array(double a[], int l)
{
    for(int i = 0; i < l; i++)
    {
        cout << "input a number: ";
        if(!(cin >> a[i]))
            return i;
    }
    return l;
}

void show_array(double a[], int l)
{
    cout << "show array: ";
    for(int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverse_array(double a[], int l)
{
    double temp;
    for(int i = 0, j = l - 1; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    double a[10];
    int l;

    l = fill_array(a, 10);
    show_array(a, l);
    reverse_array(a, l);
    show_array(a, l);
    reverse_array(a + 1, l - 2);
    show_array(a, l);

    return 0;
}
