#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

std::string generatePassword(int length) {
    std::string password;
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}[]<>,.?/:;|";
    int numCharacters = characters.length();

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < length; i++) {
        int index = std::rand() % numCharacters;
        password += characters[index];
    }

    return password;
}

int main() {
    std::map<std::string, std::string> passwords;

    while (true) {
        std::cout << "1. Generate Password" << std::endl;
        std::cout << "2. Store Password" << std::endl;
        std::cout << "3. Retrieve Password" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int length;
            std::cout << "Enter password length: ";
            std::cin >> length;

            std::string password = generatePassword(length);
            std::cout << "Generated Password: " << password << std::endl;
        } else if (choice == 2) {
            std::string account, password;
            std::cout << "Enter account name: ";
            std::cin.ignore();
            std::getline(std::cin, account);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            passwords[account] = password;
            std::cout << "Password stored successfully!" << std::endl;
        } else if (choice == 3) {
            std::string account;
            std::cout << "Enter account name: ";
            std::cin.ignore();
            std::getline(std::cin, account);

            if (passwords.find(account) != passwords.end()) {
                std::cout << "Retrieved Password: " << passwords[account] << std::endl;
            } else {
                std::cout << "Account not found!" << std::endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}
