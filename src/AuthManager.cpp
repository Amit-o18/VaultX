#include <iostream>
#include "../include/AuthManager.h"
#include <filesystem>
#include <fstream>
using namespace std;
bool AuthManager::masterPassExist()
{
    return filesystem::exists("data/master.hash");
}

void AuthManager::createMasterPass()
{
    string masterPass;
    string confirmPass;
    bool valid = false, confirm = false;
    while (!(valid && confirm)){
        cout << "Enter Your Master Password (Min 8 characters): ";
        getline(cin, masterPass);

        if (masterPass.length() < 8){
            cout<<"Password must contain at least 8 characters.\n";
            valid = false;
            continue;
        }
        else{
            valid = true;
        }
        if (valid){
            cout << "Confirm the password again: ";
            getline(cin, confirmPass);

            if (masterPass == confirmPass){
                confirm = true;
                ofstream file("data/master.hash");
                if(file.is_open()){
                    file<<masterPass;
                    file.close();
                    cout << "Master password created successfully.\n";
                }else{
                    cout << "Failed to create master password file.\n";
                }
            }
            else{
                confirm = false;
                valid=false;
                cout << "Passwords do not match! Try again." << endl;
            }
        }
    }
}

// bool AuthManager::verifyPass()
// {
//     return
// }
