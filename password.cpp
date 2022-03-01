#include <iostream>
#include <fstream>
#include <string>

//function prototypes
void getInput();
void login();
void createUser();
void createPassword();
void createPassword(std::string username);

//main function
int main(){
    getInput();
}

/**
 * @brief Get the Input from the user
 * @details takes a number and calls the function that associates with the choice
 * @author Walker Voss
 */
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

/**
 * @brief Checks for valid username and password and logs you in if true
 * @bug Does not validate correctly
 * @author Walker Voss
 */
void login() {

    //initializing values I need
    std::fstream user;
    std::fstream pass;
    std::hash<std::string> pass_hash;
    std::string username, password, storeuser, storepass;
    bool matches = false;

    //prompt for input Note:std::getline(std::cin,username/password) wasn't working for some reason
    std::cout << "Please enter Username: \n";
    std::cin >> username;
    std::cout << "Please enter Password: \n";
    std::cin >> password;

    //open both files in READ mode
    user.open("Users.txt", std::fstream::in);
    pass.open("Passwords.txt", std::fstream::in);

    //while the streams can continue to store the values they read
    while (user >> storeuser && pass >> storepass) {
        //if username and the hashed password match, set matches = true and leave loop
        if (username == storeuser && pass_hash(password) == storepass) {
            matches = true;
            break;
        }
    }
    //either "logs you in" or doesn't
    if (matches == true) {
        std::cout << "Welcome " << username << std::endl;
    }
    else { std::cout << "Either your username or password is incorrect.\n"; }

    //close files
    user.close();
    pass.close();
}

/**
 * @brief Create a User and adds it to Users.txt
 * @author Walker Voss
 */
void createUser() {
    //initialize values
    std::fstream newUser;
    std::string username;

    //prompt for input Note:std::getline(std::cin,username) wasn't working for some reason
    std::cout << "Please Enter your new username: \n";
    std::cin >> username;
    //opens file in APPEND mode, if it was WRITE, it would create a whole new file from scratch and overright it
    newUser.open("Users.txt", std::ifstream::app);
    newUser << username << std::endl;
    //close file
    newUser.close();
    //since we are creating a "user" I called the createPassword() function
    createPassword();
}

/**
 * @brief Create a Password and add it to Passwords.txt file
 * @author Walker Voss
 */
void createPassword() {
    //initialize values
    std::fstream newPass;
    std::string password;
    std::hash<std::string> str_hash;

    //prompt for input Note:std::getline(std::cin,password) wasn't working for some reason
    std::cout << "Please enter your new password: \n";
    std::cin >> password;
    //opens file in APPEND mode, if it was WRITE, it would create a whole new file from scratch and overright it
    newPass.open("Passwords.txt", std::ifstream::app);
    
    newPass << str_hash(password) << std::endl;
    newPass.close();
}

/**
 * @brief Create a new Password for the given user
 * @param username 
 * @todo jump to the place in the file where the password associated with the given user is stored, and overwrite it
 * @author Walker Voss
 */
void createPassword(std::string username) {

}