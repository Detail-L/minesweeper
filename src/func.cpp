#include "func.h"
//¿ØÖÆ²¿·Ö

#define DIR_Open 8
int dx[DIR_Open] = {-1,-1,-1,0,0,1,1,1};
int dy[DIR_Open] = {-1,0,1,-1,1,-1,0,1};
void NextEvent(int x,int y){
	for(int i = 0; i < DIR_Open; i++){
		if(x+dx[i]<0 || x+dx[i]>=MapL || y+dy[i]<0 || y+dy[i]>=MapH || !GetMasks(x+dx[i],y+dy[i]))
			continue;
		ResetMask(x+dx[i],y+dy[i]);
		Draw(x+dx[i],y+dy[i]);
		if(GetMineNum(x+dx[i],y+dy[i]) == 0)
			NextEvent(x+dx[i],y+dy[i]);
	}
}

void mapinit(int n) {
	NumReset();
	srand((unsigned int)time(NULL));
	for (int i = 0;i < MapL;i++) {
		for (int j = 0;j < MapH;j++) {
			SetValue(i, j, (unsigned char)0x00);
			SetMask(i, j);
		}
	}
	for (int i = 0;i < n;i++) {
		int x, y;
		x = rand() % MapL;
		y = rand() % MapH;
		if (GetMine(x, y)) {
			i--;
		}
		else {
			SetMine(x, y);
		}
	}
	for (int i = 0;i < MapL;i++) {
		for (int j = 0;j < MapH;j++) {
			int tmp = 0;
			if (GetMine(i, j)) {
				SetMineNum(i, j, (unsigned char)9);
				continue;
			}
			for(int k = 0;k < DIR_Open; k++){
				if(GetMine(i+dx[k],j+dy[k])){
					tmp++;
				}
			}
			SetMineNum(i, j, (unsigned char)tmp);
		}
	}

}

int MouseEvent(){
	while (mousemsg()) {
		mouse_msg msg = getmouse();
		point pos = GetPos(msg.x,msg.y);
		if (msg.is_left() && msg.is_down()){
			ResetMask(pos.x,pos.y);
			if(GetMine(pos.x,pos.y)){
				Draw(pos.x,pos.y);
				return 1;
			}
			Draw(pos.x,pos.y);
			if(GetMineNum(pos.x,pos.y) == 0)
				NextEvent(pos.x,pos.y);
		}else if(msg.is_right() && msg.is_down()){
			SetMaskMode(pos.x,pos.y,(GetMaskMode(pos.x,pos.y)+1)%3);
			Draw(pos.x,pos.y);
		}else if(msg.is_mid() && msg.is_down()){
			int counter = 0, counter2 = 0;
			for(int i = 0; i < DIR_Open; i++){
				if(pos.x+dx[i]<0 || pos.x+dx[i]>=MapL || pos.y+dy[i]<0 || pos.y+dy[i]>=MapH)
					continue;
				unsigned char tmp = GetMaskMode(pos.x+dx[i],pos.y+dy[i]);
				if(GetMasks(pos.x+dx[i],pos.y+dy[i]) && tmp != 0){
					counter++;
					if(tmp == 1)
						counter2++;
				}
			}
			if(counter == counter2 && counter == GetMineNum(pos.x,pos.y)){
				int flag = 0;
				for(int i = 0; i < DIR_Open; i++){
					if(pos.x+dx[i]<0 || pos.x+dx[i]>=MapL || pos.y+dy[i]<0 || pos.y+dy[i]>=MapH)
						continue;
					if(GetMaskMode(pos.x+dx[i],pos.y+dy[i]) == 0){
						ResetMask(pos.x+dx[i],pos.y+dy[i]);
						if(GetMine(pos.x+dx[i],pos.y+dy[i])){
							flag = 1;
						}
						Draw(pos.x+dx[i],pos.y+dy[i]);
						if(GetMineNum(pos.x+dx[i],pos.y+dy[i]) == 0)
							NextEvent(pos.x+dx[i],pos.y+dy[i]);
					}
				}
				if(flag)
					return 1;
			}
		}

	}
	if(is_success())
		return 2;
	return 0;
}
