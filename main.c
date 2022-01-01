#include <stdio.h>

// 버블 정렬 -> 오름차순
void BubbleSort(int arr[], int n) {
	int i, j, temp;
	
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(arr[j]>arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}	
		}
	}
}

void SelectionSort(int arr[], int n) {
    int i, j, temp, minIdx;

    for(i=0; i<n-1; i++) {
        minIdx = i;
        for(j=1+i; j<n; j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }   
        }
        
        temp = arr[j];
        arr[j] = arr[minIdx];
        arr[minIdx] = temp;
    }

    // 1. 배열의 처음부터 끝까지 탐색 -> 최솟값 찾기
    // 2. 찾은 최솟값은 첫번째 위치에 배정
    // 3. 배정을 끝내고 2번째 위치 탐색
    // 4. N-1번 반복
}


int main(void) {
	int arr[5] = {5, 3, 2, 4, 1};
	
	// BubbleSort(arr, sizeof(arr)/sizeof(int));
    SelectionSort(arr, sizeof(arr)/sizeof(int));

	int i;
	
	for(i=0; i<5; i++) {
		printf("%d ", arr[i]);
	}	
	return 0;
}
