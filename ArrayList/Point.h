#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	
	int xpos;
	int ypos;
	
}Point;

// 포인트 좌표 설정 
void SetPointPos(Point * ppos, int xpos, int ypos);

// 포인트 좌표 출력 
void ShowPointPos(Point * ppos);

// 두 포인트 비교 
int PointComp(Point * pos1, Point * pos2);
#endif
