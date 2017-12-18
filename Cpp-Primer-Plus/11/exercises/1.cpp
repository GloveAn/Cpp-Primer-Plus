#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
    double target;
    double dstep;
    ofstream fout;
    fout.open("record.txt");
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        fout << "Target Distance: " << target << ", "
            << "Step Size: " << dstep << endl;
        while (result.magval() < target)
        {
            fout << steps << ": " << result << endl;
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location: \n";
        fout << "After " << steps << " steps, the subject "
            "has the following location: \n";
        cout << result << endl;
        fout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        fout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        fout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    fout.close();
    return 0;
}
