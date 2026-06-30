#include<string>
using namespace std;
class AuthManager{
    public:
    bool masterPassExist();
    bool verifyPass(string username);
    void createMasterPass(string username);
};