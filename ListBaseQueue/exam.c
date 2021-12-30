#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "ListBaseQueue.h"

// 1시간 동안 주문 갯수 
#define CUSTOMER_TERM 30
#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 45
#define BUL_TERM 60
#define DUB_TERM 80
int main(void) {
	Queue q;
	QueueInit(&q);
	
	int sec;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0; 
	int cheMade = 0, bulMade = 0, dubMade = 0; 
	int makeProc = 0;
	
	srand(time(NULL));
	
	for(sec=0; sec<3600; sec++) {
		if(sec % CUSTOMER_TERM == 0) {
			switch(rand() % 3) {
				case CHE_BUR:
					Enqueue(&q, CHE_TERM);
					cheOrder++;
					break;
				case BUL_BUR:
					Enqueue(&q, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:
					Enqueue(&q, DUB_TERM);
					dubOrder++;
					break;
			}
		}
		
		if(makeProc<=0 && !QIsEmpty(&q)) {
			makeProc = Dequeue(&q);
			
			switch(makeProc) {
				case CHE_TERM:
					cheMade++;
					break;
				case BUL_TERM:
					bulMade++;
					break;
				case DUB_TERM:
					dubMade++;
					break;
			}
		}
		makeProc--;
	}
	
	printf("Simulation Report\n");
	printf("치즈버거 주문량 : %d, 실제 주문 처리량 : %d \n", cheOrder, cheMade);
	printf("불고기버거 주문량 : %d, 실제 주문 처리량 : %d \n", bulOrder, bulMade);
	printf("더블버거 주문량 : %d, 실제 주문 처리량 : %d \n", dubOrder, dubMade);
	
	return 0;
}
