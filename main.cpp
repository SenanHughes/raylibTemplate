#include "raylib.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1080;
    const int screenHeight = 600;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Font Loading and Input");

    Font customFont = LoadFont("Resources/Textures/Walkway_UltraBold.ttf");

    const char *text = "Hello, raylib";

    Vector2 textPosition = {10, screenHeight/2 - 20};
    int textSize = 20;
    Color textColour = RAYWHITE;
    


    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {
        
        if(IsKeyPressed(KEY_UP)) textSize += 10;
        if(IsKeyPressed(KEY_DOWN) && textSize > 10)textSize -= 10;
        if(IsKeyPressed(KEY_R)) textColour = RED;
        if(IsKeyPressed(KEY_G)) textColour = GREEN;
        if(IsKeyPressed(KEY_B)) textColour = BLUE;
        if(IsKeyPressed(KEY_W)) textColour = WHITE;

        
        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(PINK);

        // Here goes all the Game Logic
        DrawText(text, textPosition.x, textPosition.y, textSize, textColour);
        DrawText("Use arrow keys to change size, R/G/B/W to change colour", 10, screenHeight - 40, 10, GRAY);

        DrawTextEx(customFont, "Custom Font Text", (Vector2){screenWidth/2,20}, customFont.baseSize, 2, DARKPURPLE);

        // teardown Canvas
        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}