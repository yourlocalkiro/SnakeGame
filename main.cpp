#include "raylib.h"
#include "Snake.h"
#include "Food.h"

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
    Sound eatSound = LoadSound("Audio/EAT.wav");
    Sound leftSound = LoadSound("Audio/LEFT.wav");
    Sound rightSound = LoadSound("Audio/RIGHT.wav");
    Sound upSound = LoadSound("Audio/UP.wav");
    Sound downSound = LoadSound("Audio/DOWN.wav");
    Sound winSound = LoadSound("WAudio/IN.wav");
    Sound deathSound = LoadSound("Audio/DEATH.wav");

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
            PlaySound(winSound);
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