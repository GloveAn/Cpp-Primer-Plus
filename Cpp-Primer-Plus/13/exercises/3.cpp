#include <iostream>
#include <cstring>

class DMA
{
protected:
    char *label;
    int rating;
public:
    DMA(const char * l = "null", int r = 0);
    DMA(const DMA & rs);
    virtual DMA & operator=(const DMA & rs);
    virtual ~DMA();
    friend std::ostream & operator<<(std::ostream & os, const DMA & rs);
    virtual void View() const = 0;
};

DMA::DMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

DMA & DMA::operator=(const DMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

DMA::~DMA()
{
    delete [] label;
}

std::ostream & operator<<(std::ostream & os, const DMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

class baseDMA: public DMA
{
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
    virtual void View() const;
};

baseDMA::baseDMA(const char * l, int r)
    :DMA(l, r)
{
}

baseDMA::baseDMA(const baseDMA & rs)
    :DMA(rs)
{
}

baseDMA::~baseDMA()
{
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    DMA::operator=(rs);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    return os << (const DMA &)rs;
}

void baseDMA::View() const
{
    operator<<(std::cout, *this);
}

class lacksDMA: public DMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
            int t = 0);
    lacksDMA(const char * c, const DMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                        const lacksDMA & rs);
    virtual void View() const;
};

lacksDMA::lacksDMA(const char * c, const char * l, int r)
    :DMA(l, r)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & rs)
    :DMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const DMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const
{
    operator<<(std::cout, *this);
}

class hasDMA: public DMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
            int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
    virtual void View() const;
};

hasDMA::hasDMA(const char * s, const char * l, int r)
    : DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
    : DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
    : DMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs);
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const DMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

void hasDMA::View() const
{
    operator<<(std::cout, *this);
}

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    DMA * p;

    p = &shirt;
    cout << *p << endl;
    p = &balloon;
    cout << *p << endl;
    p = &map;
    cout << *p << endl;

    return 0;
}
