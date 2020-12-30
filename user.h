// Header for user functions
// Eugene Song v1.00

#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


struct user_info {
    string name;
    int balance;
    string cardNo;
    int pin;
};

void loadUsers(unordered_map<string, struct user_info*> map);

void authenticate(unordered_map<string, struct user_info*> map, long int cardNo, int pin, int* auth);

void adjustBalance(int amount, bool auth);




#endif //USER_H