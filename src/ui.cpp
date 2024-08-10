#include "ui.h"

PIMAGE img_mine = NULL;
PIMAGE img_doubt = NULL;
PIMAGE img_flag = NULL;

//ui����
void initgame() {
	setcaption("Minesweeper");
	initgraph(W_Window, H_Window);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	begin();
	setfont(W_Window/MapL*3/4,H_Window/MapH*3/4,"����");
	cleardevice();
	//settextstyle(W_Window/MapL,H_Window/MapH,_T("����"));
	//settextcolor(GREEN);
	for (int i = 0;i < MapL;i++) {
			for (int j = 0;j < MapH;j++) {
				Draw(i, j);
			}
	}
	//����Դ�ļ��ж�ȡͼƬ
	img_mine = newimage();
	getimage(img_mine, "PNG", "IMG_MINE");
	img_doubt = newimage();
	getimage(img_doubt, "PNG", "IMG_DOUBT");
	img_flag = newimage();
	getimage(img_flag, "PNG", "IMG_FLAG");
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

point GetPos(int x, int y) {
	point a;
	a.x = x / (W_Window / MapL);
	a.y = y / (H_Window / MapH);

	return a;
}


void Draw(int x, int y) {
	RECT d = GetRect(x, y);
	if(GetMasks(x, y)){
		setfillcolor(EGERGB(255, 204, 204));
	}
	else {
		setfillcolor(EGERGB(204, 255, 204));
	}
	setbkmode(OPAQUE);
	bar(d.left, d.top, d.right, d.bottom);
	//fillrectangle(d.left, d.top, d.right, d.bottom);
	setbkmode(TRANSPARENT);
	if(!GetMine(x, y)&&!GetMasks(x, y)){
		unsigned char v = GetMineNum(x, y);
		if(v!=0){
			char out[2];
			_itoa_s((int)v, out, 2, 10);
			setcolor(GREEN);
			outtextxy(d.left+W_Window/MapL/2, d.top+H_Window/MapH/2, *out);
		}
	}
	else if(GetMasks(x, y)){
		switch(GetMaskMode(x, y)){
			case (unsigned char)1: 
				putimage(d.left, d.top, W_Window/MapL, H_Window/MapH, img_flag, 0, 0, getwidth(img_flag), getheight(img_flag));
				break;
			case (unsigned char)2:
				putimage(d.left, d.top, W_Window/MapL, H_Window/MapH, img_doubt, 0, 0, getwidth(img_doubt), getheight(img_doubt));
				break;
		}
	}
	else if(GetMine(x, y)){
		putimage(d.left, d.top, W_Window/MapL, H_Window/MapH, img_mine, 0, 0, getwidth(img_mine), getheight(img_mine));
	}
}

void fail(){
	setfont(W_Window/MapL*3/2,H_Window/MapH*3/2,"����");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setfillcolor(EGERGBA(66, 66, 166, 200));
	ege_fillrect(0, H_Window/3, W_Window, H_Window/3);
	setcolor(EGERGB(204, 204, 255));
	outtextxy(W_Window/2, H_Window/2, "You Fail");
}
void success(){
	setfont(W_Window/MapL*3/2,H_Window/MapH*3/2,"����");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setfillcolor(EGERGBA(66, 66, 166, 200));
	ege_fillrect(0, H_Window/3, W_Window, H_Window/3);
	setcolor(EGERGB(204, 204, 255));
	outtextxy(W_Window/2, H_Window/2, "Success");
}

void begin(){
	setbkcolor(EGERGB(255, 242, 210));
	cleardevice();
	setbkmode(TRANSPARENT);
	setcolor(EGERGB(66, 85, 166));
	setfont(W_Window/MapL,H_Window/MapH,"����");
	outtextxy(W_Window/2, H_Window/3, "Minesweeper");
	setcolor(EGERGB(166, 63, 106));
	setfont(W_Window/MapL/2,H_Window/MapH/2,"����");
	outtextxy(W_Window/2, H_Window/3*2, "Click to Start");
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
}
