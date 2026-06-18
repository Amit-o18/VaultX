#include <iostream>
#include "../include/AuthManager.h"
using namespace std;
int main(){
    AuthManager A;
    // cout<<A.masterPassExist()<<endl;
     
    if (!A.masterPassExist()){
        A.createMasterPass();
    }else{
        // A.verifyPass();
        cout<<"verify later.";
    }
    
}