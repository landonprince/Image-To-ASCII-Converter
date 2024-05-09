#ifndef IMAGETOASCII_IMAGETOASCII_H
#define IMAGETOASCII_IMAGETOASCII_H

#include <opencv2/opencv.hpp>
#include <string>
#include <memory>

class ImageToASCII {
public:
    static ImageToASCII* instance();
    int uploadImage(const std::string& imagePath);
    std::string getImagePath();
    void convertToASCII();
    ImageToASCII(const ImageToASCII&) = delete;
    ImageToASCII& operator=(const ImageToASCII&) = delete;
    void displayASCII() const;

private:
    ImageToASCII() = default;
    static bool isSupported(const std::string &filename) ;
    std::unique_ptr<cv::Mat> image;
    std::string imageFilePath;
    static ImageToASCII* inst;
    std::string asciiArt;


};
#endif //IMAGETOASCII_IMAGETOASCII_H
