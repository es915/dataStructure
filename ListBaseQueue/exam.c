#include <stdio.h>
#include <stdlib.h>
#include 
#include "ListBaseQueue"

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
	
	srand(time(NULL));
	
	for(sec=0; sec<3600; sec++) {
		if(sec % CUSTOMER_TERM == 0) {
			switch(rand() % 3) {
				case 0:
					Enqueue(&q, CHE_TERM);
					break;
				case 1:
					Enqueue(&q, BUL_TERM);
					break;
				case 2:
					Enqueue(&q, DUB_TERM);
					break;
			}
		}
	}
	
	return 0;
}
