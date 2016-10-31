#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person() {lname = ""; fname[0] = '\0';}
    Person(const string & ln, const char * fn = "Heyyou");
    void show() const;
    void FormalShow() const;
};

Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
    fname[LIMIT - 1] = '\0';
}

void Person::show() const
{
    using std::cout;
    using std::endl;
    cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
    using std::cout;
    using std::endl;
    cout << lname << ", " << fname << endl;
}

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    one.FormalShow();
    two.show();
    two.FormalShow();
    three.show();
    three.FormalShow();
    return 0;
}
