#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::displayMenu()
{
    cout << "--------------------\n--------------------";
    cout << "          VaultX" << endl;
    cout << "--------------------\n--------------------";
    cout << "\n1. Add Credential\n2. View Credentials\n3. Search Credential\n4. Delete Credential\n5. Exit";
}

int Menu::getChoice()
{
    int choice;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

void Menu::run()
{

    bool run = true;
    while (run)
    {
        displayMenu();
        int choice = getChoice();
        switch (choice)
        {
        case 1:cout<<"Add Credential Selected."<<endl;
            break;

        case 2:cout<<"View Credential Selected."<<endl;
            break;

        case 3:cout<<"Search Credential Selected."<<endl;
            break;

        case 4:cout<<"Delete Credential Selected."<<endl;
            break;

        case 5:cout<<"Exited..."<<endl;
            run = false;
            break;

        default:
            cout<<"Invalid Choice! Try Again."<<endl;
            break;
        }
    }
}
