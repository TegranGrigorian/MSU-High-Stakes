#include "main.h"
#include "stdio.h"

using namespace pros;
class autoDetectionClass {
    public:
    
    char teamColor[5] = "none";

    static char detectRingColor() {// returns bool side, 0 is red and blue is 1
        char colordet = 'a'; // we want this code to detect multiple colors so we set the value detected to the first letter of the color, ie red = r.
        int colorDetected = color.get_hue();
        //detect color through hue
        if (0< colorDetected <30) {
            return colordet = 'r'; //
        } else if (50 < colorDetected < 70) {
            return colordet = 'y';
        } else if (180 < colorDetected < 240) {
            return colordet = 'b';
            
        }
        printf("%c" , colordet);

    }

    static void teamColorDetection(char* teamColor) { // set a global string to be a determinate of what team we are so we can implemente detection in other functions
        char detectedColor = detectRingColor();
        if (detectedColor == 'r') {
            strcpy(teamColor, "red");
        } else if (detectedColor == 'b') {
            strcpy(teamColor, "blue");
        } else {
            strcpy(teamColor, "dne"); // Default case or handling for 'y' and other cases
        }   
        printf("%s" , teamColor);
    }

};
