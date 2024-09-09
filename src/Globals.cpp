#include "globals.hpp"

Resolution currentResolution = RESOLUTION_1024x768;

int SCREEN_CENTER_X = currentResolution.width / 2;
int SCREEN_CENTER_Y = currentResolution.height / 2;

// Function to update the screen center
void updateScreenCenter() {
    SCREEN_CENTER_X = currentResolution.width / 2;
    SCREEN_CENTER_Y = currentResolution.height / 2;
}
