#include <stdio.h>
#include "ArrayList.h"

// 주소로 접근하는 이유 Call by Refernce 

void ListInit(List * plist) // 초기화 기능
{
	(plist->sizeOfData) = 0; // (*plist).sizeOfData => plist->numOfData
	(plist->curPosition) = -1; // 처음 인덱스가 0부터 시작이므로 -1로 초기화 해줍니다. 찾기 함수에서 사용합니다. 
}

void LInsert(List * plist, LData data) // 데이터 삽입 기능 
{
	if(plist->sizeOfData >= LIST_LEN) {
		printf("저장이 불가능합니다. \n");
		return; // 함수를 끝내는 역할, 반환하는 역할, 현재는 void이므로 반환이 필요 없습니다. 
	}
	
	plist->arr[plist->sizeOfData] = data; // 데이터 삽입 
	(plist->sizeOfData)++; // 사이즈 1 추가
}

int LFirst(List * plist, LData * pdata) // 첫 데이터 참조 기능
{
	if(plist->sizeOfData == 0)
		return FALSE; // 찾는 값이 없기때문에 FALSE 
		
	(plist->curPosition) = 0;
	*pdata = plist->arr[0]; // 임시적으로 데이터를 저장 
	return TRUE;
}

int LNext(List * plist, LData * pdata) // 두번째 데이터 참조 기능 
{
	if(plist->curPosition >= (plist->sizeOfData)-1)
		return FALSE;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

LData LRemove(List * plist) // 데이터 삭제 기능
{
	int rpos = plist->curPosition;
	int size = plist->sizeOfData;
	int i;
	LData rdata = plist->arr[rpos]; // 삭제된 값 반환하기 위해 작성한 코드입니다.
	
	for(i=rpos; i < size-1; i++)
		plist->arr[i] = plist->arr[i+1]; // 다음 인덱스의 값을 덮어 씌워줍니다.
		
	(plist->sizeOfData)--; // size
	(plist->curPosition)--; // 현재 위치
	
	return rdata;
}

int LCount(List * plist) // 데이터의 총 합을 구하는 기능 
{
	return plist->sizeOfData;	
}
