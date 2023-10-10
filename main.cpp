#include "raylib.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "My Game");

    Texture2D marioTexture = LoadTexture("Resources/Textures/mario.png");

    Vector2 scale = {0.5f/0.5f};

    float rotation = 0.0f;
    Color tint = WHITE;
    
    Vector2 position = {(screenWidth - (marioTexture.width * scale.x))/2, (screenHeight-(marioTexture.height * scale.y))/2};
    

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(PINK);

        // Here goes all the Game Logic
        DrawTextureEx(marioTexture, position, rotation, 0.5f, tint);
        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}