#include <graphics.h>		// 引用 EasyX 绘图库头文件
#include <conio.h>
#include <stdbool.h>
#include <Windows.h>
#include "func.h"
#include "ui.h"
#include "share.h"

#define M 25

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	mapinit(M);
	initgame();
	for (int i = 0;i < MapL;i++) {
		for (int j = 0;j < MapH;j++) {
			Draw(i, j);
		}
	}
	while (1) {

		Sleep(1);
	}
	closegame();
	return 0;
}
