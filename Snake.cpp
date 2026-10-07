#include "Snake.h"

std::vector<Vector2> Snake::GetBody() {
    return body;
}

Snake::Snake() {
    body = {
        {300, 300},
        {270, 300},
        {240, 300}
    };

    direction = {1, 0};
    visualHead = body[0];
    previousHead = body[0];
    visualSpeed = 200.0f;

    moveTimer = 0.0f;
    moveInterval = 0.15f;
}

void Snake::ChangeDirection(Vector2 newDirection) {
    if (newDirection.x == -direction.x &&
        newDirection.y == -direction.y) {
        return;
    }

    direction = newDirection;
}

void Snake::Update() {
    moveTimer += GetFrameTime();
    previousHead = body[0];
    if (moveTimer >= moveInterval) {
        for (int i = body.size() - 1; i > 0; i--) {
            body[i] = body[i - 1];
        }

        body[0].x += direction.x * 30;
        body[0].y += direction.y * 30;

        moveTimer = 0.0f;
    }
    float progress = moveTimer / moveInterval;
    visualHead.x = previousHead.x + (body[0].x - previousHead.x) * progress;
    visualHead.y = previousHead.y + (body[0].y - previousHead.y) * progress;
}

void Snake::Draw() {
    for (int i = 0; i < body.size(); i++) {
        Vector2 position = body[i];
        if (i == 0)
            position = visualHead;
        Color color = (i == 0) ? LIME : GREEN;

        DrawRectangle(body[i].x + 2, body[i].y + 2, 26, 26, color);

        if (i == 0) {

            float eye1X;
            float eye1Y;
            float eye2X;
            float eye2Y;

            if (direction.x == 1) {
                // Moving right
                eye1X = position.x + 20;
                eye1Y = body[i].y + 9;

                eye2X = position.x + 20;
                eye2Y = position.y + 21;
            }

            else if (direction.x == -1) {
                // Moving left
                eye1X = position.x + 10;
                eye1Y = position.y + 9;

                eye2X = position.x + 10;
                eye2Y = position.y + 21;
            }

            else if (direction.y == -1) {
                // Moving up
                eye1X = position.x + 9;
                eye1Y = position.y + 10;

                eye2X = position.x + 21;
                eye2Y = position.y + 10;
            }

            else {
                // Moving down
                eye1X = position.x + 9;
                eye1Y = position.y + 20;

                eye2X = position.x + 21;
                eye2Y = position.y + 20;
            }

            DrawCircle(eye1X, eye1Y, 3, BLACK);
            DrawCircle(eye2X, eye2Y, 3, BLACK);
        }
    }
}

void Snake::Grow(){
    body.push_back(body.back());
}

Vector2 Snake::GetHeadPosition(){
    return body[0];
}

bool Snake::CheckCollision(){
    if (body[0].x < 0 || body[0].x >= 780 || body[0].y < 0 || body[0].y >= 600){
        return true;
    }

    for(int i = 1; i < body.size(); i++){
        if(body[0].x == body[i].x && body[0].y == body[i].y){
            return true;
        }
    }

    return false;
}

void Snake::IncreaseSpeed(){
    if (moveInterval > 0.14f){
        moveInterval -= 0.001f;
    }
}