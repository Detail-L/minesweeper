#pragma once
#include <stdbool.h>

#define MapL 15  //��ͼ���
#define MapH 15  //��ͼ�߶�

unsigned char GetMineNum(int x, int y);
void SetMineNum(int x, int y, unsigned char v);


bool GetMine(int x, int y);
void SetMine(int x, int y);
void ResetMine(int x, int y);


bool GetMasks(int x, int y);
void SetMask(int x, int y);
void ResetMask(int x, int y);

unsigned char GetMaskMode(int x, int y);
void SetMaskMode(int x, int y, unsigned char v);


unsigned char GetValue(int x, int y);
void SetValue(int x, int y, unsigned char v);