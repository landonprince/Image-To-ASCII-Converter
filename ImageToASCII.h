#ifndef IMAGETOASCII_IMAGETOASCII_H
#define IMAGETOASCII_IMAGETOASCII_H

#include <opencv2/opencv.hpp>
#include <string>
#include <memory>

class ImageToASCII {
public:
    static ImageToASCII* instance();
    ImageToASCII(const ImageToASCII&) = delete;
    ImageToASCII& operator=(const ImageToASCII&) = delete;

    int uploadImage(const std::string& imagePath);
    void convertToASCII();
    void displayASCII() const;
    [[nodiscard]] std::string getImagePath() const;

private:
    ImageToASCII() = default;
    static bool isSupported(const std::string &filename) ;

    static ImageToASCII* inst;
    std::unique_ptr<cv::Mat> image;
    std::string asciiArt;
    std::string imageFilePath;
};

#endif //IMAGETOASCII_IMAGETOASCII_H
