#include <iostream>
#include <fstream>

using namespace std;

void help(const char *name)
{
    cout << "usage: " << name << " input_file1 input_file2 output_file" << endl;
}

int main(int argc, char * argv[])
{
    if(argc != 4)
    {
        help(argv[0]);
        return 0;
    }

    ifstream ifs1; // ifs1/txt
    ifstream ifs2; // ifs2.txt
    ofstream ofs;
    char c;

    ifs1.open(argv[1]);
    if(!ifs1.is_open())
    {
        cout << "Can not open input file" << endl;
        return 0;
    }
    ifs2.open(argv[2]);
    if(!ifs2.is_open())
    {
        cout << "Can not open input file" << endl;
        ifs1.close();
        return 0;
    }
    ofs.open(argv[3]);
    if(!ofs.is_open())
    {
        cout << "Can not open output file" << endl;
        ifs1.close();
        ifs2.close();
        return 0;
    }

    while(!ifs1.eof() && !ifs2.eof())
    {
        while(ifs1.get(c) && c != '\n')
            ofs.put(c);
        ofs.put(' ');
        while(ifs2.get(c) && c != '\n')
            ofs.put(c);
        ofs.put('\n');
    }
    if(ifs1.eof() && !ifs2.eof())
    {
        while(ifs2.get(c))
            ofs.put(c);
    }
    if(!ifs1.eof() && ifs2.eof())
    {
        while(ifs1.get(c))
            ofs.put(c);
    }

    ofs.close();
    ifs1.close();
    ifs2.close();
    return 0;
}
