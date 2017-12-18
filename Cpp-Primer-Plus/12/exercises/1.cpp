#include <iostream>
#include <cstring>

class Cow
{
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow & operator=(const Cow &c);
    void ShowCow() const;
};

Cow::Cow()
{
    strcpy(name, "alien");
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    name[19] = '\0';
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow &Cow::operator=(const Cow &c)
{
    strcpy(name, c.name);
    delete [] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

void Cow::ShowCow() const
{
    using std::cout;

    cout << "name: " << name
        << ": hobby: " << hobby
        << ": weight: " << weight << "\n";
}

int main()
{
    Cow a("a cow", "eat", 200);
    Cow b(a);
    Cow c = a;

    a.ShowCow();
    b.ShowCow();
    c.ShowCow();

    return 0;
}
