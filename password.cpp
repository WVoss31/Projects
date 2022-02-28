#include <iostream>
#include <fstream>
#include <string>

void getInput();
void login();
void createUser();
void createPassword();
void createPassword(std::string username);

int main(){
    getInput();
}

void getInput(){
    std::cout << "Please enter a number: \n"
                "\n 1. Login"
                "\n 2. Sign up"
                "\n 3. Forgot Password\n"
                << std::endl;
    
    int answer;
    std::cin >> answer;

    switch (answer)
    {
    case 1:
        login();
        break;
    case 2:
        createUser();
        break;
    case 3:
        createPassword();
        break;
    default:
        std::cout << "Invalid Input. Exiting...\n";
        break;
    }
}

void login() {

    std::ifstream user;
    std::ifstream pass;
    std::hash<std::string> pass_hash;
    std::string username, password, storeuser, storepass;

    std::cout << "Please enter Username: \n";
    std::cin >> username;
    std::cout << "Please enter Password: \n";
    std::cin >> password;

    user.open("Users.txt");
    pass.open("Passwords.txt");

    while (user >> storeuser && pass >> storepass) {
        password = pass_hash(password);
        if (username == storeuser && password == storepass) {
            std::cout << "Welcome " << username << std::endl;
            break;
        }
    }
    std::cout << "Either your username or password is incorrect.\n";

    user.close();
    pass.close();
    
}

void createUser() {
    std::fstream newUser;
    std::string username;

    std::cout << "Please Enter your new username: \n";
    std::cin >> username;
    newUser.open("Users.txt");
    newUser << username << std::endl;
    newUser.close();
    createPassword();



}

void createPassword() {
    std::fstream newPass;
    std::string password;
    std::hash<std::string> str_hash;

    std::cout << "Please enter your new password: \n";
    std::cin >> password;
    newPass.open("Passwords.txt");
    newPass << str_hash(password) << std::endl;
    newPass.close();
}

void createPassword(std::string username) {

}