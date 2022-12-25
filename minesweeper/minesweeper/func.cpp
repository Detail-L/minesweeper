#include "func.h"
//¿ØÖÆ²¿·Ö

void mapinit(int n) {
	srand((unsigned int)time(NULL));
	for (int i = 0;i < MapL;i++) {
		for (int j = 0;j < MapH;j++) {
			SetValue(i, j, (unsigned char)0x00);
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
			if (GetMine(i-1, j-1)) { tmp++; }
			if (GetMine(i-1, j)) { tmp++; }
			if (GetMine(i-1, j+1)) { tmp++; }
			if (GetMine(i, j-1)) { tmp++; }
			if (GetMine(i, j+1)) { tmp++; }
			if (GetMine(i+1, j-1)) { tmp++; }
			if (GetMine(i+1, j)) { tmp++; }
			if (GetMine(i+1, j+1)) { tmp++; }
			SetMineNum(i, j, (unsigned char)tmp);
		}
	}

}
