#include "Customs\automatedDetection.hpp"  // Include the header file for the class
#include "main.h"
using namespace pros;
autoDetectionClass autoDetection;
char autoDetectionClass::teamColor[4];  // Define the static variable

char autoDetectionClass::detectRingColor() {
    char colordet = 'a';  // Default color set to 'a' for unidentified
    int colorDetected = color.get_hue();

    // Detect color through hue
    if (0 < colorDetected && colorDetected < 30) {
        colordet = 'r';  // Red
    } else if (50 < colorDetected && colorDetected < 70) {
        colordet = 'y';  // Yellow
    } else if (180 < colorDetected && colorDetected < 240) {
        colordet = 'b';  // Blue
    }

    printf("%c", colordet);  // Print the detected color
    return colordet;         // Return the detected color
}

const char* autoDetectionClass::teamColorDetection() {
    char detectedColor = detectRingColor();
    if (detectedColor == 'r') {
        return "red";
    } else if (detectedColor == 'b') {
        return "blue";
    } else {
        return "dne";  // Default case or handling for yellow/others
    }
}