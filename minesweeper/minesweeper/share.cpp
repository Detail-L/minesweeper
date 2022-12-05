#include "share.h"
#include <stdbool.h>

unsigned char Map[MapL][MapH];  //�����ͼ��Ϣ
/*
	0-3λ������Χ������0-8��ʾ������9��ʾ�ף�
	4λ�����Ƿ�Ϊ��
	5λ��ʾ�Ƿ��ڸǣ����Ƿ񱻷�����
	6-7λ��ʾ������ڸ���ʾ������
*/

/* ������ͼ�ܱ����� */
//�õ���Χ�����������ڸ�ʱ��ʾ���֣�
unsigned char GetMineNum(int x, int y) {
	return Map[x][y] & 0x0F;//0000 1111
}

//���ڣ���ʼ��ʱ���Ե�ͼд������
void SetMineNum(int x, int y, unsigned char v) {
	v &= 0x0F;//0000 1111
	Map[x][y] &= 0xF0;//1111 0000
	Map[x][y] |= v;
}


/* ������ */
//һ��λ���Ƿ�����
bool GetMine(int x, int y) {
	return (bool)(Map[x][y] & 0x10);//0001 0000
}

//���������������ú��ͷ���
void SetMine(int x, int y) {
	Map[x][y] |= 0x10;//0001 0000
}
void ResetMine(int x, int y) {
	Map[x][y] &= 0xEF;//1110 1111
}


/* �����ڵ� */
//һ��λ���Ƿ����ڵ�
bool GetMasks(int x, int y) {
	return (bool)(Map[x][y] & 0x20);//0010 0000
}

//���������������ú��ͷ��ڵ�
void SetMask(int x, int y) {
	Map[x][y] |= 0x20;//0010 0000
}
void ResetMask(int x, int y) {
	Map[x][y] &= 0xDF;//1101 1111
}
//���������������ڲ����ڵ�������
unsigned char GetMaskMode(int x, int y) {
	return (Map[x][y] >> 6) & 0x03;//0000 0011
}
void SetMaskMode(int x, int y, unsigned char v) {
	v = (v << 6) & 0xC0;//1100 0000
	Map[x][y] &= 0x3F;//0011 1111
	Map[x][y] |= v;
}




/* ���������������������ʹ�� */
//�õ�Map(x,y)��ֵ
unsigned char GetValue(int x, int y) {
	return Map[x][y];
}
//����Map(x,y)��ֵ
void SetValue(int x, int y,unsigned char v) {
	Map[x][y] = v;
}


