#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
  int sizeImg ;
  sizeImg = w*h*3;
      // Convert the size to the desired unit
    
    if (strcmp(unit, "bt") == 0) {           // Convert to bits
        sizeImg = sizeImg * 8;
    } else if (strcmp(unit, "ko") == 0) {    // Convert to kilobits
        sizeImg = (sizeImg * 8) / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {    // Convert to megabits
        sizeImg = (sizeImg * 8) / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) {    // Convert to gigabits
        sizeImg = (sizeImg * 8) / (1024.0 * 1024.0 * 1024.0);
    } else {
        // Handle invalid unit
        sizeImg = -1;  // Return -1 for an invalid unit
    }
   // YOUR CODE HERE - END
   return sizeImg;
}