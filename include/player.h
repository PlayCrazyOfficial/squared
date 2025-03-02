#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

/*
    Player

    This structure represents a player in the game. It stores the player's
    attributes, such as size, color, movement speed, position, and score.

    Attributes:
        - `size`: the width and height of the player (assumed to be a square).
        - `color`: the color of the player, represented by a `Color` type from raylib.
        - `velocity`: the movement speed of the player (in pixels per frame).
        - `x`: the horizontal position of the player (in pixels).
        - `y`: the vertical position of the player (in pixels).
        - `score`: the player's current score, which can be incremented during the game.
*/
typedef struct {
    unsigned int size;     // The size (width/height) of the player square.
    Color color;           // The color of the player, using raylib's Color type.
    unsigned int velocity; // The speed at which the player moves (in pixels per frame).
    int x;                  // The x-coordinate (horizontal position) of the player.
    int y;                  // The y-coordinate (vertical position) of the player.
    unsigned int score;    // The player's score, incremented as the player achieves goals.
} Player;

/*
    init_Player

    This function initializes a `Player` structure with the provided attributes.
    It assigns values to the player's size, color, velocity, position, and score.

    Parameters:
        - `player`: a pointer to the `Player` structure to be initialized.
        - `size`: the size of the player (width/height of the square).
        - `color`: the color of the player (a `Color` value from raylib).
        - `velocity`: the movement speed of the player (in pixels per frame).
        - `x`: the initial x-coordinate (horizontal position) of the player.
        - `y`: the initial y-coordinate (vertical position) of the player.
        - `score`: the initial score of the player.

    Returns:
        - The initialized `Player` structure with the provided values.

    Example:
        Player player;
        init_Player(&player, 25, WHITE, 5, 100, 100, 0);
*/
static Player init_Player(Player *player, unsigned int size, Color color, unsigned int velocity, int x, int y, unsigned int score)
{
    player->size = size;
    player->color = color;
    player->velocity = velocity;
    player->x = x;
    player->y = y;
    player->score = score;

    return *player;
}

/*
    draw_Player

    This function draws the player on the screen as a filled rectangle using
    the player's color at the player's current position.

    Parameters:
        - `player`: the `Player` structure containing the player's attributes.

    Example:
        draw_Player(player);
*/
static void draw_Player(Player player)
{
    DrawRectangle(player.x, player.y, player.size, player.size, player.color);
}

/*
    move_Player

    This function updates the player's position based on user input (arrow keys).
    The player can move within the boundaries of the screen, ensuring they
    don't move off the edge.

    Parameters:
        - `player`: a pointer to the `Player` structure that will be updated.
        - `screenWidth`: the width of the game screen.
        - `screenHeight`: the height of the game screen.

    Example:
        move_Player(&player, screen.width, screen.height);
*/
static void move_Player(Player *player, int screenWidth, int screenHeight)
{
    // Move the player to the right if the right arrow key is pressed, and if within bounds
    if (IsKeyDown(KEY_RIGHT) && player->x + player->size < screenWidth) player->x += player->velocity;

    // Move the player to the left if the left arrow key is pressed, and if within bounds
    if (IsKeyDown(KEY_LEFT) && player->x > 0) player->x -= player->velocity;

    // Move the player up if the up arrow key is pressed, and if within bounds
    if (IsKeyDown(KEY_UP) && player->y > 0) player->y -= player->velocity;

    // Move the player down if the down arrow key is pressed, and if within bounds
    if (IsKeyDown(KEY_DOWN) && player->y + player->size < screenHeight) player->y += player->velocity;
}

#endif