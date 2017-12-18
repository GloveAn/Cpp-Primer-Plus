#include <iostream>
#include <cstring>

class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd();
    virtual ~Cd();
    virtual void Report()const;
    Cd & operator=(const Cd & d);
};

Cd::Cd(char * s1, char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    using std::cout;
    cout << performers << ": " << label << ", " << playtime << "\n";
}

Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

class Classic: public Cd
{
private:
    char *major;
public:
    Classic(char * s0, char * s1, char * s2, int n, double x);
    Classic();
    ~Classic();
    virtual void Report()const;
    Classic & operator=(const Classic & c);
};

Classic::Classic(char * s0, char * s1, char * s2, int n, double x)
    :Cd(s1, s2, n, x)
{
    major = new char[strlen(s0) + 1];
    strcpy(major, s0);
}

Classic::Classic()
    :Cd()
{
    major = new char[1];
    major[0] = '\0';
}

Classic::~Classic()
{
    delete [] major;
}

void Classic::Report() const
{
    using std::cout;
    Cd::Report();
    cout << "    " << major << "\n";
}

Classic & Classic::operator=(const Classic & c)
{
    if(this == &c)
        return *this;
    Cd::operator=(c);
    delete [] major;
    major = new char[strlen(c.major) + 1];
    strcpy(major, c.major);
    return *this;
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
