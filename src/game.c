#include "ball.h"
#include "bricks.h"
#include "game.h"
#include "paddle.h"
#include "stdbool.h"
#include "stdio.h"
#include "windows.h"
#include "time.h"

static char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

void hideCursor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);
}

void clearScreen()
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

void render()
{
    system("cls");
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void game()
{
    bool isRunning = true;
    paddle_init();
    ball_init();

    float lastTime = (float)clock() / CLOCKS_PER_SEC;
    float deltaTime;

    hideCursor();

    while (isRunning)
    {
        float currentTime = (float)clock() / CLOCKS_PER_SEC;
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        paddle_update(deltaTime);
        ball_update(deltaTime);
        clearScreen();
        ball_render(screen);
        paddle_render(screen);
        render();
    }
}