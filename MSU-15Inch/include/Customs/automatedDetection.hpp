#ifndef AUTOMATEDDETECTION_H
#define AUTOMATEDDETECTION_H

class autoDetectionClass {
    public:
    char teamColor[5];
    static char detectRingColor();
    static void teamColorDetection(char* teamColor);
};
autoDetectionClass autoDetection;
#endif // AUTOMATEDDETECTION_H