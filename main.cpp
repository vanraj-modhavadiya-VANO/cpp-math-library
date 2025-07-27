#include "InputUtils.h"

int main() {
    // Get an integer
    int myInt = InputUtils::getInt("Enter an integer: ");
    std::cout << "You entered: " << myInt << "\n\n";

    // Get a double
    double myDouble = InputUtils::getDouble("Enter a floating-point number: ");
    std::cout << "You entered: " << myDouble << "\n\n";

    // Get a line of text
    std::string myText = InputUtils::getLine("Enter a line of text: ");
    std::cout << "You entered: \"" << myText << "\"\n\n";

    // Get a yes/no response
    bool confirmed = InputUtils::getYesNo("Do you want to continue (y/n)? ");
    std::cout << (confirmed ? "You chose to continue.\n\n" : "You chose not to continue.\n\n");

    // Menu selection
    std::cout << "Menu:\n";
    std::cout << "1. Option One\n";
    std::cout << "2. Option Two\n";
    std::cout << "3. Option Three\n";
    int choice = InputUtils::getMenuChoice(1, 3, "Choose an option (1-3): ");
    std::cout << "You selected option: " << choice << "\n\n";

    // Wait for enter
    InputUtils::waitForEnter("Press Enter to exit...");

    return 0;
}
