#include <iostream>

using namespace std;

int get_scores(double scores[])
{
    int i;

    cout << "Enter scores (q to quit): " << endl;
    for(i = 0; i < 10; i++)
    {
        if(!(cin >> scores[i]))
            break;
        cout << "Enter scores (q to quit): " << endl;
    }

    return i;
}

void print_scores(double scores[], int n)
{
    cout << "scores: ";
    for(int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

void average_scores(double scores[], int n)
{
    double average = 0;

    for(int i = 0; i < n; i++)
    {
        average += scores[i];
    }
    average /= n;
    cout << "average: " << average << endl;
}

int main()
{
    int n;
    double scores[10];

    n = get_scores(scores);
    print_scores(scores, n);
    average_scores(scores, n);

    return 0;
}
