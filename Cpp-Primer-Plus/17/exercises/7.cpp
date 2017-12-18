#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void ShowStr(const std::string & s)
{
    std::cout << s << std::endl;
}

class Store
{
private:
    std::ofstream & ofs;
public:
    Store(std::ofstream & i) :ofs(i) {}
    void operator()(const std::string &);
};

void Store::operator()(const std::string &s)
{
    size_t length = s.length();
    ofs.write((char *)&length, sizeof(length));
    ofs.write(s.data(), length);
}

void GetStr(std::ifstream &ifs, std::vector<std::string> &v)
{
    size_t length;
    char c;
    std::string s;

    for(int i = 0; !ifs.eof(); i++)
    {
        s.clear();
        ifs.read((char *)&length, sizeof(length));
        for(int j = 0; j < length; j++)
        {
            ifs.read(&c, sizeof(c));
            s.append(1, c);
        }
        v.push_back(s);
    }
}

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStr(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}
