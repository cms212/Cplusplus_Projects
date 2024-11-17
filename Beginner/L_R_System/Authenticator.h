#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H
#include<string>
#include<map>
using namespace std;

class Authenticator{
    private:
        string username;
        string password;
        map<string, string> user_passwords;
    
    public:
        Authenticator();
        ~Authenticator();
        void display();
        bool login();
        bool register_user();
        void forgot_password();

};

#endif