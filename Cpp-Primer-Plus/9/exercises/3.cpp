#include <iostream>
#include <cstring>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    chaff *c = new chaff[2];
    chaff *d = new (c) chaff[2];

    strcpy(d[0].dross, "ab");
    strcpy(d[1].dross, "cd");
    d[0].slag = 0;
    d[1].slag = 1;

    for(int i = 0; i < 2; i++)
        cout << d[i].dross << ": " << d[i].slag << endl;

    delete [] c;
    return 0;
}
