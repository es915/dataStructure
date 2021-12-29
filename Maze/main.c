#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

#define MAZE_SIZE 10
#define PATH 0 // 지나갈 수 있는 위치
#define WALL 1 // 지나갈 수 없는 위치
#define VISITED 2 // 이미 방문한 위치
#define BACKTRACKED 3 // 방문했다가 되돌아 나온 위치

char maze[MAZE_SIZE][MAZE_SIZE]={
	{1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,1,0,1,1,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,0,0,0,1,0,1,1,0,1},
	{1,0,1,0,1,0,1,1,0,1},
	{1,0,1,0,1,0,1,1,0,1},
	{1,0,1,0,1,0,1,1,0,1},
	{0,0,1,0,0,0,0,1,0,1},
	{1,-1,1,1,1,1,1,1,1,1}
};

void print_maze() {
	int i, j;

	for(i=0; i<MAZE_SIZE; i++) {
		for(j=0; j<MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}

		printf("\n");
	}
}


// 북동남서 한칸씩 
int offset[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int movable(Data cur, int dir) {
	
	cur.x = cur.x + offset[dir][0];
	cur.y = cur.y + offset[dir][1];
	
	if(cur.x < 0 || cur.y < 0 || cur.x > MAZE_SIZE-1 || cur.y > MAZE_SIZE-1)
		return 0; // 갈수 없다 

	if(maze[cur.x][cur.y] != WALL && maze[cur.x][cur.y] != VISITED && maze[cur.x][cur.y] != BACKTRACKED)
		return 1; // 못가는 상황이면 POP으로 되돌아갈 수 있다. 
	else {
		return 0;
	}
}

Data move(Data cur, int dir) {	
	
	cur.x = cur.x + offset[dir][0];
	cur.y = cur.y + offset[dir][1];
	
	return cur;
}
	
int main(void) {

	Stack stack; // 스택이 메모리 공간에 할당됩니다. 
	StackInit(&stack); // 스택 초기화
	Point cur; // 움직일 좌표
	
	int i, j, dir;
	
	// 시작점
	cur.x = 1;
	cur.y = 0;
	
	printf("시작점: %d, %d\n", cur.x, cur.y);
	SPush(&stack, cur);
	
	while(1) {
		if(maze[cur.x][cur.y] == -1) {
			printf("탈출 성공!\n"); // 현재 위치가 출구라면
			break;
		}

		if(maze[cur.x][cur.y] == VISITED || maze[cur.x][cur.y] == BACKTRACKED) {
			maze[cur.x][cur.y] = BACKTRACKED;
		} else {
			maze[cur.x][cur.y] = VISITED;
		}				
		int fowarded = 0; 
		
		for(dir = 0; dir < 4; dir++) {
			if(movable(cur, dir)) {
				// 현재 위치는 방문 처리 
				cur = move(cur, dir);
				SPush(&stack, cur); // 데이터 삽입시 동적 할당하므로 구조체로 데이터 접근 
				fowarded = 1;
				break;
			}
		}
		
		if(fowarded == 0) {
			
			if(SIsEmpty(&stack)) {
				printf("출구가 존재하지 않음 \n");
				break;
			}
			
			printf(" BACKTRACKED ");
			maze[cur.x][cur.y] = BACKTRACKED;
			cur = SPop(&stack);
			
		}
	}
	
	print_maze();
	
	return 0;
}
