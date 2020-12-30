#include "user.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    while (true) {
        int* auth;
        printf("Loading...\n");
        unordered_map<string, struct user_info*> users;
        loadUsers(users);
        printf("Please insert your card(enter your card number)\n");
        string cardInput;
        scanf("%s", &cardInput);
        printf("%s", users.find("4539644431265203")->second->name);
        /*printf("Please input your pin number\n");
        int pinInput;
        scanf("%d", &pinInput);
        authenticate(users, cardInput, pinInput, auth);*/

    }
}