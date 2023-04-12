#include <iostream>

using namespace std;

// Function to authenticate the user with a PIN
bool authenticate(int pin, int attempts) {
    int enteredPin;
    cout << "Enter PIN: ";
    cin >> enteredPin;
    if (enteredPin == pin) {
        return true;
    } else {
        attempts++;
        cout << "Incorrect PIN. Attempts left: " << 3 - attempts << endl;
        if (attempts < 3) {
            return authenticate(pin, attempts);
        } else {
            cout << "Too many incorrect attempts. Exiting..." << endl;
            return false;
        }
    }
}

// Function to reset or change PIN
void resetPin(int& pin) {
    int newPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    pin = newPin;
    cout << "PIN successfully changed." << endl;
}

// Function to check balance
void checkBalance(int pin, int balance) {
    if (authenticate(pin, 0)) {
        cout << "Your current balance is: $" << balance << endl;
    }
}

// Function to send money
void sendMoney(int pin, int& balance) {
    if (authenticate(pin, 0)) {
        int amount;
        cout << "Enter amount to send: $";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Money sent successfully." << endl;
        }
    }
}

int main() {
    int pin = 0000; // Default PIN
    int balance = 1000; // Default balance
    int option;

    do {
        cout << "Welcome to Everest Mobile Money!" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Send money" << endl;
        cout << "3. Reset/Change PIN" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                checkBalance(pin, balance);
                break;
            case 2:
                sendMoney(pin, balance);
                break;
            case 3:
                resetPin(pin);
                break;
            case 4:
                cout << "Thank you for using Everest Mobile Money. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    return 0;
}

