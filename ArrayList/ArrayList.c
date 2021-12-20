#include <stdio.h>
#include "ArrayList.h"

// �ּҷ� �����ϴ� ���� Call by Refernce 

void ListInit(List * plist) // �ʱ�ȭ ���
{
	(plist->sizeOfData) = 0; // (*plist).sizeOfData => plist->numOfData
	(plist->curPosition) = -1; // ó�� �ε����� 0���� �����̹Ƿ� -1�� �ʱ�ȭ ���ݴϴ�. ã�� �Լ����� ����մϴ�. 
}

void LInsert(List * plist, LData data) // ������ ���� ��� 
{
	if(plist->sizeOfData >= LIST_LEN) {
		printf("������ �Ұ����մϴ�. \n");
		return; // �Լ��� ������ ����, ��ȯ�ϴ� ����, ����� void�̹Ƿ� ��ȯ�� �ʿ� �����ϴ�. 
	}
	
	plist->arr[plist->sizeOfData] = data; // ������ ���� 
	(plist->sizeOfData)++; // ������ 1 �߰�
}

int LFirst(List * plist, LData * pdata) // ù ������ ���� ���
{
	if(plist->sizeOfData == 0)
		return FALSE; // ã�� ���� ���⶧���� FALSE 
		
	(plist->curPosition) = 0;
	*pdata = plist->arr[0]; // �ӽ������� �����͸� ���� 
	return TRUE;
}

int LNext(List * plist, LData * pdata) // �ι�° ������ ���� ��� 
{
	if(plist->curPosition >= (plist->sizeOfData)-1)
		return FALSE;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

LData LRemove(List * plist) // ������ ���� ���
{
	int rpos = plist->curPosition;
	int size = plist->sizeOfData;
	int i;
	LData rdata = plist->arr[rpos]; // ������ �� ��ȯ�ϱ� ���� �ۼ��� �ڵ��Դϴ�.
	
	for(i=rpos; i < size-1; i++)
		plist->arr[i] = plist->arr[i+1]; // ���� �ε����� ���� ���� �����ݴϴ�.
		
	(plist->sizeOfData)--; // size
	(plist->curPosition)--; // ���� ��ġ
	
	return rdata;
}

int LCount(List * plist) // �������� �� ���� ���ϴ� ��� 
{
	return plist->sizeOfData;	
}
