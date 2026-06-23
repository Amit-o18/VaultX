#pragma once
#include<string>

class UserManager{
    public:
    bool userExists(const std::string& username);
    void loginUser();
    void createUser();
    void deleteUser();
    void listUsers();
};