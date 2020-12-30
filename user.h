// Header for user functions
// Eugene Song v1.00

#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


class User {

private:
    string pin;
    string cardNo;
    int balance;

public:
    string name;
    User();
    User(string name, string cardNo, string pin, int balance);
    ~User();

    /*
     *  Checking PIN entry with User info.
     *  @param pin = user entered PIN
     *  @returns whether the PIN was correct
     */
    bool check_pin(string pin);
    /*
     *  @returns the current balance of the user
     */
    int getBalance();
    /*
     *  @returns the Pin of current user
     */
    string getPin();
    /*
     *  Adjusts the valance of the user by the given amount for deposit
     *  @param amount = the amount of adjustment to be made(positive for it will be the count of money)
     */
    void adjBalance(int amount);
    /*
     *  Withdraws a certain amount of money from account
     *  @param amount = the amount of adjustment to be made(positive for it will be the count of money)
     */
    void withdraw(int amount);
    

};



#endif //USER_H