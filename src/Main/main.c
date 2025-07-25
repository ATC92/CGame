#include "../Engine/Engine.h"
#include "../Game/Game.h"
//////////////////////////////////////////////////////////////////
int main(void)
{
    InitWindow(1440, 900, "Project V-Beta");        ///< Set Name of the window
    SetTargetFPS(75);                               ///< Set FPS
    InitEngine();                                   ///< Init Engine
    while (!WindowShouldClose())                    ///< Main loop for the game
    {
        EngineUpdate();                             ///< Game Engine Update
        BeginDrawing();                             ///< || Start Drawing, RayLib Context
            ClearBackground(RAYWHITE);              ///< Give a color to the Background
            GameRender();                           ///< Game Engine Render
        EndDrawing();                               ///< || End Drawing, RalyLib Context
    }
    DeInitEngine();                                 ///< De-Init Game Engine
    CloseWindow();                                  ///< Close Window OpenGL Context
    return EXIT_SUCCESS;                            ///< Close main correctly
}
//////////////////////////////////////////////////////////////////