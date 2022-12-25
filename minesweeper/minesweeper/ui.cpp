#include "ui.h"

//ui²¿·Ö


void initgame() {
	initgraph(W_Window, H_Window);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(W_Window/MapL,H_Window/MapH,_T("ËÎÌå"));
	settextcolor(GREEN);
}

void closegame() {
	closegraph();
}

RECT GetRect(int x, int y) {
	RECT a;
	a.left = x * W_Window / MapL;
	a.top = y * H_Window / MapH;
	a.right = (x+1) * W_Window / MapL;
	a.bottom = (y+1) * H_Window / MapH;

	return a;
}


void Draw(int x, int y) {
	RECT d = GetRect(x, y);
	if (GetMine(x, y)) {
		setfillcolor(RED);
	}
	else {
		setfillcolor(BLACK);
	}
	setbkmode(OPAQUE);
	fillrectangle(d.left, d.top, d.right, d.bottom);
	setbkmode(TRANSPARENT);
	unsigned char v = GetMineNum(x, y);
	char out[2];
	_itoa_s((int)v, out, 2, 10);
	outtextxy(d.left, d.top, *out);
}