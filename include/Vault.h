#include <string>

class VaultMenu{
    private:
        std::string username;
    public:
        VaultMenu(std::string user);
        void showMenu();      
        void AddCredential();
        void ViewCredential();
        void DeleteCredential();
        void LogOut();
};