#ifndef SQUARE_H
#define SQUARE_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>

/*
    Square

    This structure represents a square object in the game. It holds the
    attributes necessary to define and draw a square on the screen.

    Attributes:
        - `size`: the width and height of the square.
        - `color`: the color of the square, represented by a `Color` type from raylib.
        - `x`: the x-coordinate (horizontal position) of the square on the screen.
        - `y`: the y-coordinate (vertical position) of the square on the screen.
*/
typedef struct {
    unsigned int size;  // The size (width/height) of the square.
    Color color;        // The color of the square (raylib's Color type).
    int x;               // The x-coordinate (horizontal position) of the square.
    int y;               // The y-coordinate (vertical position) of the square.
} Square;

/*
    init_Square

    This function initializes a `Square` structure with the provided size
    and color. The position of the square is not initialized and should
    be set separately (e.g., by calling `summon_Square`).

    Parameters:
        - `square`: a pointer to the `Square` structure to be initialized.
        - `size`: the size (width/height) of the square.
        - `color`: the color of the square (a `Color` value from raylib).

    Returns:
        - The initialized `Square` structure with the provided size and color.

    Example:
        Square square;
        init_Square(&square, 15, YELLOW);
*/
static Square init_Square(Square *square, unsigned int size, Color color)
{
    square->size = size;
    square->color = color;

    return *square;
}

/*
    summon_Square

    This function randomly places a square on the screen within the given
    screen boundaries. The square's position is updated to new random
    values for `x` and `y` within the screen's width and height.

    Parameters:
        - `square`: a pointer to the `Square` structure whose position will
          be updated.
        - `screenWidth`: the width of the game screen (used to constrain the
          random x-coordinate).
        - `screenHeight`: the height of the game screen (used to constrain
          the random y-coordinate).

    Example:
        summon_Square(&square, screen.width, screen.height);
*/
static void summon_Square(Square *square, int screenWidth, int screenHeight)
{
    srand(time(NULL));  // Seed the random number generator.

    // Generate random x and y coordinates within screen bounds.
    square->x = 0 + rand() % (screenWidth + 1);
    square->y = 0 + rand() % (screenHeight + 1);
}

/*
    draw_Square

    This function draws the square on the screen at its current position
    using the square's color and size.

    Parameters:
        - `square`: the `Square` structure containing the position and color.

    Example:
        draw_Square(square);
*/
static void draw_Square(Square square)
{
    // Draw the square at its current position with its size and color.
    DrawRectangle(square.x, square.y, square.size, square.size, square.color);
}

#endif