#include <graphics.h>
#include <stdbool.h>
#include <Windows.h>
#include "func.h"
#include "ui.h"
#include "share.h"

#define M 25

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	while(1){
		mapinit(M);
		initgame();
		
		int exitcode = 0;
		while(!exitcode){
			exitcode = MouseEvent();
			Sleep(50);
		}
		switch(exitcode){
			case 1: fail(); break;
			case 2: success(); break;
		}	
		
		bool flag = 1;
		while(flag){
			while (mousemsg()) {
				mouse_msg msg = getmouse();
				if (msg.is_left() && msg.is_down()){
					flag = 0;
				}
			}
			Sleep(50);
		}
		Sleep(300);
	}
	
	closegame();
	return 0;
}
