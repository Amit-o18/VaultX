#include <iostream>
#include "../include/AuthManager.h"
#include <filesystem>
#include <fstream>
#include <thread>
#include <chrono>
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
    while (!(valid && confirm))
    {
        cout << "Enter Your Master Password (Min 8 characters): ";
        getline(cin, masterPass);

        if (masterPass.length() < 8)
        {
            cout << "Password must contain at least 8 characters.\n";
            valid = false;
            continue;
        }
        else
        {
            valid = true;
        }
        if (valid)
        {
            cout << "Confirm the password again: ";
            getline(cin, confirmPass);

            if (masterPass == confirmPass)
            {
                confirm = true;
                ofstream file("data/master.hash");
                if (file.is_open())
                {
                    file << masterPass;
                    file.close();
                    cout << "Master password created successfully.\n";
                }
                else
                {
                    cout << "Failed to create master password file.\n";
                }
            }
            else
            {
                confirm = false;
                valid = false;
                cout << "Passwords do not match! Try again." << endl;
            }
        }
    }
}

bool AuthManager::verifyPass(string username)
{
    string masterPath="data/"+username+"/master.hash";
    string vaultPath="data/"+username+"/vault.dat+";
    ifstream file("masterPath");    
    string existPass = "";
    if (file.is_open())
    {
        getline(file, existPass);
        file.close();
    }
    else
    {
        return false;
    }
    int attempts = 3;
    string masterPass = "";

    while (attempts > 0)
    {

        cout << "Enter Master Password: ";

        getline(cin, masterPass);
        if (masterPass == existPass)
        {
            return true;
        }
        else
        {
            attempts--;
            cout << "Wrong Password! Try Again!\n";
            cout << "You have " << attempts << " attempts left!" << endl;
            if (attempts == 0)
            {
                for (int i = 30; i > 0; i--)
                {
                    cout << "\rToo many failed attempts. Try again in "
                         << i << " seconds..." << flush;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                cout << "\n";
                attempts = 3;
            }
        }
    }
    return false;
}
