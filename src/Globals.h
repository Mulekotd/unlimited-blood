#pragma once

struct Resolution {
    int width;
    int height;
};

// Define default resolutions
constexpr Resolution RESOLUTION_800x600 = {800, 600};
constexpr Resolution RESOLUTION_1024x768 = {1024, 768};
constexpr Resolution RESOLUTION_1280x720 = {1280, 720};
constexpr Resolution RESOLUTION_1920x1080 = {1920, 1080};

// Define the current resolution as a global variable (initially 800x600)
extern Resolution currentResolution;

// Variables for the screen center position, calculated dynamically
extern int SCREEN_CENTER_X;
extern int SCREEN_CENTER_Y;

// Function to update the screen center position based on the current resolution
void updateScreenCenter();
