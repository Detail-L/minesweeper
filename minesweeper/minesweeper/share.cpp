#ifndef __SHARE__
#define __SHARE__
//公用部分

#define MapL 35;  //地图宽度
#define MapH 35;  //地图高度

unsigned char Map[MapL][MapH];  //储存地图信息
/*
	0-3位储存周围雷数（0-8表示雷数，9表示雷）
	4位储存是否为雷
	5位表示是否遮盖（既是否被翻开）
	6-7位表示如果被遮盖显示的内容
*/





#endif
