#include<iostream>
#include"../include/Vault.h"
using namespace std;

void VaultMenu::showMenu(){
    int choice=0;
    while(choice!=4){
        cout<<"1. Add Credential. "<<endl;
        cout<<"2. View Credential. "<<endl;
        cout<<"3. Delete Credential. "<<endl;
        cout<<"4. Log Out. "<<endl;
        
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:AddCredential();
            break;
            case 2:ViewCredential();
            break;
            case 3:DeleteCredential();
            break;
            case 4:LogOut();
            break;
            default:
            cout<<"Invalid choice\nTry Again.";
        }
    }
}

void VaultMenu::AddCredential()
{
    cout << "Add Credential\n";
}

void VaultMenu::ViewCredential()
{
    cout << "View Credential\n";
}

void VaultMenu::DeleteCredential()
{
    cout << "Delete Credential\n";
}

void VaultMenu::LogOut()
{
    cout << "Logged Out\n";
}

VaultMenu::VaultMenu(string user){
    username=user;
}