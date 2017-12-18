#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int energy;
};

void set_candy_bar(
    CandyBar &candy_bar,
    const char brand[] = "Millennium Munch",
    const double weight = 2.85,
    const int energy = 350 )
{
    candy_bar.brand = brand;
    candy_bar.weight = weight;
    candy_bar.energy = energy;
}

void show_candy_bar(const CandyBar &candy_bar)
{
    cout << "brand: " << candy_bar.brand << ", "
        << "weight: " << candy_bar.weight << ", "
        << "energy: " << candy_bar.energy << ".\n";
}

int main()
{
    CandyBar glove;

    set_candy_bar(glove, "glove", 1, 2);
    show_candy_bar(glove);
    set_candy_bar(glove, "in", 3);
    show_candy_bar(glove);
    set_candy_bar(glove, "the");
    show_candy_bar(glove);
    set_candy_bar(glove);
    show_candy_bar(glove);
    return 0;
}
