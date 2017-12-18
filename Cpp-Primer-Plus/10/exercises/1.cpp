#include <iostream>
#include <string>

class Account
{
private:
    std::string name;
    long id;
    double balance;
public:
    Account(const std::string &n, long i = 0, double b = 0);
    bool deposit(double);
    bool withdraw(double);
    void show() const;
};

Account::Account(const std::string &n, long i, double b)
{
    name = n;
    id = i;
    balance = b;
}

bool Account::deposit(double d)
{
    balance += d;
}

bool Account::withdraw(double d)
{
    using std::cout;

    if(d > balance)
    {
        cout << "You don't have enough money.\n";
        cout << "Operation aborted.\n";
    }
    else
    {
        balance -= d;
    }
}

void Account::show() const
{
    using std::cout;
    using std::endl;

    cout << name << ": #" << id << ": $" << balance << endl;
}

int main()
{
    Account a("glove", 100203, 20);
    a.show();
    a.deposit(3000);
    a.show();
    a.withdraw(20);
    a.show();
    a.withdraw(2000000);
    a.show();
    return 0;
}
