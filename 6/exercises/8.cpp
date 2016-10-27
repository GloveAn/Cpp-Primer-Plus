#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    char c;
    unsigned long count = 0;

    file.open(__FILE__); // g++ macro for the source code itself
    while(file >> c)
        count++;
    file.close();
    cout << "Total of " << count << " characters" << endl;

    return 0;
}
