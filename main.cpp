// By: Landon Prince (5/9/2024)

#include "ImageToASCII.h"
#include <iostream>

/**
* Entry point of the program. Facilitates imageToASCII
*/
int main() {
    std::cout << "\n-- Image to ASCII (C++ Edition) --\n";
    std::cout << "     By: Landon Prince\n\n";
    ImageToASCII *converter = ImageToASCII::instance();

    std::string imagePath;
    std::cout << "Enter the file path of your image:\n";
    std::cout << "Example: C:\\pictures\\image.jpg\n\n";
    std::cout << "Image path: ";
    std::getline(std::cin, imagePath);
    std::cout << std::endl;

    if (converter->loadImage(imagePath) != 0) {
        std::cerr << "Failed to load image.\n";
        return 1;
    }
    if (converter->convertToASCII() != 0) {
        std::cerr << "Failed to convert image to ASCII.\n";
        return 1;
    }
    if (converter->displayASCII() != 0) {
        std::cerr << "Failed to display ASCII art.\n";
        return 1;
    }
    std::cout << "\nThank you for converting!\n";
    return 0;
}

