#include<iostream>
#include "../include/UserMenu.h"
#include "../include/UserManager.h"
using namespace std;

void UserMenu::showMenu(){
    int choice=0;
    UserManager U;
    while(choice!=5){
        cout << "1. Create User\n";
        cout << "2. Delete User\n";
        cout << "3. List Users\n";
        cout << "4. Login\n";
        cout << "5. Exit..\n";

        cout<<"Enter Your Choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:U.createUser();
            break;
            case 2: U.deleteUser();
            break;
            case 3:U.listUsers();
            break;
            case 4:U.loginUser();
            break;
            case 5: cout<<"Exited...";
            break;
            default:
            cout<<"Invalid Choice!\nTry again.";
        }
    }
}