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

	for(i=0; i<MAZE_SIZE; i++) { // 2차원 배열이기 때문에 for문 이중 중첩
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

// 이동 가능한 여부
int movable(Data cur, int dir) {
	
	cur.x = cur.x + offset[dir][0]; // x좌표 이동 - 2행중 0번째만 x좌표에 해당하여 0을 넣음
	cur.y = cur.y + offset[dir][1]; // y좌표 이동 - 2행중 1번째만 y좌표에 해당하여 1을 넣음
	
	if(cur.x < 0 || cur.y < 0 || cur.x > MAZE_SIZE-1 || cur.y > MAZE_SIZE-1) // 이동시킨 좌표가 메이지사이즈를 초과하는지 확인함
		return 0; // 갈수 없다 - 초과했다면 이동할수 없음

	if(maze[cur.x][cur.y] != WALL && maze[cur.x][cur.y] != VISITED && maze[cur.x][cur.y] != BACKTRACKED) // 이동시킨 좌표가 벽, 방문한길, 되돌아온길 인지 체크
		return 1; // 못가는 상황이면 POP으로 되돌아갈 수 있다. - 벽, 방문한길, 되돌아온길이 아닐시
	else {
		return 0;
	}
}

// 이동
Data move(Data cur, int dir) {	
	
	cur.x = cur.x + offset[dir][0]; // x좌표에 이동시킬 좌표값을 넣음
	cur.y = cur.y + offset[dir][1]; // x좌표에 이동시킬 좌표값을 넣음
	
	return cur; // 이동시킨 좌표를 넣은 좌표값을 리턴
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

		if(maze[cur.x][cur.y] == VISITED || maze[cur.x][cur.y] == BACKTRACKED) { // 현재 서있는 좌표가 방문한길인지, 돌아온길인지 체크
			maze[cur.x][cur.y] = BACKTRACKED; // 맞으면 돌아온길 체크
		} else {
			maze[cur.x][cur.y] = VISITED; // 아니면 지나간 길이 아니니 방문한길로 체크
		}				
		
		int fowarded = 0; // 지나갈수 있는 길이 있는지 체크
		
		for(dir = 0; dir < 4; dir++) {
			if(movable(cur, dir)) {
				// 현재 위치는 방문 처리 
				cur = move(cur, dir);
				SPush(&stack, cur); // 데이터 삽입시 동적 할당하므로 구조체로 데이터 접근 
				fowarded = 1; // 한번이라도 이동하면 fowarded 1로 체크
				break;
			}
		}
		
		if(fowarded == 0) { // 이동이 없다 -> 지나갈 길이 없다 -> 돌아가야함
			
			if(SIsEmpty(&stack)) {
				printf("출구가 존재하지 않음 \n");
				break;
			}
			
			printf(" BACKTRACKED ");
			maze[cur.x][cur.y] = BACKTRACKED;
			cur = SPop(&stack);
			
		}
	}
	
	print_maze(); // 컴퓨터가 출구를 찾는 과정을 출력하는 함수
	
	return 0;
}
