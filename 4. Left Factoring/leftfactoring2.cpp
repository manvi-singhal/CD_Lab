#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ch, lhs[20][20], rhs[20][20][20], temp[20], temp1[20];
    int n, n1, count[20], x, y, i, j, k, c[20];

    cout << "\nEnter the no. of nonterminals : ";
    cin >> n;
    n1 = n;
    for (i = 0; i < n; i++)
    {
        cout << "\nNonterminal " << i + 1 << "\nEnter the no. of productions : ";
        cin >> c[i];
        cout << "\nEnter LHS : ";
        cin >> lhs[i];

        for (j = 0; j < c[i]; j++)
        {
            cout << lhs[i] << "->";
            cin >> rhs[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        count[i] = 1;
        while (memcmp(rhs[i][0], rhs[i][1], count[i]) == 0)
            count[i]++;
    }
    for (i = 0; i < n; i++)
    {
        count[i]--;
        if (count[i] > 0)
        {
            strcpy(lhs[n1], lhs[i]);
            strcat(lhs[i], "'");

            for (k = 0; k < count[i]; k++)
                temp1[k] = rhs[i][0][k];
            temp1[k++] = '\0';

            for (j = 0; j < c[i]; j++)
            {
                for (k = count[i], x = 0; k < strlen(rhs[i][j]); x++, k++)
                    temp[x] = rhs[i][j][k];
                temp[x++] = '\0';
                if (strlen(rhs[i][j]) == 1)
                    strcpy(rhs[n1][1], rhs[i][j]);
                strcpy(rhs[i][j], temp);
            }
            c[n1] = 2;
            strcpy(rhs[n1][0], temp1);
            strcat(rhs[n1][0], lhs[n1]);
            strcat(rhs[n1][0], "'");
            n1++;
        }
    }
    cout << "\n\nThe resulting productions are : \n";
    for (i = 0; i < n1; i++)
    {
        if (i == 0)
            cout << "\n " << lhs[i] << " -> " << (char)238 << "|";
        else
            cout << "\n " << lhs[i] << " -> ";
        for (j = 0; j < c[i]; j++)
        {
            cout << " " << rhs[i][j] << " ";
            if ((j + 1) != c[i])
                cout << "|";
        }
        cout << "\b\b\b\n";
    }

    return 0;
}
