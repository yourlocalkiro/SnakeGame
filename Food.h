#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"
#include <vector>

class Food {
private:
    Vector2 position;

public:
    Food();

    void Spawn(const std::vector<Vector2>& snakeBody);
    void Draw();
    Vector2 GetPosition();

};

#endif