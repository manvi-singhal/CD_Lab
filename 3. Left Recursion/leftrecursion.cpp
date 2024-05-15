#include<iostream>
#include<string>
using namespace std;

int main() {
    string ip, op1, op2, temp;
    char c;
    int n;

    cout << "Enter the Parent Non-Terminal : ";
    cin >> c;
    ip.push_back(c);
    op1 += ip + "->";
    op2 += ip + "\'->";

    cout << "Enter the number of productions : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter Production " << i + 1 << " : ";
        cin >> temp;
        if (temp[0] == c) {
            temp.erase(0, 1);
            op2 += temp + c + "\'|";
        } else {
            op1 += temp + c + "\'|";
        }
    }
    op1 += "#";
    op2 += "#";
    cout << "New Productions without Left Recursion:\n";
    cout << op1 << endl;
    cout << op2 << endl;

    return 0;
}
