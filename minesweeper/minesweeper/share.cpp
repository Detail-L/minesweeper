#include "share.h"
#include <stdbool.h>

unsigned char Map[MapL][MapH];  //储存地图信息
/*
	0-3位储存周围雷数（0-8表示雷数，9表示雷）
	4位储存是否为雷
	5位表示是否遮盖（既是否被翻开）
	6-7位表示如果被遮盖显示的内容
*/

/* 操作地图周边雷数 */
//得到周围雷数（在无遮盖时显示数字）
unsigned char GetMineNum(int x, int y) {
	return Map[x][y] & 0x0F;//0000 1111
}

//用于（初始化时）对地图写入雷数
void SetMineNum(int x, int y, unsigned char v) {
	v &= 0x0F;//0000 1111
	Map[x][y] &= 0xF0;//1111 0000
	Map[x][y] |= v;
}


/* 操作雷 */
//一个位置是否有雷
bool GetMine(int x, int y) {
	return (bool)(Map[x][y] & 0x10);//0001 0000
}

//以下两个用于设置和释放雷
void SetMine(int x, int y) {
	Map[x][y] |= 0x10;//0001 0000
}
void ResetMine(int x, int y) {
	Map[x][y] &= 0xEF;//1110 1111
}


/* 操作遮挡 */
//一个位置是否有遮挡
bool GetMasks(int x, int y) {
	return (bool)(Map[x][y] & 0x20);//0010 0000
}

//以下两个用于设置和释放遮挡
void SetMask(int x, int y) {
	Map[x][y] |= 0x20;//0010 0000
}
void ResetMask(int x, int y) {
	Map[x][y] &= 0xDF;//1101 1111
}
//以下两个函数用于操作遮挡的类型
unsigned char GetMaskMode(int x, int y) {
	return (Map[x][y] >> 6) & 0x03;//0000 0011
}
void SetMaskMode(int x, int y, unsigned char v) {
	v = (v << 6) & 0xC0;//1100 0000
	Map[x][y] &= 0x3F;//0011 1111
	Map[x][y] |= v;
}




/* 以下两个函数仅特殊情况使用 */
//得到Map(x,y)的值
unsigned char GetValue(int x, int y) {
	return Map[x][y];
}
//设置Map(x,y)的值
void SetValue(int x, int y,unsigned char v) {
	Map[x][y] = v;
}


