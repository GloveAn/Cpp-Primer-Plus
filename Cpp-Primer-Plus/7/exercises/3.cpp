#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

box b = {"an", 1, 2, 3, 0};

void print_box(box b)
{
    cout << "maker: " << b.maker << ", "
        << "height: " << b.height << ", "
        << "width: " << b.width << ", "
        << "length: " << b.length << ", "
        << "volume: " << b.volume << ", "
        << endl;
}

void set_box_volume(box *b)
{
    b->volume = b->height * b->width * b-> length;
}

int main()
{
    set_box_volume(&b);
    print_box(b);
    return 0;
}
