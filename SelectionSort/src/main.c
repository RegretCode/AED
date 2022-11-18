#include <stdio.h>

//------------functions-------------
void swap(int *xp, int *yp);
void selectionSort (int arr[], int n);
void printArray(int arr[], int n);


int main(void)
{
	int arr[] = {16, 19, 15, 4, 18};
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);
	printArray(arr, n);
	
	system("pause");
	return (0);
}

void swap(int *xp, int *yp){
	int aux = *xp;
	*xp = *yp;
	*yp = aux;
}

void selectionSort (int arr[], int n){
	int i, j, minIdx;

	for ( i = 0; i < n-1; i++){
		minIdx = i;

		for (j = i + 1; j < n; j++){
			if (arr[j] < arr[minIdx]){
				minIdx = j;
			}
		swap(&arr[minIdx], &arr[i]);
		}		
	}	
}

void printArray(int arr[], int n){

	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}