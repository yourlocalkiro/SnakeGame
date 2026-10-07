#include "raylib.h"
#include "Snake.h"
#include "Food.h"

//Including Embedded Audios
#include "eat.h"
#include "left.h"
#include "right.h"
#include "up.h"
#include "down.h"
#include "win.h"
#include "death.h"

enum GameState {
    MENU,
    PLAYING,
    GAME_OVER,
    GAME_WON
};

int main() {
    InitWindow(780, 600, "My Snake Game");
    InitAudioDevice();
    SetTargetFPS(60);

    Snake player;
    Food food;

    Wave eatWave = LoadWaveFromMemory(".WAV", eatData, eatDataSize);
    Sound eatSound = LoadSoundFromWave(eatWave);
    UnloadWave(eatWave);

    Wave leftWave = LoadWaveFromMemory(".WAV", leftData, leftDataSize);
    Sound leftSound = LoadSoundFromWave(leftWave);
    UnloadWave(leftWave);

    Wave rightWave = LoadWaveFromMemory(".WAV", rightData, rightDataSize);
    Sound rightSound = LoadSoundFromWave(rightWave);
    UnloadWave(rightWave);

    Wave upWave = LoadWaveFromMemory(".WAV", upData, upDataSize);
    Sound upSound = LoadSoundFromWave(upWave);
    UnloadWave(upWave);

    Wave downWave = LoadWaveFromMemory(".WAV", downData, downDataSize);
    Sound downSound = LoadSoundFromWave(downWave);
    UnloadWave(downWave);

    Wave winWave = LoadWaveFromMemory(".WAV", winData, winDataSize);
    Sound winSound = LoadSoundFromWave(winWave);
    UnloadWave(winWave);

    Wave deathWave = LoadWaveFromMemory(".WAV", deathData, deathDataSize);
    Sound deathSound = LoadSoundFromWave(deathWave);
    UnloadWave(deathWave);
    
    food.Spawn(player.GetBody());

    GameState gameState = MENU;
    int score = 0;
    int highscore = 0;

    while (!WindowShouldClose()) {
        if (gameState == MENU) {
            if (IsKeyPressed(KEY_ENTER)) {
                gameState = PLAYING;
            }
        }

        else if (gameState == PLAYING) {
            // Controls
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){
                player.ChangeDirection({0, -1});
                PlaySound(upSound);}
            else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){
                player.ChangeDirection({0, 1});
                PlaySound(downSound);}
            else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)){
                player.ChangeDirection({-1, 0});
                PlaySound(leftSound);}
            else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)){
                player.ChangeDirection({1, 0});
                PlaySound(rightSound);}

            player.Update();

            // Collision
            if (player.CheckCollision()) {
                PlaySound(deathSound);
                gameState = GAME_OVER;
            }
            else {
                // Food
                Vector2 head = player.GetHeadPosition();
                Vector2 foodPos = food.GetPosition();

                if (head.x == foodPos.x && head.y == foodPos.y) {

                    player.Grow();
                    player.IncreaseSpeed();
                    score++;
                    if (player.GetBody().size() >= 520){
                        gameState = GAME_WON;
                        PlaySound(winSound);
                    }
                    else{
                        food.Spawn(player.GetBody());
                        PlaySound(eatSound);
                    }
                    if (score > highscore)
                        highscore = score;
                }
            }
        }

        else if (gameState == GAME_OVER || gameState == GAME_WON) {
            if (IsKeyPressed(KEY_R)) {
                player = Snake();
                food.Spawn(player.GetBody());

                score = 0;
                gameState = PLAYING;
            }
        }

        BeginDrawing();
        ClearBackground((Color){8, 15, 30, 255});

        if (gameState == MENU) {
            int titleWidth = MeasureText("SNAKE", 50);
            int subtitleWidth = MeasureText("Press ENTER to Start", 20);
            DrawText("SNAKE", (GetScreenWidth() - titleWidth) / 2, 200, 50, GREEN);
            DrawText("Press ENTER to Start", (GetScreenWidth() - subtitleWidth) / 2, 280, 20, WHITE);
        }

        else if  (gameState == GAME_WON){
            int winWidth = MeasureText("YOU WIN!", 40);
            int restartWidth = MeasureText("Press R To Restart", 20);
            DrawText("YOU WIN!", (GetScreenWidth()-winWidth)/2, 250, 40, GREEN);
            DrawText("Press R To Restart", (GetScreenWidth()-restartWidth)/2, 300, 20, WHITE);
        }

        else if (gameState == PLAYING || gameState == GAME_OVER) {

            for (int x = 0; x < GetScreenWidth(); x += 30) {
                for (int y = 0; y < GetScreenHeight(); y += 30) {

                    if ((x / 30 + y / 30) % 2 == 0) {
                        DrawRectangle(x, y, 30, 30, (Color){12, 22, 40, 255});
                    }
                }
            }

            food.Draw();
            player.Draw();
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);
            DrawText(TextFormat("High Score: %d", highscore), 10, 35, 20, WHITE);

            if (gameState == GAME_OVER) {
                int gameOverWidth = MeasureText("GAME OVER", 40);
                int restartWidth = MeasureText("Press R To Restart", 20);

                DrawText("GAME OVER", (GetScreenWidth()-gameOverWidth)/2, 250, 40, RED);
                DrawText("Press R To Restart", (GetScreenWidth()-restartWidth)/2, 300, 20, WHITE);
            }
        }
        EndDrawing();
    }
    UnloadSound(eatSound);
    UnloadSound(leftSound);
    UnloadSound(rightSound);
    UnloadSound(upSound);
    UnloadSound(downSound);
    UnloadSound(winSound);
    UnloadSound(deathSound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}