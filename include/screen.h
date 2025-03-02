/*
    ==============================================================
    screen.h

    This header file defines the structure and functions related
    to the game screen.
    It contains the `Screen` structure to store screen properties
    and a function to initialize the screen with given parameters.
    ==============================================================
*/

#ifndef SCREEN_H
#define SCREEN_H

/*
    Screen

    This structure holds information about the game window. It includes:
    - `width`: the width of the window (in pixels).
    - `height`: the height of the window (in pixels).
    - `title`: a string that defines the title of the window (displayed in the title bar).
*/
typedef struct {
    unsigned int width;  // The width of the window in pixels.
    unsigned int height; // The height of the window in pixels.
    char *title;         // The title displayed on the window's title bar.
} Screen;

/*
    init_Screen

    This function initializes a `Screen` structure with the specified
    width, height, and title for the game window. It assigns the provided
    parameters to the structure's fields and returns the initialized structure.

    Parameters:
        - `screen`: a pointer to the `Screen` structure to be initialized.
        - `width`: the width of the window (in pixels).
        - `height`: the height of the window (in pixels).
        - `title`: the title string to be displayed on the window's title bar.

    Returns:
        - The initialized `Screen` structure with the provided parameters.

    Example:
        Screen screen;
        init_Screen(&screen, 800, 600, "My Game Window");
*/
static Screen init_Screen(Screen *screen, unsigned int width, unsigned int height, char *title)
{
    screen->width = width;
    screen->height = height;
    screen->title = title;

    return *screen;
}

#endif