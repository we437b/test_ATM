// Implementation for user functions
// Eugene Song v1.00

#include "user.h"
#define USER_FILE "USER_INFO.INFO"

using namespace std;

//helper to set user info for readability
void setUserInfo(string tempName, string tempCard, int tempBal, int tempPin, struct user_info* temp) {
    temp->name = tempName;
    temp->cardNo = tempCard;
    temp->balance = tempBal;
    temp->pin = tempPin;
}

/*
 *  Function to load users from the file
 *  @param map : destination to load user_info structs
 */
void loadUsers(unordered_map<string, struct user_info*> map) {
    FILE *fp = fopen(USER_FILE, "r");
    int counter = 0;
    while(!feof(fp)) {
        struct user_info *temp = (struct user_info*) malloc(sizeof(struct user_info));

        // Reading user info
        fscanf(fp, "%s %s %i %i\n", &temp->name, &temp->cardNo, &temp->balance, &temp->pin);
        printf("%s %s %i %i\n", &temp->name, &temp->cardNo, &temp->balance, &temp->pin);

        
        //Setting User info
        //setUserInfo(tempName, tempCard, tempBal, tempPin, &temp);
        map.insert(make_pair(temp->cardNo, temp));
    }
    fclose(fp);
}

/*
 *  Function to authenticate user access to balance(withdrawal, etc)
 *  @param map : the map with user info loaded
 *  @param cardNo : current card trying to access user info
 *  @param pin : pin number the user entered
 *  @param auth : will become 1 if the authentication was successful
 */
void authenticate(unordered_map<char*, struct user_info*> map, char* cardNo, int pin, int* auth) {
    /*unordered_map<unsigned, struct user_info> map;
    if (cur.pin == pin) {
        cout << "authentication successful!" << endl;
        *auth = 1;
    } else {
        cout << "authentication failed!" << endl;
        *auth = 0;
    }*/
    return;
}
void adjustBalance(int amount, bool auth);
