#include <iostream>
#include "../include/AuthManager.h"
#include"../include/UserManager.h"
#include"../include/UserMenu.h"
using namespace std;
int main(){

    
    UserMenu U;
    U.showMenu();
    // AuthManager A;
    // cout<<A.masterPassExist()<<endl;
     
    // if (!A.masterPassExist()){
    //     A.createMasterPass();
    // }else{
    //     // A.verifyPass();
    //     if(A.verifyPass()){
    //         cout << "Access granted.\n";
    //     }else{
    //         cout << "Access denied.\n";
    //     }
    // }
    
}