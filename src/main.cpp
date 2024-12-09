#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)  //MOVE DOWN SPPED
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris");  //ini game window

    SetTargetFPS(60);  // GAME SPEED

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0); //LOAD FRONT 

    Game game = Game();

    while (WindowShouldClose() == false)  // GAME LOOP
    {
        UpdateMusicStream(game.music);  //INPUT MUSIC

        game.HandleInput();  //KEY-PRESSED

        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();  //MOVE DOWN SPPED
        }

        BeginDrawing();    //GAME OBJ DRAWING
        ClearBackground(darkBlue); //BG_COLOR


        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE); 
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE); 


        if (game.gameOver) //CHECK FOR GAME OVER
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);  //SCORE-CNT
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); 

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}