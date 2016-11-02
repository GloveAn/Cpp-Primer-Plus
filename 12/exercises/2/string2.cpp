#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 1;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

void String::stringlow()
{
    for(int i = 0; i < len; i++)
        str[i] = std::tolower(str[i]);
}

void String::stringup()
{
    for(int i = 0; i < len; i++)
        str[i] = std::toupper(str[i]);
}

int String::has(char c) const
{
    int count;
    for(int i = 0; i < len; i++)
        if(str[i] == c)
            count++;
    return count;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

String operator+(const String &st1, const String &st2)
{
    using std::strlen;
    using std::strcpy;
    using std::strcat;

    char *temp = new char [strlen(st1.str) + strlen(st2.str) + 1];
    strcpy(temp, st1.str);
    strcat(temp, st2.str);

    String s(temp);
    delete [] temp;
    return s;
}

String operator+(const char * c1, const String &st2)
{
    using std::strlen;
    using std::strcpy;
    using std::strcat;

    char *temp = new char [strlen(c1) + strlen(st2.str) + 1];
    strcpy(temp, c1);
    strcat(temp, st2.str);

    String s(temp);
    delete [] temp;
    return s;
}

String operator+(const String &st1, const char * c2)
{
    using std::strlen;
    using std::strcpy;
    using std::strcat;

    char *temp = new char [strlen(st1.str) + strlen(c2) + 1];
    strcpy(temp, st1.str);
    strcat(temp, c2);

    String s(temp);
    delete [] temp;
    return s;
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
