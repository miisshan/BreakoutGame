#ifndef PADDLE_H
#define PADDLE_H

#include "game.h" //for SCREEN_WIDTH and SCREEN_HEIGHT

// Function declarations.
void paddle_init();
void paddle_update(float deltaTime);
void paddle_render(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);

int paddle_getX();
int paddle_getY();
int paddle_getWidth();

#endif