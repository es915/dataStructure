//#include <stdio.h>
//#include <stdlib.h>
//#include "CLinkedList.h"
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(void) {
//	List list;
//	ListInit(&list);
//	int data;
//	int i = 0;
//	
//	// LInsert를 이용해서 6~10까지 데이터를 입력해주세요.
//	// LInsertFront를 이용해서 1~5까지 데이터를 입력해주세요.
//	// 데이터는 오름차순으로 정렬됩니다. 
//	LInsert(&list, 6);
//	LInsert(&list, 7);
//	LInsert(&list, 8);
//	LInsert(&list, 9);
//	LInsert(&list, 10);
//	
//	LInsertFront(&list, 5);
//	LInsertFront(&list, 4);
//	LInsertFront(&list, 3);
//	LInsertFront(&list, 2);
//	LInsertFront(&list, 1);
//	 
//	// 데이터를 30회 연속으로 출력해주세요.
//	// 원형 연결리스트는 마지막 데이터 다음 데이터로 다시 첫번째 데이터를 순회합니다.
//	// LNext를 이용하여 30회 연속으로 출력해주세요. for문 또는 while문으로 이용 가능합니다. 
//	if(LFirst(&list, &data)) {
//		printf("%d ", data);
//		
//		while(LNext(&list, &data)) {
//			if(i == 29) {
//				break;
//			}
//			printf("%d ", data);
//			
//			i++;
//		}
//	}
//	
//	printf("\n\n");
//	
//	// 2의 배수를 찾아서 모두 삭제합니다.
//	// 데이터의 크기는 LCount 함수를 이용합니다. 
//	int size = LCount(&list);
//	
//	if(size != 0) {
//		LFirst(&list, &data);
//		if(data%2 == 0) {
//			LRemove(&list);
//		}
//		
//		for(i=0; i<size-1; i++)
//		{
//			LNext(&list, &data);
//			if(data%2 == 0) {
//				LRemove(&list);
//			}
//		}
//	}
//	
//	// 전체 데이터를 1회 출력합니다.
//	i = 0;
//	size = LCount(&list);
//	
//	if(LFirst(&list, &data)) {
//		printf("%d ", data);
//		
//		while(LNext(&list, &data)) {
//			if(i == size - 1) {
//				break;
//			}
//			printf("%d ", data);
//			
//			i++;
//		}
//	}
//	
//	return 0;
//}
