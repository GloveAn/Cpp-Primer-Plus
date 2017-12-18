#include <iostream>
#include "list.h"

void sum(type &t)
{
    using namespace std;
    cout << t << endl;
}

int main()
{
    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.visit(sum);
    return 0;
}
