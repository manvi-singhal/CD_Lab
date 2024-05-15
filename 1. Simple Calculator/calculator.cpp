#include <iostream>
using namespace std;
int main() {
    char op;
    double num1, num2;
    while (true) {
        cout << "Enter an operator (+, -, *, /), or 'x' to exit: ";
        cin >> op;
        if (op == 'x')
            break;
        cout << "Enter the first and second operand: ";
        cin >> num1 >> num2;

        switch (op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                if(num2 != 0.0)
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                else
                    cout << "Division by zero error!" << endl;
                break;
            default:
                cout << "Error! Operator is not correct" << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}
