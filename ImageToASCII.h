#ifndef IMAGETOASCII_IMAGETOASCII_H
#define IMAGETOASCII_IMAGETOASCII_H

#include <opencv2/opencv.hpp>
#include <string>
#include <memory>

class ImageToASCII {
public:
    /**
    * Singleton pattern to get the instance of ImageToASCII.
    * @return Pointer to the singleton instance of ImageToASCII.
    */
    static ImageToASCII* instance();

    // Prevent copying and assignment.
    ImageToASCII(const ImageToASCII&) = delete;
    ImageToASCII& operator=(const ImageToASCII&) = delete;

    /**
     * Loads an image from a given file path.
     * @param imagePath Path to the image file to be loaded.
     * @return 0 if the image is successfully loaded, -1 otherwise.
     */
    int loadImage(const std::string& imagePath);

    /**
     * Converts the loaded image to ASCII art.
     * @return 0 if the conversion is successful, -1 otherwise.
     */
    int convertToASCII();

    /**
     * Displays the ASCII art, typically by writing it to a file.
     * @return 0 if the ASCII art is successfully displayed, -1 otherwise.
     */
    [[nodiscard]] int displayASCII() const;

    /**
     * Retrieves the path of the currently loaded image.
     * @return The file path of the loaded image.
     */
    [[maybe_unused]] [[nodiscard]] std::string getImagePath() const;

private:
    // Default constructor for the singleton pattern.
    ImageToASCII() = default;

    /**
     * Checks if the given file has a supported format for conversion.
     * @param filename The name of the file to check.
     * @return true if the file format is supported, false otherwise.
     */
    static bool isSupported(const std::string &filename);

    static ImageToASCII* inst;
    std::unique_ptr<cv::Mat> image;
    std::string asciiArt;
    std::string imageFilePath;
};

#endif //IMAGETOASCII_IMAGETOASCII_H
