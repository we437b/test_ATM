// Implementation for user functions
// Eugene Song v1.00

#include "user.h"
#define USER_FILE "USER_INFO.INFO"

using namespace std;

User::User() {
}

User::User(string name, string cardNo, string pin, int balance) {
    this->name = name;
    this->cardNo = cardNo;
    this->pin = pin;
    this->balance = balance;
}

User::~User() {
}

bool User::check_pin(string pin) {
    if (this->pin == pin) {
        return true;
    }
    return false;
}

int User::getBalance() {
    return this->balance;
}

string User::getPin() {
    return this->pin;
}

void User::adjBalance(int amount) {
    this->balance += amount;
}

void User::withdraw(int amount) {
    if (this->balance - amount < 0) {
        cout << "Insufficient funds." << endl;
        return;
    }
    else {
        this->balance -= amount;
        cout << "Your withdrawal of $" << amount << " was successful.\nRemaining balance : $" << this->balance << endl;
    }
}