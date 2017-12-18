#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    std::string name;
    PairArray collection;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    void GetBottles();
    std::string & Label();
    int Sum() const;
    void Show() const;
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : name(l), collection(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char * l, int y)
    : name(l), collection(ArrayInt(y), ArrayInt(y))
{
}

void Wine::GetBottles()
{
    using std::cout;
    using std::cin;

    int n = collection.first().size();

    cout << "Enter " << name << " data for " << n << " year(s):\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Enter year: ";
        cin >> collection.first()[i];
        cout << "Enter bottles for that year: ";
        cin >> collection.second()[i];
    }
}

std::string & Wine::Label()
{
    return name;
}

int Wine::Sum() const
{
    int n = collection.first().size();
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += collection.second()[i];
    }
    return s;
}

void Wine::Show() const
{
    using std::cout;
    using std::endl;

    int n = collection.first().size();

    cout << "Wine: " << name << endl;
    cout << "   year    Bottles" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "   " << collection.first()[i]
            << "    " << collection.second()[i] << endl;
    }
}

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
        << ": " << more.Sum() << endl;
    cout << "Bye\n";
    return 0;
}
