#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    state = 's';
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    state = 's';
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    state = 's';
}

Stonewt::~Stonewt()
{
}

void Stonewt::use_stone()
{
    state = 's';
}

void Stonewt::use_int_pound()
{
    state = 'i';
}

void Stonewt::use_float_pound()
{
    state = 'f';
}

void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}

std::ostream &operator<<(std::ostream &os, const Stonewt &s)
{
    switch(s.state)
    {
        case 's':
            os << s.stone << " stone, " << s.pds_left << " pounds\n";
            break;
        case 'i':
            os << int(s.pounds + 0.5) << " pounds\n";
            break;
        case 'f':
            os << s.pounds << " pounds\n";
            break;
    }
    return os;
}

Stonewt::operator int() const
{
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}
