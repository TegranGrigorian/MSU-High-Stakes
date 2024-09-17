#include "Customs\automatedDetection.hpp"  // Include the header file for the class
#include "main.h"
using namespace pros;

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

void autoDetectionClass::teamColorDetection(char* teamColor) {
    char detectedColor = detectRingColor();

    if (detectedColor == 'r') {
        strcpy(teamColor, "red");
    } else if (detectedColor == 'b') {
        strcpy(teamColor, "blue");
    } else {
        strcpy(teamColor, "dne");  // Default case or handling for yellow/others
    }

    printf("%s", teamColor);  // Print the team color
}
