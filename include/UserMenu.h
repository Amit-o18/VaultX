#include<string>

class UserMenu{
    public:
    bool userExist(const std::string &username);
    void createUser(const std::string &username);
    void deleteUser(const std::string &username);
    void showMenu();
    void listUsers();
};

class VaultMenu{
    public:
    void AddCredential();
    void ViewCredential();
    void DeleteCredential();
    void LogOut();
};