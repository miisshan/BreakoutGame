#include "paddle.h"
#include "game.h"

typedef struct
{
    int x;
    int y;
    int paddleWidth;
    float accumX;
    float speed;
} Paddle;

static Paddle paddle;

void paddle_init()
{
    paddle.paddleWidth = 6;
    paddle.x = (SCREEN_WIDTH - paddle.paddleWidth) / 2;
    paddle.y = SCREEN_HEIGHT - 3;
    paddle.speed = 40.0f; // units per second
    paddle.accumX = 0.0f;
}

void paddle_update(float deltaTime)
{

    float move = 0.0f; // how much this frame wants to move
    if (_kbhit())
    {
        char key = getch(); // Detect the keypress
        if (key == 'a')
        {
            move = -paddle.speed * deltaTime;
        }

        if (key == 'd')
        {
            move = paddle.speed * deltaTime;
        }
        // Add movement to the accumulator
        paddle.accumX += move;

        // Extract whole number
        int moveInt = (int)paddle.accumX;

        // Subtract the integer portion
        paddle.accumX -= moveInt;

        // apply integer movement
        paddle.x += moveInt;

        // BOUNDS CHECK
        if (paddle.x < 0)
        {
            paddle.x = 0;
        }
        if (paddle.x > SCREEN_WIDTH - paddle.paddleWidth)
        {
            paddle.x = SCREEN_WIDTH - paddle.paddleWidth;
        }
    }
}

void paddle_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int i = 0; i < paddle.paddleWidth; i++)
    {
        screen[paddle.y][paddle.x + i] = '=';
    }
}

int paddle_getX()
{
    return paddle.x;
}

int paddle_getY()
{
    return paddle.y;
}

int paddle_getWidth()
{
    return paddle.paddleWidth;
}
