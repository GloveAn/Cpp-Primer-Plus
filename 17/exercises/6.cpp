#include <iostream>
#include <fstream>
#include <string>
//#include <cstdlib>

const int MAX = 10;
const char *file = "employees.txt";

enum classkind { Employee, Manager, Fink, Highfink };

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
            const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::ofstream &ofs);
    virtual void GetAll(std::ifstream &ifs);
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};

abstr_emp::abstr_emp()
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
                    const std::string & j)
    : fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
    std::cout << "fname: " << fname << ", lname: " << lname << ", job: " << job;
}

void abstr_emp::SetAll()
{
    using std::cin;
    using std::cout;

    cout << "Enter fname: ";
    cin >> fname;
    cout << "Enter lname: ";
    cin >> lname;
    cout << "Enter job: ";
    cin >> job;
}

void abstr_emp::WriteAll(std::ofstream &ofs)
{
    ofs << fname << std::endl;
    ofs << lname << std::endl;
    ofs << job << std::endl;
}

void abstr_emp::GetAll(std::ifstream &ifs)
{
    ifs >> fname;
    ifs >> lname;
    ifs >> job;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.fname << ", " << e.lname;
}

abstr_emp::~abstr_emp()
{
}

class employee: public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
            const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::ofstream &ofs);
    virtual void GetAll(std::ifstream &ifs);
};

employee::employee()
{
}

employee::employee(const std::string & fn, const std::string & ln,
                    const std::string & j)
    : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << std::endl;
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::WriteAll(std::ofstream &ofs)
{
    ofs << Employee << std::endl;
    abstr_emp::WriteAll(ofs);
}

void employee::GetAll(std::ifstream &ifs)
{
    abstr_emp::GetAll(ifs);
}

class manager: virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::ofstream &ofs);
    virtual void GetAll(std::ifstream &ifs);
};

manager::manager()
{
}

manager::manager(const std::string & fn, const std::string & ln,
                const std::string & j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp & e, int ico)
    : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager & m)
    : abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << ", in charge of: " << inchargeof << std::endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter in charge of: ";
    std::cin >> inchargeof;
}

void manager::WriteAll(std::ofstream &ofs)
{
    ofs << Manager << std::endl;
    abstr_emp::WriteAll(ofs);
    ofs << inchargeof << std::endl;
}

void manager::GetAll(std::ifstream &ifs)
{
    abstr_emp::GetAll(ifs);
    ifs >> inchargeof;
}

class fink: virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
        const std::string & j, const std::string & rpt);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::ofstream &ofs);
    virtual void GetAll(std::ifstream &ifs);
};

fink::fink()
{
}

fink::fink(const std::string & fn, const std::string & ln,
            const std::string & j, const std::string & rpt)
    : abstr_emp(fn, ln, j), reportsto(rpt)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo)
    : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e)
    : abstr_emp(e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << ", reports to: " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reports to: ";
    std::cin >> reportsto;
}

void fink::WriteAll(std::ofstream &ofs)
{
    ofs << Fink << std::endl;
    abstr_emp::WriteAll(ofs);
    ofs << reportsto << std::endl;
}

void fink::GetAll(std::ifstream &ifs)
{
    abstr_emp::GetAll(ifs);
    ifs >> reportsto;
}

class highfink: public manager, public fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
            const std::string & j, const std::string & rpt,
            int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::ofstream &ofs);
    virtual void GetAll(std::ifstream &ifs);
};

highfink::highfink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln,
                    const std::string & j, const std::string & rpt,
                    int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpt)
{
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink & f, int ico)
    : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager & m, const std::string & rpo)
    : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink & h)
    : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << ", in charge of: " << manager::InChargeOf()
        << ", reports to: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
    using std::cout;
    using std::cin;

    abstr_emp::SetAll();
    cout << "Enter in charge of: ";
    cin >> manager::InChargeOf();
    cout << "Enter reports to: ";
    cin >> fink::ReportsTo();
}

void highfink::WriteAll(std::ofstream &ofs)
{
    ofs << Highfink << std::endl;
    abstr_emp::WriteAll(ofs);
    ofs << manager::InChargeOf() << std::endl;
    ofs << fink::ReportsTo() << std::endl;
}

void highfink::GetAll(std::ifstream &ifs)
{
    abstr_emp::GetAll(ifs);
    ifs >> manager::InChargeOf();
    ifs >> fink::ReportsTo();
}

int main()
{
    using namespace std;

    abstr_emp *ae[MAX];
    int type;
    int i = 0;
    ifstream fin;

    fin.open(file);
    if(fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file: \n";
        fin >> type;
        while(!fin.eof())
        {
            switch(type)
            {
                case Employee:
                    ae[i] = new employee();
                    break;
                case Manager:
                    ae[i] = new manager();
                    break;
                case Fink:
                    ae[i] = new fink();
                    break;
                case Highfink:
                    ae[i] = new highfink();
                    break;
            }
            ae[i]->GetAll(fin);
            ae[i]->ShowAll();
            i++;
            fin >> type;
        }
    }
    fin.close();

    ofstream fout(file, ios::out | ios::app);
    if(!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter type you want to create (q to quit): \n";
    while(cin >> type && i < MAX)
    {
        switch(type)
        {
            case Employee:
                ae[i] = new employee();
                break;
            case Manager:
                ae[i] = new manager();
                break;
            case Fink:
                ae[i] = new fink();
                break;
            case Highfink:
                ae[i] = new highfink();
                break;
        }
        ae[i]->SetAll();
        ae[i]->WriteAll(fout);
        i++;
        cout << "Enter type you want to create (q to quit): \n";
    }
    fout.close();
    cin.clear();

    cout << "Here are the new contents of the "
        << file << " file: \n";
    for(int j = 0; j < i; j++)
        ae[j]->ShowAll();

    cout << "Done.\n";
    return 0;
}
