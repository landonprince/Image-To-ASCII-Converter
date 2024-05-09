// By: Landon Prince (5/9/2024)

#include "ImageToASCII.h"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <fstream>

ImageToASCII* ImageToASCII::inst = nullptr;

ImageToASCII* ImageToASCII::instance() {
    if (!inst) {
        inst = new ImageToASCII;
    }
    return inst;
}

int ImageToASCII::loadImage(const std::string& imagePath) {
    if (!isSupported(imagePath)) {
        std::cerr << "Unsupported file format." << std::endl;
        return -1;
    }
    if (!std::filesystem::exists(imagePath)) {
        std::cerr << "File does not exist." << std::endl;
        return -1;
    }
    imageFilePath = imagePath;
    std::unique_ptr<cv::Mat> newImage = std::make_unique<cv::Mat>();
    *newImage = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (newImage->empty()) {
        std::cerr << "Failed to load image. Please check the file path and integrity." << std::endl;
        return -1;
    }
    image = std::move(newImage);
    std::cout << "Image successfully loaded." << std::endl;
    return 0;
}

int ImageToASCII::convertToASCII() {
    if (!image) {
        std::cerr << "No image loaded." << std::endl;
        return -1;
    }

    const char* levels = "@%#*+=-:. ";
    size_t scale = 255 / (strlen(levels) - 1);
    std::string result;

    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            auto brightness = image->at<uchar>(i, j);
            char ascii_char = levels[brightness / scale];
            result += ascii_char;
        }
        result += '\n';
    }
    asciiArt = result;
    std::cout << "Image successfully converted to ASCII." << std::endl;
    return 0;
}

int ImageToASCII::displayASCII() const {
    if (!asciiArt.empty()) {
        std::ofstream file("ascii.txt");
        if (file.is_open()) {
            file << asciiArt;
            file.close();
            std::cout << "ASCII art has been saved to ascii.txt" << std::endl;
            return 0;
        } else {
            std::cerr << "Unable to open file to save ASCII art." << std::endl;
            return -1;
        }
    } else {
        std::cerr << "Failed to convert image to ASCII." << std::endl;
        return -1;
    }
}

[[maybe_unused]] std::string ImageToASCII::getImagePath() const {
    return imageFilePath;
}

bool ImageToASCII::isSupported(const std::string &filename) {
    const std::set<std::string> supportedExtensions = {
            ".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff", ".webp", ".jp2"
    };
    std::string extension = std::filesystem::path(filename).extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return supportedExtensions.find(extension) != supportedExtensions.end();
}