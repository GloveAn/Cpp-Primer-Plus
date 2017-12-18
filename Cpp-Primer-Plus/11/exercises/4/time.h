#ifndef MYTIME4_H_
#define MYTIME4_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time &t, const Time &i);
    friend Time operator-(const Time &t, const Time &i);
    friend Time operator*(const Time & t, double n);
    friend Time operator*(double m, const Time & t);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
    void Show() const;
};

#endif
