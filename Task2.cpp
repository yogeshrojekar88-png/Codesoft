#include <iostream>
using namespace std;

int main()
{
    float num1, num2;
    char op;

    cout << "Enter First Number: ";
    cin >> num1;

    cout << "Enter Second Number: ";
    cin >> num2;

    cout << "Choose an Operation (+, -, *, /): ";
    cin >> op;

    switch(op)
    {
        case '+':
            cout << "Addition = " << num1 + num2;
            break;

        case '-':
            cout << "Subtraction = " << num1 - num2;
            break;

        case '*':
            cout << "Multiplication = " << num1 * num2;
            break;

        case '/':
            if(num2 != 0)
                cout << "Division = " << num1 / num2;
            else
                cout << "Error! Division by zero is not allowed.";
            break;

        default:
            cout << "Invalid Operator!";
    }

    return 0;
}