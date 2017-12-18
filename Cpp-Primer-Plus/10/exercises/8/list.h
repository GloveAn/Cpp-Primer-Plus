#ifndef HEADER_LIST
#define HEADER_LIST

typedef int type;

class List
{
private:
    static const int LENGTH = 20;
    type store[LENGTH];
    int index;
public:
    List();
    List &add(const type &t);
    bool isempty() const { return index == 0; }
    bool isfull() const { return index == LENGTH; }
    void visit(void (*f)(type &));
};

#endif
