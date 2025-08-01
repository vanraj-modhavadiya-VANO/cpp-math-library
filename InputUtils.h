#ifndef INPUTUTILS_H
#define INPUTUTILS_H

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>

namespace InputUtils {

    // Prompt the user for an integer with validation
    inline int getInt(
            const std::string& prompt = "Enter an integer: ",
            int min = std::numeric_limits<int>::min(),
            int max = std::numeric_limits<int>::max(),
            bool allowDefault = false,
            int defaultValue = 0,
            const std::string& errorMsg = "Invalid input. Please enter a valid integer."
    ){
        std::string line;
        int value;

        while (true)
        {
            std::cout << prompt;

            if(allowDefault){
                std::cout << " [" << defaultValue <<"]";
            }
            
            std::cout << ": ";
            std::getline(std::cin, line);

            // Use default if input is empty and default is allowed
            if(allowDefault && line.empty()){
                return defaultValue;
            }

            std::istringstream iss(line);
            if(iss >> value && iss.eof()){
                if(value >= min && value <= max){
                    return value;
                } else {
                    std::cout << "Input must be between " << min << " and " << max << ".\n";
                    continue;
                }
            }

            std::cout << errorMsg << std::endl;
        }
    }

    // Prompt the user for a floating-point number with validation
    inline double getDouble(const std::string& prompt = "Enter a number: ",
        int min = std::numeric_limits<int>::min(),
        int max = std::numeric_limits<int>::max(),
        bool allowDefault = false,
        double defaultValue = 0.0,
        const std::string& errrorMsg = "Invalid input. Please enter a valid number."
    ) {
    std::string line;
    double value;

    while (true)
    {
        std::cout << prompt;
        if (allowDefault) {
            std::cout << " [" << defaultValue << "]";
        }
        std::cout << ": ";

        std::getline(std::cin, line);

        // Use default if input is empty and default is allowed
        if (allowDefault && line.empty()) {
            return defaultValue;
        }

        std::istringstream iss(line);
        if (iss >> value && iss.eof()) {
            if (value >= min && value <= max) {
                return value;
            } else {
                std::cout << "Input must be between " << min << " and " << max << ".\n";
                continue;
            }
        }

        std::cout << "Invalid input. Please enter a valid number.\n";
    }
}


    // Prompt the user for a full line of text
    inline std::string getLine(const std::string& prompt = "Enter a line: ") {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }

    // Prompt the user for a yes/no confirmation
    inline bool getYesNo(const std::string& prompt = "Continue (y/n): ") {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            if (input.empty()) continue;
            char c = std::tolower(static_cast<unsigned char>(input[0]));
            if (c == 'y') return true;
            if (c == 'n') return false;
            std::cout << "Please enter 'y' or 'n'.\n";
        }
    }

    // Wait for the user to press Enter
    inline void waitForEnter(const std::string& prompt = "Press Enter to continue...") {
        std::cout << prompt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Prompt the user for a menu choice between min and max
    inline int getMenuChoice(int min, int max, const std::string& prompt = "Choose an option: ") {
        int choice;
        while (true) {
            std::cout << prompt;
            if (std::cin >> choice && choice >= min && choice <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Enter a number between " << min << " and " << max << ".\n";
        }
    }

}

#endif // INPUTUTILS_H
