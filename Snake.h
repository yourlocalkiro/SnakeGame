#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <vector>

class Snake {
private:
    std::vector<Vector2> body;
    Vector2 direction;

    float moveTimer;
    float moveInterval;
    Vector2 visualHead;
    Vector2 previousHead;

    float visualSpeed;

public:
    Snake();

    void Update();
    void Draw();

    void ChangeDirection(Vector2 newDirection);
    void Grow();
    Vector2 GetHeadPosition();
    void IncreaseSpeed();
    bool CheckCollision();
    std::vector<Vector2> GetBody();
};

#endif