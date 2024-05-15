#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<vector<char>> precedence = {
    {'/', '1'},
    {'*', '1'},
    {'+', '2'},
    {'-', '2'}};

int precedenceOf(char token)
{
    for (size_t i = 0; i < precedence.size(); i++)
    {
        if (token == precedence[i][0])
        {
            return precedence[i][1] - '0';
        }
    }
    return -1;
}

int main()
{
    int i, j, opc = 0;
    char token;
    vector<vector<string>> operators(10, vector<string>(2));
    string expr, temp;
    bool processed[expr.length()] = {false};

    cout << "\nEnter an expression for calculating Address codes: ";
    getline(cin, expr);

    for (i = 0; i < expr.length(); i++)
    {
        processed[i] = false;
    }

    for (i = 0; i < expr.length(); i++)
    {
        token = expr[i];
        for (j = 0; j < precedence.size(); j++)
        {
            if (token == precedence[j][0])
            {
                operators[opc][0] = token;
                operators[opc][1] = to_string(i);
                opc++;
                break;
            }
        }
    }

    cout << "\nOperators: \nOperators \tLocation number\n";
    for (i = 0; i < opc; i++)
    {
        cout << operators[i][0] << "\t\t" << operators[i][1] << endl;
    }

    for (i = opc - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (precedenceOf(operators[j][0][0]) > precedenceOf(operators[j + 1][0][0]))
            {
                temp = operators[j][0];
                operators[j][0] = operators[j + 1][0];
                operators[j + 1][0] = temp;
                temp = operators[j][1];
                operators[j][1] = operators[j + 1][1];
                operators[j + 1][1] = temp;
            }
        }
    }

    cout << "\nOperators sorted in their precedence: \nOperators \tLocation number \n";
    for (i = 0; i < opc; i++)
    {
        cout << operators[i][0] << "\t\t" << operators[i][1] << endl;
    }

    cout << endl;
    for (i = 0; i < opc; i++)
    {
        j = stoi(operators[i][1]);
        string op1 = "", op2 = "";
        if (processed[j - 1])
        {
            if (precedenceOf(operators[i - 1][0][0]) == precedenceOf(operators[i][0][0]))
            {
                op1 = "t" + to_string(i);
            }
            else
            {
                for (int x = 0; x < opc; x++)
                {
                    if ((j - 2) == stoi(operators[x][1]))
                    {
                        op1 = "t" + to_string(x + 1);
                    }
                }
            }
        }
        else
        {
            op1 = expr[j - 1];
        }
        if (processed[j + 1])
        {
            for (int x = 0; x < opc; x++)
            {
                if ((j + 2) == stoi(operators[x][1]))
                {
                    op2 = "t" + to_string(x + 1);
                }
            }
        }
        else
        {
            op2 = expr[j + 1];
        }
        cout << "t" << (i + 1) << " = " << op1 << operators[i][0] << op2 << endl;
        processed[j] = processed[j - 1] = processed[j + 1] = true;
    }

    return 0;
}
