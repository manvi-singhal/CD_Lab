#include <iostream>
#include <string>

using namespace std;

int main()
{
    char parentNonTerminal;
    string gram, part1, part2, modifiedGram, newGram;

    cout << "Enter Parent Non-Terminal: ";
    cin >> parentNonTerminal;
    cin.ignore();

    cout << "Enter Production for " << parentNonTerminal << " -> ";
    getline(cin, gram);

    size_t pos = gram.find('|');
    part1 = gram.substr(0, pos);
    part2 = gram.substr(pos + 1);

    size_t i = 0, j = 0, k = 0;
    for (i = 0; i < part1.length() && i < part2.length(); i++)
    {
        if (part1[i] == part2[i])
        {
            modifiedGram += part1[i];
            k++;
            pos = i + 1;
        }
    }
    modifiedGram += 'X';

    newGram = part1.substr(pos) + '|' + part2.substr(pos);

    cout << "\nGrammar Without Left Factoring:\n";
    cout << parentNonTerminal << "->" << modifiedGram << endl;
    cout << "X->" << newGram << endl;

    return 0;
}
