#include <iostream>
#include <cstring>

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd();
    virtual void Report()const;
};

Cd::Cd(char * s1, char * s2, int n, double x)
{
    strncpy(performers, s1, 50);
    performers[49] = '\0';
    strncpy(label, s2, 20);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    performers[49] = '\0';
    label[19] = '\0';
    selections = 0;
    playtime = 0;
}

void Cd::Report() const
{
    using std::cout;
    cout << performers << ": " << label << ", " << playtime << "\n";
}

class Classic: public Cd
{
private:
    char major[50];
public:
    Classic(char * s0, char * s1, char * s2, int n, double x);
    Classic();
    virtual void Report()const;
};

Classic::Classic(char * s0, char * s1, char * s2, int n, double x)
    :Cd(s1, s2, n, x)
{
    strncpy(major, s0, 50);
    major[49] = '\0';
}

Classic::Classic()
    :Cd()
{
    major[0] = '\0';
}

void Classic::Report() const
{
    using std::cout;
    Cd::Report();
    cout << "    " << major << "\n";
}

using namespace std;

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano sonata in B flat, Fantasia in C",
                    "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;

    cout << "Using object directly: \n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects: \n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument: \n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: \n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}
