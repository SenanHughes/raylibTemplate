#include "raylib.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1080;
    const int screenHeight = 600;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Raylib Follow Mouse and Change Colour");

    Texture2D marioTexture = LoadTexture("Resources/Textures/mario.png");

    Vector2 scale = {0.5f, 0.5f};

    Color tint = WHITE;


    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        Vector2 position = GetMousePosition();
        position.x -= marioTexture.width * scale.x/2;
        position.y -= marioTexture.height * scale.y/2;

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            tint = (Color){ 
                (unsigned char)GetRandomValue(50,255),
                (unsigned char)GetRandomValue(50,255),
                (unsigned char)GetRandomValue(50,255), 255
            };
        }
        if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
            tint = WHITE;
        }
        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(PINK);

        // Here goes all the Game Logic
        DrawTextureEx(marioTexture, position, 0, 0.5f, tint);



        // teardown Canvas
        EndDrawing();
    }

    UnloadTexture(marioTexture);

    CloseWindow();
    return 0;
}