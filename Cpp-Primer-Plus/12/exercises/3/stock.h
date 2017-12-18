#ifndef STOCK3_H_
#define STOCK3_H_

#include <iostream>

class Stock
{
private:
    char *company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val; }
public:
    Stock();
    Stock(const char *co, int n = 0, double pr = 0.0);
    Stock(const Stock &s);
    ~Stock();
    Stock &operator=(const Stock &s);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s)const;
    friend std::ostream &operator<<(std::ostream &os, const Stock &s);
};

#endif
