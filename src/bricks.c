#include "bricks.h"

// Brick layout
#define BRICK_ROWS 5
#define BRICK_COLS 20
#define BRICK_CHAR 'x'

// Each brick is either alive or dead 1 or 0.
static int bricks[BRICK_ROWS][BRICK_COLS];

// Bricks position
static const int BRICK_START_Y = 2;
static const int BRICK_START_X = 0;

// size per brick
static const int BRICK_W = 2;
static const int BRICK_H = 1;

void bricks_init()
{
    for (int r = 0; r < BRICK_ROWS; r++)
    {
        for (int c = 0; c < BRICK_COLS; c++)
        {
            bricks[r][c] = 1; // 1 = alive
        }
    }
}

void bricks_update(float deltaTime)
{
    // Ball init

    int bx = ball_getX();
    int by = ball_getY();

    for (int r = 0; r < BRICK_ROWS; r++)
    {
        for (int c = 0; c < BRICK_COLS; c++)
        {
            if (bricks[r][c] == 0)
            {
                continue;
            }
            int brickX = BRICK_START_X + c * BRICK_W;
            int brickY = BRICK_START_Y + r * BRICK_H;
            // check vertical collision (ball touches the brick row)
            if (by == brickY)
            {
                // checking the horizontal overlap
                if (bx >= brickX && bx < brickX + BRICK_W)
                {
                    bricks[r][c] = 0; // destroy the block
                    invertVelY();     // bounce;
                }
            }
        }
    }
}

void bricks_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int r = 0; r < BRICK_ROWS; r++)
    {
        for (int c = 0; c < BRICK_COLS; c++)
        {
            if (bricks[r][c] == 0)
            {
                continue;
            }
            int x = BRICK_START_X + c * BRICK_W;
            int y = BRICK_START_Y + r * BRICK_H;
            // Drawing the bricks
            for (int w = 0; w < BRICK_W; w++)
            {
                screen[y][x + w] = BRICK_CHAR;
            }
        }
    }
}