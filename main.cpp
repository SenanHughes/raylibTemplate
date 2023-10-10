#include "raylib.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1080;
    const int screenHeight = 600;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Conditionals");

    bool isEven = false;
    int number = 6;
        
    if (number%2 == 0){
        isEven = true;
    }

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(PINK);

        // Here goes all the Game Logic
        if(isEven){
            DrawText("Number is even", 10, 10, 20, BLUE);
        }else{
            DrawText("Number is odd", 10, 10, 20, BLUE);
        }

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}