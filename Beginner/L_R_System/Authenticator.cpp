#include "Authenticator.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

Authenticator::Authenticator(){
    ifstream file("../../L_R_System/usernames_passwords.txt");
    if(file.is_open()){
        string line;
        int pos;
        while(getline(file, line)){
            pos = line.find(" ");
            this->username = line.substr(0, pos);
            this->password = line.substr(pos+1);
            this->user_passwords[this->username] = this->password;
        }
    }
    else{
        cout << "Isuue opening file\n";
        perror("Error");
    }
    file.close();
};
Authenticator::~Authenticator(){
    cout << "Authenticator object destroyed\n";
}

void Authenticator::display(){
        

};
bool Authenticator::login(){

    while (true){
    cout << "Please enter Username";
    cin >> this->username;
    auto it = this->user_passwords.find(this->username);
    if (it != this->user_passwords.end()){
        break;
    }
    else{
        cout << "Username not found";
        return false;
    }
    }


    cout << "Please enter password";
    cin >> this->password;
    if(this->user_passwords[username] != this->password){
        "Incorect password\n";
        return false;
    }
    cout << "Succesfully logged in!\n";
    return true;
};

bool Authenticator::register_user(){
    //system("cls");
    string id;
    string password;
    string new_user;
    while(true){
        cout << "Please enter a username to use: ";
        cin >> id;
        auto it = this->user_passwords.find(id);
        if(it == this->user_passwords.end()){
            break;
        }
        else{
            cout << "Username is taken. Please select another one.\n";;
        }
    }

    cout << "Please enter a password: ";
    cin >> password;
    new_user += id + " " + password + "\n";
    ofstream file("../../L_R_System/usernames_passwords.txt", ios::app);
    file << new_user;
    file.close();
    return true;
};
void Authenticator::forgot_password(){
    system("cls");
    int option;
    string id;
    while(true){
        cout << "Press 1 to look up password\n";
        cout << "Press 2 to return to main menu";
        switch (option){
            case (1):
                cout << "Enter Id: ";
                cin >> id;
                if (this->user_passwords.count(id) == 0 ){
                    cout << id << " is not found in database\n";
                }
                else{
                    cout << "Password is: " << this->user_passwords[id] << "\n";
                    return; 
                }
                break;
            case(2):
                system("cls");
                return;
            
            default:
                cout << "Invalid option";
                break;
        }
    }
};