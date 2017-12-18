#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main()
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}

void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()
{
    double warming = 0.8;

    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}
