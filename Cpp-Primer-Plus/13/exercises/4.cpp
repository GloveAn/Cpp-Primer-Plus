#include <iostream>
#include <cstring>
using namespace std;

class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 20);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if(this == &p)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    return os << p.brand << ", " << p.style << ", " << p.bottles;
}

class VintagePort: public Port
{
private:
    char * nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & p);
};

VintagePort::VintagePort()
    :Port()
{
    nickname = new char[strlen("none") + 1];
    strcpy(nickname, "none");
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    :Port(br, "", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
    :Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & p)
{
    os << (const Port &)p;
    return os << ", " << p.nickname << ", " << p.year;
}

int main()
{
    Port p1("Gallo", "tawny", 20);
    Port p2(p1);
    Port p3;
    VintagePort vp1("Hallo", 20, "Uawny", 21);
    VintagePort vp2(vp1);
    VintagePort vp3;

    p3 = p1;
    vp3 = vp1;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    cout << vp1 << endl;
    cout << vp2 << endl;
    cout << vp3 << endl;

    p1.Show();
    p2.Show();
    p3.Show();

    vp1.Show();
    vp2.Show();
    vp3.Show();

    return 0;
}
