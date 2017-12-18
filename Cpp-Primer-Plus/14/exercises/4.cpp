#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Person
{
private:
    string fname;
    string lname;
public:
    Person(const string & fn, const string & ln) :fname(fn), lname(ln) {}
    virtual void Show() const { cout << fname << ", " << lname << endl; }
};

class Gunslinger: virtual public Person
{
private:
    double time;
    int count;
public:
    Gunslinger(const string & fn, const string & ln, double t, int c)
        : Person(fn, ln), time(t), count(c) {}
    double Draw() const { return time; }
    void Show() const {
        Person::Show();
        cout << "time :" << time << " count: " << count << endl; }
};

class PokerPlayer: virtual public Person
{
public:
    PokerPlayer(const string & fn, const string & ln) :Person(fn, ln) {}
    int Draw() const { return rand() % 52 + 1; }
};

class BadDude: public PokerPlayer, public Gunslinger
{
public:
    BadDude(const string & fn, const string & ln, double t, int c)
        : Person(fn, ln), PokerPlayer(fn, ln), Gunslinger(fn, ln, t, c) {}
    double GDraw() const { return Gunslinger::Draw(); }
    int CDraw() const { return PokerPlayer::Draw(); }
    void Show() const { Gunslinger::Show(); }
};

int main()
{
    BadDude bd("Glove", "An", 0.5, 9);
    srand(time(0));
    bd.Show();
    cout << bd.GDraw() << endl;
    cout << bd.CDraw() << endl;
    return 0;
}
