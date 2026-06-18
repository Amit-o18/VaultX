#include <iostream>
#include "../include/AuthManager.h"
using namespace std;
int main(){
    AuthManager A;
    // cout<<A.masterPassExist()<<endl;
     
    if (A.masterPassExist()){
        cout<<"Master Pass Exist";
    }else{
        cout<<"Master Pass does not Exist";
    }
}