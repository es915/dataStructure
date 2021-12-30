#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

int main2(int argc, char *argv[]) {
	
	Queue q;
	QueueInit(&q);
	
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	Enqueue(&q, 6);

	while(!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));	
	}
	
	return 0;
}
