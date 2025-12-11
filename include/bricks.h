#ifndef BRICKS_H
#define BRICKS_H

#include "game.h"
#include "ball.h"

void bricks_init();
void bricks_update(float deltaTime);
void bricks_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);

#endif