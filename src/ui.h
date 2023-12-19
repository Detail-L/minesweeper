#pragma once
#include "share.h"
#include <graphics.h>
#include <stdlib.h>


#define W_Window 700
#define H_Window 700

typedef struct{
    int x;
    int y;
}point;

void initgame();
void closegame();

void begin();
void fail();
void success();

point GetPos(int x, int y);
void Draw(int x, int y);
