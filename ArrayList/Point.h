#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	
	int xpos;
	int ypos;
	
}Point;

// ����Ʈ ��ǥ ���� 
void SetPointPos(Point * ppos, int xpos, int ypos);

// ����Ʈ ��ǥ ��� 
void ShowPointPos(Point * ppos);

// �� ����Ʈ �� 
int PointComp(Point * pos1, Point * pos2);
#endif
