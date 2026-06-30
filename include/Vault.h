#include <string>

class VaultMenu{
    private:
        std::string username;
    public:
        VaultMenu(std::string user);
        void showMenu();      
        void AddSecret();
        void ViewSecret();
        void DeleteSecret();
        void LogOut();
};