// Tariq Shallow
// November 2, 2026

#include <iostream>
#include <string>
#include "Lab04.h"

using namespace std;

int main()
{
    string word1;
    string word2;

    do
    {
        cout << "Enter the first word: ";
        cin >> word1;

        cout << "Enter the second word: ";
        cin >> word2;

        cout << "First word: " << word1 << endl;
        cout << "Second word: " << word2 << endl;

        if (aal::Anagram(word1) == aal::Anagram(word2))
            cout << "They are anagrams of each other" << endl;
        else
            cout << "They are not anagrams of each other" << endl;

        cout << endl;

    } while (aal::Anagram(word1) != aal::Anagram(word2));

    return 0;
}
