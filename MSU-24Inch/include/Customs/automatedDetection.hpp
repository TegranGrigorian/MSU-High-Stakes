#ifndef AUTOMATEDDETECTION_HPP
#define AUTOMATEDDETECTION_HPP

class autoDetectionClass {
    public:
    static char teamColor[4]; // Static variable to store team color
    static char detectRingColor(); // Function to detect ring color
    static void teamColorDetection(char* teamColor); // Function to set team color
};

extern autoDetectionClass autoDetection; // Declare an instance of the class

#endif // AUTOMATEDDETECTION_H
