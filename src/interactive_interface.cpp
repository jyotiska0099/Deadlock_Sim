#include "interactive_interface.h"
#include <iostream>

void InteractiveInterface::run() {
    std::cout << "Interactive Interface Started." << std::endl;
    while (true) {
        std::cout << "1. Allocate Resource" << std::endl;
        std::cout << "2. Release Resource" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string resourceName;
                std::cout << "Enter Resource Name: ";
                std::cin >> resourceName;
                allocateResource(resourceName);
                break;
            }
            case 2: {
                std::string resourceName;
                std::cout << "Enter Resource Name: ";
                std::cin >> resourceName;
                releaseResource(resourceName);
                break;
            }
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void InteractiveInterface::allocateResource(const std::string& resourceName) {
    std::cout << "Allocating resource: " << resourceName << std::endl;
    // Update resource allocation graph here
}

void InteractiveInterface::releaseResource(const std::string& resourceName) {
    std::cout << "Releasing resource: " << resourceName << std::endl;
    // Update resource allocation graph here
}
