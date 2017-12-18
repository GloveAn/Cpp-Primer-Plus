#include <iostream>
#include <cstring>

class Plorg
{
private:
    char name[20];
    int ci;
public:
    Plorg(const char n[] = "Plorga", int c = 50);
    void set_ci(int c);
    void report() const;

};

Plorg::Plorg(const char n[], int c)
{
    strncpy(name, n, 20);
    name[19] = '\0';
    ci = c;
}

void Plorg::set_ci(int c)
{
    ci = c;
}

void Plorg::report() const
{
    using std::cout;

    cout << name << ": " << ci << "\n";
}

int main()
{
    Plorg p;
    p.set_ci(20);
    p.report();
    return 0;
}
