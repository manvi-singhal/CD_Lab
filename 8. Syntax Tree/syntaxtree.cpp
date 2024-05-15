#include <iostream>
#include <stack>

using namespace std;

struct SyntaxTreeNode
{
    string value;
    SyntaxTreeNode *left;
    SyntaxTreeNode *right;

    SyntaxTreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

bool isOperator(string token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

SyntaxTreeNode *constructSyntaxTree(string postfixExpression[], int size)
{
    stack<SyntaxTreeNode *> st;

    for (int i = 0; i < size; ++i)
    {
        SyntaxTreeNode *newNode = new SyntaxTreeNode(postfixExpression[i]);

        if (isOperator(postfixExpression[i]))
        {
            SyntaxTreeNode *rightNode = st.top();
            st.pop();
            SyntaxTreeNode *leftNode = st.top();
            st.pop();
            newNode->left = leftNode;
            newNode->right = rightNode;
        }

        st.push(newNode);
    }

    return st.top();
}

void printInfix(SyntaxTreeNode *root)
{
    if (root != nullptr)
    {
        if (isOperator(root->value))
        {
            cout << "(";
        }
        printInfix(root->left);
        cout << root->value;
        printInfix(root->right);
        if (isOperator(root->value))
        {
            cout << ")";
        }
    }
}

void printSyntaxTree(SyntaxTreeNode *root, string prefix, bool isLeft)
{
    if (root != nullptr)
    {
        cout << prefix << (isLeft ? "|-- " : "\\-- ") << root->value << endl;
        printSyntaxTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
        printSyntaxTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
    }
}

int main()
{
    string postfixExpression[] = {"3", "4", "+", "5", "*"};
    int size = sizeof(postfixExpression) / sizeof(postfixExpression[0]);

    SyntaxTreeNode *root = constructSyntaxTree(postfixExpression, size);

    cout << "Syntax Tree:" << endl;
    printSyntaxTree(root, "", true);

    cout << "\nInfix expression: ";
    printInfix(root);

    return 0;
}
