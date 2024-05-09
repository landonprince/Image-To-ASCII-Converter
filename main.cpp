#include "ImageToASCII.h"

int main() {
    ImageToASCII* converter = ImageToASCII::instance();
    if (converter->uploadImage("C:\\test\\test.jpg") == 0) {
        std::cout << "Image successfully loaded." << std::endl;
    } else {
        std::cerr << "Failed to load image." << std::endl;
        return -1;
    }
    std::cerr << converter->getImagePath() << std::endl;
    converter->convertToASCII();
    converter->displayASCII();
}

