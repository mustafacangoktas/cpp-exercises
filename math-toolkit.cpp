#include <iostream>
#include <cmath>

using namespace std;

void showMenu() {
    cout << "-------------------------------" << endl;
    cout << "-         MATH TOOLKIT        -" << endl;
    cout << "-------------------------------" << endl;
    cout << "1 - Addition (a + b)" << endl;
    cout << "2 - Subtraction (a - b)" << endl;
    cout << "3 - Multiplication (a * b)" << endl;
    cout << "4 - Division (a / b)" << endl;
    cout << "5 - Power (a ^ b)" << endl;
    cout << "6 - Square Root (√a)" << endl;
    cout << "7 - Natural Log (ln a)" << endl;
    cout << "8 - Log Base 10 (log10 a)" << endl;
    cout << "0 - Exit" << endl;
}

int main() {
    int choice;
    double a = 0, b = 0;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        showMenu();
        cout << "Choose an operation (0-8): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        // Get inputs based on choice
        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number (a): ";
            cin >> a;
            cout << "Enter second number (b): ";
            cin >> b;
        } else if (choice >= 6 && choice <= 8) {
            cout << "Enter number (a): ";
            cin >> a;
        } else {
            cout << "Invalid selection! Please choose between 0-8." << endl;
            continue;
        }

        if (cin.fail()) {
            // Handle invalid input (non-numeric)
            cout << "Invalid input! Exiting program." << endl;
            break;
        }

        cout << "Result: ";
        switch (choice) {
            case 1:
                cout << a + b << endl;
                break;
            case 2:
                cout << a - b << endl;
                break;
            case 3:
                cout << a * b << endl;
                break;
            case 4:
                if (b != 0)
                    cout << a / b << endl;
                else
                    cout << "Error: Division by zero!" << endl;
                break;
            case 5:
                cout << pow(a, b) << endl;
                break;
            case 6:
                if (a >= 0)
                    cout << sqrt(a) << endl;
                else
                    cout << "Error: Cannot take square root of a negative number!" << endl;
                break;
            case 7:
                if (a > 0)
                    cout << log(a) << endl;
                else
                    cout << "Error: Logarithm undefined for non-positive numbers!" << endl;
                break;
            case 8:
                if (a > 0)
                    cout << log10(a) << endl;
                else
                    cout << "Error: Log10 undefined for non-positive numbers!" << endl;
                break;
            default:
                cout << "Unexpected error occurred!" << endl;
        }

        cout << endl << "Would you like to perform another operation? (y/n): ";
        cin >> again;
        cout << endl;
    }

    return 0;
}
