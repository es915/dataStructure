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
//	// LInsert�� �̿��ؼ� 6~10���� �����͸� �Է����ּ���.
//	// LInsertFront�� �̿��ؼ� 1~5���� �����͸� �Է����ּ���.
//	// �����ʹ� ������������ ���ĵ˴ϴ�. 
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
//	// �����͸� 30ȸ �������� ������ּ���.
//	// ���� ���Ḯ��Ʈ�� ������ ������ ���� �����ͷ� �ٽ� ù��° �����͸� ��ȸ�մϴ�.
//	// LNext�� �̿��Ͽ� 30ȸ �������� ������ּ���. for�� �Ǵ� while������ �̿� �����մϴ�. 
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
//	// 2�� ����� ã�Ƽ� ��� �����մϴ�.
//	// �������� ũ��� LCount �Լ��� �̿��մϴ�. 
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
//	// ��ü �����͸� 1ȸ ����մϴ�.
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
