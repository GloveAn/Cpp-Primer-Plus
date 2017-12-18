#include <iostream>

using namespace std;

int main()
{
    double donations[10];
    double average = 0;
    int i, j, k;
    cout << "Enter donations, up to 10.\n";
    for(i = 0; i < 10 && cin >> donations[i]; i++)
        average += donations[i];
    average /= i;
    for(j = 0; j < i; j++)
        k += (donations[j] - average > 0.0099);
    cout << "average = " << average << "." << endl;
    cout << k << " donations above average" << endl;
    return 0;
}
