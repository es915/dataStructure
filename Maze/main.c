#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

#define MAZE_SIZE 10
#define PATH 0 // ������ �� �ִ� ��ġ
#define WALL 1 // ������ �� ���� ��ġ
#define VISITED 2 // �̹� �湮�� ��ġ
#define BACKTRACKED 3 // �湮�ߴٰ� �ǵ��� ���� ��ġ

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


// �ϵ����� ��ĭ�� 
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
		return 0; // ���� ���� 

	if(maze[cur.x][cur.y] != WALL && maze[cur.x][cur.y] != VISITED && maze[cur.x][cur.y] != BACKTRACKED)
		return 1; // ������ ��Ȳ�̸� POP���� �ǵ��ư� �� �ִ�. 
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

	Stack stack; // ������ �޸� ������ �Ҵ�˴ϴ�. 
	StackInit(&stack); // ���� �ʱ�ȭ
	Point cur; // ������ ��ǥ
	
	int i, j, dir;
	
	// ������
	cur.x = 1;
	cur.y = 0;
	
	printf("������: %d, %d\n", cur.x, cur.y);
	SPush(&stack, cur);
	
	while(1) {
		if(maze[cur.x][cur.y] == -1) {
			printf("Ż�� ����!\n"); // ���� ��ġ�� �ⱸ���
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
				// ���� ��ġ�� �湮 ó�� 
				cur = move(cur, dir);
				SPush(&stack, cur); // ������ ���Խ� ���� �Ҵ��ϹǷ� ����ü�� ������ ���� 
				fowarded = 1;
				break;
			}
		}
		
		if(fowarded == 0) {
			
			if(SIsEmpty(&stack)) {
				printf("�ⱸ�� �������� ���� \n");
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
