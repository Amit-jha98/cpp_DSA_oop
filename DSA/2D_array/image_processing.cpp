#include <iostream>
#include <string>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

const int width = 256;
const int height = 256;
unsigned char image[height][width][3];

void initializeColorfulImage() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            image[j][i][0] = i;
            image[j][i][1] = j;
            image[j][i][2] = (i + j) % 256;
        }
    }
}

int main() {
    initializeColorfulImage();

    string filePath;
    cout << "Enter the file path to save the colorful image (e.g., Amit.png): ";
    cin >> filePath;

    if (stbi_write_png(filePath.c_str(), width, height, 3, image, width * 3)) {
        cout << "Image saved successfully at " << filePath << endl;
    } else {
        cerr << "Error: Failed to save image at " << filePath << endl;
    }

    return 0;
}
