#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "../11.13.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    unsigned long max = 0, min = ULONG_MAX, ave = 0;
    int trial = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }

        trial++;
        ave += steps;
        if(steps > max) max = steps;
        if(steps < min) min = steps;

        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    if(trial)
    {
        ave /= trial;
        cout << "max: " << max << ", min: " << min << ", ave: " << ave << endl;
    }
    cout << "Bye!\n";

    return 0;
}
