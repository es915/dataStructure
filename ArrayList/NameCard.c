#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"


NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);	
	strcpy(newCard->phone, phone);
	
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("이름 : %s , 전화번호 : %s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name){
//	두 매개변수가 같다면 0, 같지 않다면 다른수 
	return strcmp(pcard->name, name);
}

void ChangePhoneNumber(NameCard * pcard, char * phone){
	strcpy(pcard->phone, phone);
}
