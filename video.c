#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
// Constants for bytes per pixel
    const int bytesPerPixelColor = 3;  // 24 bits for color
    const int bytesPerPixelBW = 1;    // 8 bits for black-and-white

    // Frame sizes (in bytes)
    int frameSizeColor = w * h * bytesPerPixelColor;
    int frameSizeBW = w * h * bytesPerPixelBW;

    // Total sizes for each section (in bytes)
    int totalSizeColor = frameSizeColor * fps * durationMovie;
    int totalSizeBW = frameSizeBW * fps * durationCredits;

    // Total video size in bytes
    int totalSizeBytes = totalSizeColor + totalSizeBW;

    // Convert to desired unit
    float size = 0;
    if (strcmp(unit, "bt") == 0) {
        size = totalSizeBytes * 8;  // Convert to bits
    } else if (strcmp(unit, "ko") == 0) {
        size = (totalSizeBytes * 8) / 1024.0;  // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = (totalSizeBytes * 8) / (1024.0 * 1024.0);  // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        size = (totalSizeBytes * 8) / (1024.0 * 1024.0 * 1024.0);  // Convert to gigabits
    } else {
        size = -1;  // Invalid unit
    }
   // YOUR CODE HERE - END
    return size;
}

