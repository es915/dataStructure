#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// �ʱ�ȭ
void QueueInit(Queue * pq) {
	// �ʱ� ���� == ������ X -> �� �� = 0
	pq->front = 0; 
	pq->rear = 0;
}

// ����ִ��� Ȯ��
int QIsEmpty(Queue * pq) {
	// front�� rear�� ����Ű�� �ִ� ������ �ε����� ���� -> �������
	if(pq->front == pq->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ���� �ε��� �߰�
int NextPosIdx(int pos) {
	if(pos == QUE_LEN -1) { // ���� ���� Q ������ ���̴� -> 0��° �ε����� ���� ���� ����Ʈ�� �� 
		return 0; 
	} else { 
		return pos+1; // Q ������ ���� �ƴϴ� -> ���� �ε��� �߰� ���� -> ���� ���� �ε����� +1
	}
}

// ������ ����
void Enqueue(Queue * pq, Data data) { 
	if(NextPosIdx(pq->rear) == pq->front) { // rear�� ���� �ε������� front�� -> ������ 

		printf("FULL\n");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear); // rear�� rear�� ���� �ε������� ����
	pq->queArr[pq->rear] = data; // rear�� �ε����� q �迭�� ����
}

// ������ ����
Data Dequeue(Queue * pq) {
	if(QIsEmpty(pq)) { // ����ִ��� üũ
		printf("EMPTY\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front); // ���Լ���� ���� ����Ʈ�� ������ ����
		
	return pq->queArr[pq->front]; // ��� ����Ʈ�� �ε����� ���� �˽�Ŵ
}

// ������ �̱�
Data QPeek(Queue * pq) {
	if(QIsEmpty(pq)) { // ����ִ��� üũ
		printf("EMPTY\n");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)]; // ����Ʈ�� �����Ͱ� ���� -> ����Ʈ ������ �ε������� �����
}

// ������ ���� �̱�
int getCount(Queue * pq) {
	return pq->rear - pq->front; // ������ �ε���(����) - ����Ʈ�� �ε���(�Ӹ�) = ������ ����
}
