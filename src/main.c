#include <raylib.h>
#include <stdio.h>

#include "../include/screen.h"
#include "../include/player.h"
#include "../include/square.h"

/*
    player_touch_square

    This function checks if the player's square has collided with the
    target square. It returns 1 if the two squares are overlapping, 
    meaning a collision has occurred, and 0 otherwise.

    Parameters:
        - `player`: The player object, which contains the player's position
          and size.
        - `square`: The target square that the player needs to collide with.

    Returns:
        - 1 if the player has collided with the target square.
        - 0 if there is no collision.

    Example:
        if (player_touch_square(player, square)) { 
            // Handle collision
        }
*/
int player_touch_square(Player player, Square square)
{
    if ((player.x + player.size > square.x) && (player.x < square.x + square.size) &&
        (player.y + player.size > square.y) && (player.y < square.y + square.size))
    {
        return 1; // Collision detected
    }

    return 0; // No collision
}

/*
    main

    The main function initializes the game screen, player, and square,
    and handles the main game loop. The game involves moving the player
    and trying to collide with randomly placed squares to increase the score.

    It performs the following steps:
    - Initializes the screen, player, and square.
    - Creates the game window.
    - Runs a loop that handles input (player movement), checks collisions,
      updates the score, and draws everything to the screen.
    - Closes the window and frees up resources when the game ends.

    Parameters:
        - `argc`: Argument count (not used in this case).
        - `argv`: Argument values (not used in this case).

    Returns:
        - 0 when the game finishes and the program ends.
*/
int main(int argc, const char *argv[])
{
    // Set log level to warnings only (ignores info logs)
    SetTraceLogLevel(LOG_WARNING);

    Screen screen;   // The game screen object.
    Player player;   // The player object.
    Square square;   // The target square object.
    char score_text[100];  // A buffer for displaying the score.

    // Initialize the screen, player, and square
    init_Screen(&screen, 800, 600, "Squared 1.0");
    init_Player(&player, 25, WHITE, 25, screen.width / 2, screen.height / 2, 0);
    init_Square(&square, 15, YELLOW);

    // Initialize the game window
    InitWindow(screen.width, screen.height, screen.title);

    // Place the target square randomly on the screen
    summon_Square(&square, screen.width, screen.height);

    // Set the target frame rate for the game loop (15 frames per second)
    SetTargetFPS(15);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Format the score text for display
        snprintf(score_text, sizeof(score_text), "%d", player.score);

        // Handle player movement
        move_Player(&player, screen.width, screen.height);

        // Begin drawing to the screen
        BeginDrawing();

        // Clear the background to black
        ClearBackground(BLACK);

        // Draw the score text on the screen
        DrawText(score_text, 0, 0, 40, WHITE);

        // Check for collision between the player and the target square
        if (player_touch_square(player, square) == 1)
        {
            // Place a new random square and increase the score
            summon_Square(&square, screen.width, screen.height);
            player.score += 1;
        }

        // Draw the player and the target square
        draw_Player(player);
        draw_Square(square);

        // End the drawing process for this frame
        EndDrawing();
    }

    // Close the game window
    CloseWindow();

    return 0;
}