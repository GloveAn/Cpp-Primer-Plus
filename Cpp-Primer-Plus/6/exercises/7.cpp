#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string word;
    int vowel = 0, consonants = 0, other = 0;

    cout << "Enter words (q to quit):" << endl;
    while(cin >> word && word != "q")
    {
        if(isalpha(word[0]))
        {
            if(word[0] == 'a'
            || word[0] == 'e'
            || word[0] == 'i'
            || word[0] == 'o'
            || word[0] == 'u')
            {
                vowel++;
            }
            else
            {
                consonants++;
            }
        }
        else
        {
            other++;
        }
    }
    cout << vowel << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << other << " others" << endl;

    return 0;
}
