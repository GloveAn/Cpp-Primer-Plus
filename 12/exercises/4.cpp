#include <iostream>

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX=10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for(int i = 0; i < st.top; i++)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if(isfull())
        return false;
    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item & item)
{
    if(isempty())
        return false;
    item = pitems[--top];
    return true;
}

Stack &Stack::operator=(const Stack &st)
{
    if(this == &st)
        return *this;
    delete [] pitems;

    pitems = new Item[st.size];
    for(int i = 0; i < st.top; i++)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;
}

int main()
{
    using namespace std;

    Item t;

    Stack a;
    Stack b(a);
    Stack c;

    a.push(1);
    c = a;
    cout << "a is empty? " << a.isempty() << endl;
    cout << "b is empty? " << b.isempty() << endl;
    cout << "c is empty? " << c.isempty() << endl;
    c.push(2);
    a.pop(t);
    cout << "pop a: " << t << endl;
    c.pop(t);
    cout << "pop c: " << t << endl;

    return 0;
}
