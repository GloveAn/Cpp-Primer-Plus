#include <iostream>
#include <string>

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

using namespace std;

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();

    highfink hf(ma, "Curly Kew");
    hf.ShowAll();

    cout << "Please enter a key for next phase:\n";
    cin.get();

    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    return 0;
}
