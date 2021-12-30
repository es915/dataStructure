#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// 초기화
void QueueInit(Queue * pq) {
	// 초기 상태 == 데이터 X -> 앞 뒤 = 0
	pq->front = 0; 
	pq->rear = 0;
}

// 비어있는지 확인
int QIsEmpty(Queue * pq) {
	// front와 rear가 가르키고 있는 데이터 인덱스가 같음 -> 비어있음
	if(pq->front == pq->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 다음 인덱스 추가
int NextPosIdx(int pos) {
	if(pos == QUE_LEN -1) { // 들어온 값이 Q 길이의 끝이다 -> 0번째 인덱스로 돌아 원형 리스트로 됨 
		return 0; 
	} else { 
		return pos+1; // Q 길이의 끝이 아니다 -> 다음 인덱스 추가 가능 -> 들어온 값의 인덱스에 +1
	}
}

// 데이터 삽입
void Enqueue(Queue * pq, Data data) { 
	if(NextPosIdx(pq->rear) == pq->front) { // rear의 다음 인덱스값이 front다 -> 가득참 

		printf("FULL\n");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear); // rear에 rear의 다음 인덱스값을 넣음
	pq->queArr[pq->rear] = data; // rear의 인덱스를 q 배열에 넣음
}

// 데이터 삭제
Data Dequeue(Queue * pq) {
	if(QIsEmpty(pq)) { // 비어있는지 체크
		printf("EMPTY\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front); // 선입선출로 인해 프론트를 앞으로 땅김
		
	return pq->queArr[pq->front]; // 당긴 프론트의 인덱스에 값을 팝시킴
}

// 데이터 뽑기
Data QPeek(Queue * pq) {
	if(QIsEmpty(pq)) { // 비어있는지 체크
		printf("EMPTY\n");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)]; // 프론트엔 데이터가 없음 -> 프론트 다음의 인덱스값을 출력함
}

// 데이터 갯수 뽑기
int getCount(Queue * pq) {
	return pq->rear - pq->front; // 레어의 인덱스(꼬리) - 프론트의 인덱스(머리) = 데이터 갯수
}
