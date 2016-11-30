#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    char c;
    ofstream ofs;

    if(argc == 1)
        return 0;
    ofs.open(argv[1]);
    if(!ofs.is_open())
        return 0;

    while(cin.get(c))
        ofs.put(c);

    ofs.close();
}
