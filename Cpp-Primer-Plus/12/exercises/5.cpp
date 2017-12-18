#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../12.10.h"
const int MIN_PER_HR = 60;

bool newcustomer (double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    double perhour = 0;
    double min_per_cust;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;
    bool found = false;

    while (!found)
    {
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;

        perhour++;
        min_per_cust = MIN_PER_HR / perhour;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }
        found = ((double) line_wait / served) > 1.0;
    }
    perhour--;
    if (customers > 0)
        cout << "customers per hour: " << perhour << endl;
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
