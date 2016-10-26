#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int calorie;
};

int main()
{
    CandyBar *snack = new CandyBar[3];
    snack[0] = {"Mocha Munch", 2.3, 350};
    snack[1] = {"Mochb Munci", 2.4, 351};
    snack[2] = {"Mochc Muncj", 2.5, 352};

    cout << "Brand: " << snack[0].brand << ", "
        << "Weight: " << snack[0].weight << ", "
        << "calorie: " << snack[0].calorie << "."
        << endl;
    cout << "Brand: " << snack[1].brand << ", "
        << "Weight: " << snack[1].weight << ", "
        << "calorie: " << snack[1].calorie << "."
        << endl;
    cout << "Brand: " << snack[2].brand << ", "
        << "Weight: " << snack[2].weight << ", "
        << "calorie: " << snack[2].calorie << "."
        << endl;

    delete [] snack;

    return 0;
}
