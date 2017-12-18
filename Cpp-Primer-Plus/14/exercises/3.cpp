#include <iostream>
#include <cstring>

#include "../14.10.h"

template <typename Type>
class QueueTp
{
private:
    int head, tail, size;
    Type * container;
public:
    QueueTp(int n);
    ~QueueTp();
    bool enqueue(const Type & item);
    bool dequeue(Type & item);
    bool is_empty() const { return head == tail; }
    bool is_full() const { return head == (tail + 1) % size; }
};

template <typename Type>
QueueTp<Type>::QueueTp(int n)
    : head(0), tail(0), size(n)
{
    container = new Type[size + 1];
}

template <typename Type>
QueueTp<Type>::~QueueTp()
{
    delete [] container;
}

template <typename Type>
bool QueueTp<Type>::enqueue(const Type & item)
{
    if(is_full())
        return false;
    container[tail++] = item;
    tail %= size;
    return true;
}

template <typename Type>
bool QueueTp<Type>::dequeue(Type & item)
{
    if(is_empty())
        return false;
    item = container[head++];
    head %= size;
    return true;
}

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker *wk;
    QueueTp<Worker *> lolas(SIZE);
    int ct;
    for(ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee Category:\n"
            << "w: waiter s:singer "
            << "t: singing waiter q: quit\n";
        cin >> choice;
        while(strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if(choice == 'q')
            break;
        switch(choice)
        {
            case 'w': wk = new Waiter;
                        break;
            case 's': wk = new Singer;
                        break;
            case 't': wk = new SingingWaiter;
                        break;
        }
        cin.get();
        wk->Set();
        lolas.enqueue(wk);
    }

    cout << "\nHere is your staff:\n";
    int i;
    for(i = 0; i < ct; i++)
    {
        cout << endl;
        lolas.dequeue(wk);
        wk->Show();
        delete wk;
    }

    cout << "Bye.\n";
    return 0;
}
