#include <iostream>
#include <string>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" // Include the header file

using namespace std;

const int width = 256;  // Image width
const int height = 256; // Image height
unsigned char image[height][width][3]; // Color image array (RGB)

// Function to initialize the image with colorful patterns
void initializeColorfulImage() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            image[j][i][0] = i;           // Red channel (gradient horizontally)
            image[j][i][1] = j;           // Green channel (gradient vertically)
            image[j][i][2] = (i + j) % 256; // Blue channel (diagonal gradient)
        }
    }
}

int main() {
    // Initialize colorful image
    initializeColorfulImage();

    // Ask the user for a file path
    string filePath;
    cout << "Enter the file path to save the colorful image (e.g., Amit.png): ";
    cin >> filePath;

    // Save the image as PNG
    if (stbi_write_png(filePath.c_str(), width, height, 3, image, width * 3)) {
        cout << "Image saved successfully at " << filePath << endl;
    } else {
        cerr << "Error: Failed to save image at " << filePath << endl;
    }

    return 0;
}
