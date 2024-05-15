#include <bits/stdc++.h>
using namespace std;

int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

void check()
{
    strcpy(ac, "REDUCE: ");
    for (z = 0; z < c; z++)
    {
        if (stk[z] == 'b')
        {
            printf("%sB -> b", ac);
            stk[z] = 'B';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
        }
    }

    for (z = 0; z < c - 1; z++)
    {
        if (stk[z] == 'a')
        {
            printf("%sA -> a", ac);
            stk[z] = 'A';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 1;
        }
    }

    for (z = 0; z < c - 1; z++)
    {
        if (stk[z] == 'A' && stk[z + 1] == 'B')
        {
            printf("%sS -> AB", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 1;
        }
    }
    return;
}

int main()
{
    printf("GRAMMAR is -\nS -> AB \nA -> a \nB -> b\n");
    strcpy(a, "abab");
    c = strlen(a);
    strcpy(act, "SHIFT");
    printf("\nstack \t input \t action");
    printf("\n$\t%s$\t", a);
    for (i = 0; j < c; i++, j++)
    {
        printf("%s", act);
        stk[i] = a[j];
        stk[i + 1] = '\0';
        a[j] = ' ';
        printf("\n$%s\t%s$\t", stk, a);
        check();
    }
    check();
    if (stk[0] == 'S' && stk[1] == '\0')
        printf("Accept\n");
    else
        printf("Reject\n");
}
