#include <iostream>
#include <fstream>

using namespace std;

void help(const char *name)
{
    cout << "usage: " << name << " input_file output_file" << endl;
}

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        help(argv[0]);
        return 0;
    }

    ifstream ifs;
    ofstream ofs;
    char c;

    ifs.open(argv[1]);
    if(!ifs.is_open())
    {
        cout << "Can not open input file" << endl;
        return 0;
    }
    ofs.open(argv[2]);
    if(!ofs.is_open())
    {
        cout << "Can not open output file" << endl;
        ifs.close();
        return 0;
    }

    while(ifs.get(c))
        ofs.put(c);

    ofs.close();
    ifs.close();

    return 0;
}
