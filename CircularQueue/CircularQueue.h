#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

typedef struct _cQueue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

// 초기화
void QueueInit(Queue * pq);
// 비어있는지 체크
int QIsEmpty(Queue * pq);
// 데이터 추가
void Enqueue(Queue * pq, Data data);
// 데이터 삭제
Data Dequeue(Queue * pq);
// 값 뽑기
Data QPeek(Queue * pq);

#endif
