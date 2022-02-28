#include <iostream>
#include <fstream>
#include <string>

void getInput();
void login();
void createUser();
void createPassword();

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

}

void createUser() {

}

void createPassword() {

}