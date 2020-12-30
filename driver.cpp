#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#define USER_INFO "USER_INFO.INFO"
using namespace std;

string menu = "\n 1. Check Balance\n 2. Withdraw\n 3. Deposit\n 4. Quit";

User fetch_users(string cardNo) {
    ifstream readServer;
    readServer.open(USER_INFO);
    while (!readServer.eof() && readServer.is_open()) {

        // Temporary Fields
        string tempName;
        string tempCard;
        string tempPin;
        int tempBal;

        readServer >> tempName;
        readServer >> tempCard;
        readServer >> tempBal;
        readServer >> tempPin;

        //If found, return the user
        if (cardNo == string(tempCard)) {
            readServer.close();
           return User(tempName, tempCard, tempPin, tempBal);
        }
    }

    readServer.close();
    cout << "Card information cannot be found. Please try again!" << endl;
    throw 1;
}

void line() {
    cout << "*******************************************************************************************" << endl;
}



void main(void) {
    while (true) {
        line();
        // User info fetched from server(simulated)
        cout << "Hello, Please insert your Credit Card (insert Credit Card No.)" << endl;
        string cardIn;
        
        //Card Read should be implemented according to ATM
        cin >> cardIn;
        User curUser;

        // If User info cannot be found, reset for next customer
        try {
            curUser = fetch_users(cardIn);
        } catch (int i) {
            continue;
        }

        // Check PIN, 5 times maximum
        int i;
        for (i = 0; i < 5; i++) {
            string tempPin;
            cout << "Welcome " << curUser.name << ", Please enter your PIN" << endl;
            cin >> tempPin;
            if (curUser.check_pin(tempPin)) {
                cout << "Authorized\n" << endl;
                break;
            }
            else {
                cout << "Incorrect PIN number. Please try again.\nYou have " << 4 - i << " attemts remaining." << endl;
            }
        }

        if (i == 5) {
            cout << "Too many attempts. Please try again later\n" << endl;
            continue;
        }

        // User usage start
        while (true) {
            int userIn;
            int amount;
            line();
            cout << "Please Choose from the following Options." << endl;
            cout << menu << endl;
            cin >> userIn;
            if (userIn == 1) {
                cout << "Your Current Balance is: $" << curUser.getBalance() << endl;
            }
            else if (userIn == 2) {
                cout << "Please enter the amount of money you would like to withdraw." << endl;
                cin >> amount;
                curUser.withdraw(amount);
            }
            else if (userIn == 3) {
                cout << "Please Insert Cash. (Enter the amount in integer)" << endl;
                cin >> amount;
                curUser.adjBalance(amount);
                cout << "Your deposit of $" << amount << " was successful.\nRemaining Balance is $" << curUser.getBalance() << endl;
            }
            else if (userIn == 4) {
                break;
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }


        // Getting all data from file for editing

        ifstream infs(USER_INFO);
        vector<string> data;
        string temp;
        int rel = 0;
        while (!infs.eof()) {
            infs >> temp;
            //edits the only for the current user data
            if (rel == 0) {
                if (temp == cardIn) {
                    rel += 2;
                }
                data.push_back(temp);
            }
            else if (rel == 2) {
                data.push_back(to_string(curUser.getBalance()));
                rel -= 1;
            }
            else if (rel == 1) {
                data.push_back(curUser.getPin());
                rel -= 1;
            }
        }
        infs.close();
        
        //Updating user data file
        ofstream ofs(USER_INFO);
        string space = " ";
        data.pop_back();
        while (!data.empty()) {
            for (int i = 0; i < 4; i++) {
                ofs << data.front();
                ofs << space;
                data.erase(data.begin());
            }
            ofs << endl;
        }
        ofs.close();

        cout << " Thank you for using Bank of Lorem. Have a good Day!\n" << endl;
        cout << "****************************New User Session***********************************************" << endl;
    }
}