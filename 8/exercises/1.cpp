#include <iostream>

using namespace std;

int count = 0;

void print_string(const char string[], int flag = 0)
{
    count++;
    int c = flag ? count : 1;
    for(int i = 0; i < c; i++)
        cout << string << endl;
}

int main()
{
    print_string("abc");
    print_string("bcd", 0);
    print_string("cde", 1);
    print_string("def");
    return 0;
}
