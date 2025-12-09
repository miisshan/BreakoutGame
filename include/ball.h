#ifndef BALL_H
#define BALL_H
#include "game.h"

void ball_init();
void ball_update(float deltaTime);
void ball_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);

#endif