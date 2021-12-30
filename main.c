#include <stdio.h>

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


int main(void) {
	int arr[5] = {5, 3, 2, 4, 1};
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));

	int i;
	
	for(i=0; i<5; i++) {
		printf("%d ", arr[i]);
	}	
	return 0;
}
