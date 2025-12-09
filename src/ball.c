#include "ball.h"
#include "paddle.h"

typedef struct
{
    int x;
    int y;
    float accumX;
    float accumY;
    float velX;
    float velY;
} Ball;

static Ball b;

void ball_init()
{
    b.x = SCREEN_WIDTH / 2;
    b.y = SCREEN_HEIGHT / 2;
    b.accumX = 0.0f;
    b.accumY = 0.0f;
    b.velX = 0.0f;
    b.velY = 5.5f;
}

void ball_update(float deltaTime)
{
    b.accumX += b.velX * deltaTime;
    b.accumY += b.velY * deltaTime;
    int px = paddle_getX();
    int py = paddle_getY();
    int pw = paddle_getWidth();

    // Move ball by integer part of accum;
    int moveX = (int)floorf(b.accumX);
    int moveY = (int)floorf(b.accumY);

    if (moveX != 0)
    {
        b.x += moveX;
        b.accumX -= moveX;
    }
    if (moveY != 0)
    {
        b.y += moveY;
        b.accumY -= moveY;
    }
    // Collisions:

    // Collisions with walls
    if (b.x <= 0)
    {
        b.x = 0;
        b.velX = -b.velX;
    }

    if (b.x >= SCREEN_WIDTH - 1)
    {
        b.x = SCREEN_WIDTH - 1;
        b.velX = -b.velX;
    }

    if (b.y <= 0)
    {
        b.y = 0;
        b.velY = -b.velY;
    }

    if (b.y >= SCREEN_HEIGHT - 1)
    {
        b.y = SCREEN_HEIGHT - 1;
        b.velY = -b.velY;
    }
    // Paddle Collision
    // if (b.velY > 0 && b.y >= py - 1)
    // {
    //     if (b.x >= px && b.x < px + pw)
    //     {
    //         if (b.x > px + pw / 2)
    //         {
    //             b.y = py - 1;
    //             b.velY = -b.velY;
    //             b.velX = +2.0;
    //         }
    //         if (b.x < px - pw / 2)
    //         {
    //             b.y = py - 1;
    //             b.velY = -b.velY;
    //             b.velY = -2.0;
    //         }
    //     }
    // }
    if (b.velY > 0 && b.y == py - 1)
    {
        if (b.x >= px && b.x < px + pw)
        {
            b.y = py - 1;     // clamp above paddle
            b.velY = -b.velY; // bounce up

            // adjust horizontal velocity based on hit position
            float hitPos = (float)(b.x - px) / pw; // 0.0 = left, 0.5 = middle, 1.0 = right

            if (hitPos < 0.33f)
                b.velX = -2.0f; // left third
            else if (hitPos > 0.66f)
                b.velX = 2.0f; // right third
            else
                b.velX = 0.0f; // middle
        }
    }
}

// Updates screen buffer at ball position
void ball_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    if (b.x >= 0 && b.x < SCREEN_WIDTH && b.y >= 0 && b.y < SCREEN_HEIGHT)
    {
        if (b.y % 2 == 0)
        {
            screen[b.y][b.x] = '*';
        }
        else
        {
            screen[b.y][b.x] = '+';
        }
    }
}