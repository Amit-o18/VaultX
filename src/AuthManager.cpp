#include<iostream>
#include "../include/AuthManager.h"
#include<filesystem>
using namespace std;
bool AuthManager::masterPassExist(){
    return filesystem::exists("data/master.hash");
}

