#include <iostream>
#include <string>
// ANSI escape codes for text formatting and colors
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// Function to clear the command line
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

// Function to print a message with color
void printColoredMessage(const std::string& message, const std::string& color) {
    std::cout << color << message << RESET << std::endl;
}

int main() {
#ifdef __linux__
  std::cout << "Hey Linux";
#endif
#ifdef _WIN32
  std::cout << "Hey Windows";
#endif
    // clearScreen();
    std::string hi;
    // Example usage with different colors
    printColoredMessage("Hello, this is red text!", RED);
    printColoredMessage("This text is green.", GREEN);
    printColoredMessage("Another message in blue.", BLUE);
    std::cin >> hi;
    clearScreen();
    return 0;
}
