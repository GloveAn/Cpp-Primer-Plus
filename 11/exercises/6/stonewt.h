#ifndef STONEWT3_H_
#define STONEWT3_H_

class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    bool operator<(const Stonewt &s) { return pounds < s.pounds; }
    bool operator>(const Stonewt &s) { return pounds > s.pounds; }
    bool operator<=(const Stonewt &s) { return pounds <= s.pounds; }
    bool operator>=(const Stonewt &s) { return pounds >= s.pounds; }
    bool operator==(const Stonewt &s) { return pounds == s.pounds; }
    bool operator!=(const Stonewt &s) { return pounds != s.pounds; }
    operator int() const;
    operator double() const;
};

#endif
