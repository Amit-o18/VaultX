#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
#include"../include/Vault.h"
#include "../include/UserManager.h"
#include "../include/AuthManager.h"

namespace fs = std::filesystem;
bool UserManager::userExists(const string& username){
    return fs::exists("data/"+username);
}

void UserManager::createUser(){
    cin.ignore();
    string username;
    cout<<"Enter UserName: ";
    getline(cin,username);
    if(userExists(username)){
         cout << "User already exists!\n";
    }else{
        fs::create_directories("data/"+username);
        // ofstream masterFile("data/"+username+"/master.hash");
        ofstream vaultFile("data/"+username+"/vault.dat");
        
        AuthManager A;
        A.createMasterPass(username);
        // masterFile.close();
        vaultFile.close();
        cout << "User created successfully!\n";
    }
}

void UserManager::loginUser(){
    AuthManager A;
    string username;
    cout<<"Enter username: ";
    cin>>username;
    if(userExists(username)){
        cout<<"User Found.."<<endl;
        if(A.verifyPass(username)){
            cout<<"Login Successful!\n";
            VaultMenu V(username);
            V.showMenu();
        }else{
            cout<<"Login Failed!\n";
        }

    }else{
        cout<<"User Not Found.."<<endl;
    }
}

void UserManager::deleteUser(){
    
}
void UserManager::listUsers(){

}