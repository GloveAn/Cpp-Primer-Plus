#include "list.h"

List::List()
{
    index = 0;
}

List &List::add(const type &t)
{
    if(index < LENGTH)
        store[index++] = t;
}

void List::visit(void (*f)(type &))
{
    for(int i = 0; i < index; i++)
        f(store[i]);
}
