#include <iostream>
#include <string>

using namespace std;

struct info
{
    string name;
    double donation;
};

int main()
{
    int n, i, j;
    info *donators;
    info temp;

    cout << "The number of donators: ";
    cin >> n;
    cin.get();
    donators = new info[n];

    for(i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        getline(cin, donators[i].name);
        cout << "Enter donation: ";
        cin >> donators[i].donation;
        cin.get();
    }

    i = 0, j = n - 1;
    while(true)
    {
        while(donators[i].donation > 10000)
            i++;
        while(donators[j].donation <= 10000)
            j--;
        if(i < j)
        {
            temp = donators[i];
            donators[i] = donators[j];
            donators[j] = temp;
        }
        else
        {
            break;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);

    cout << "Great Patrons" << endl;
    for(j = 0; j < i; j++)
    {
        cout << donators[j].name << ": " << donators[j].donation << endl;
    }
    if(j == 0)
    {
        cout << "none" << endl;
    }

    cout << "Patrons" << endl;
    for(i = i; i < n; i++)
    {
        cout << donators[i].name << ": " << donators[i].donation << endl;
    }
    if(j == n)
    {
        cout << "none" << endl;
    }

    delete [] donators;
    return 0;
}
