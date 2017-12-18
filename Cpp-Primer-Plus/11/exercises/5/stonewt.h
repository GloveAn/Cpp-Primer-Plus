#ifndef STONEWT2_H_
#define STONEWT2_H_

#include <iostream>

class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
    char state;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void use_stone();
    void use_int_pound();
    void use_float_pound();
    void show_lbs() const;
    void show_stn() const;
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &s);
    operator int() const;
    operator double() const;
};

#endif
