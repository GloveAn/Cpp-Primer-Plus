#include <iostream>

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove()const;
    Move add(const Move & m)const;
    void reset(double a = 0, double b = 0);
};

Move::Move(double a, double b)
{
    reset(a, b);
}

void Move::showmove() const
{
    using std::cout;
    cout << "(" << x << ", " << y << ")\n";
}

Move Move::add(const Move & m) const
{
    return Move(x + m.x, y + m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    Move a(1, 2);
    Move b;

    a.showmove();
    b.showmove();
    a.add(a).showmove();
    a.reset();
    a.showmove();

    return 0;
}
