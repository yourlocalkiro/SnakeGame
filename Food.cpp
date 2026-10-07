#include "Food.h"

Food::Food() {
    position = {100, 100};
}

void Food::Spawn(const std::vector<Vector2>& snakeBody) {

    bool onSnake;

    do {
        int x = GetRandomValue(0, 25);
        int y = GetRandomValue(0, 19);

        position = {
            static_cast<float>(x * 30),
            static_cast<float>(y * 30)
        };

        onSnake = false;

        for (Vector2 segment : snakeBody) {
            if (position.x == segment.x &&
                position.y == segment.y) {
                onSnake = true;
                break;
            }
        }

    } while (onSnake);
}

void Food::Draw(){
    DrawCircle(
        position.x + 15,
        position.y + 15,
        11,
        RED
    );
}

Vector2 Food::GetPosition(){
    return position;
}
