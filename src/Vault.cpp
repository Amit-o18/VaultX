#include<iostream>
#include<fstream>
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
            case 1:AddSecret();
            break;
            case 2:ViewSecret();
            break;
            case 3:DeleteSecret();
            break;
            case 4:LogOut();
            break;
            default:
            cout<<"Invalid choice\nTry Again.";
        }
    }
}

void VaultMenu::AddSecret(){
    string title,category,content;
    cin.ignore();
    cout<<"Add Title: ";
    getline(cin,title);
    cout<<"Category: ";
    getline(cin,category);
    cout<<"Add Content (Type END on a new line to finish): ";
    string temp;
    while(true){
        getline(cin,temp);
        if(temp=="END")
            break;
        content.append(temp);
        content.append("\n");
    }
    ofstream file("data/"+username+"/vault.dat",ios::app);
    if(file.is_open()){
        file<<"Title: "<<title<<"\n";
        file<<"Category: "<<category<<"\n";
        file<<"Content:\n"<<content<<"\n";
        file<<"--------------------\n";
        file.close();
        cout<<"Secret added successfully.\n";
    }else{
        cout<<"Error: Unable to open vault file.";
    }
}

void VaultMenu::ViewSecret(){
    string line;
    ifstream file("data/"+username+"/vault.dat");
    if(!file.is_open()){
        cout<<"Error: Unable to open vault file.";
        return;
    }else if(!getline(file,line)){
        cout << "Vault is empty.\n";
        return;
    }else{
        cout<<line<<"\n";
        while(getline(file,line)){
            cout<<line<<"\n";
        }
    }    
    file.close();
}

void VaultMenu::DeleteSecret(){
    cout << "Delete Credential\n";
}

void VaultMenu::LogOut(){
    cout << "Logged Out\n";
}

VaultMenu::VaultMenu(string user){
    username=user;
}