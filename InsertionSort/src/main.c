#include <stdio.h>
#include <math.h>

//----------------functions----------------
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(void)
{
	int arr[] = {16, 19, 15, 04, 18};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	system("pause");
	return (0);
}

void insertionSort(int arr[], int n){
	int i, j, key;

	for ( i = 1; i < n; i++){
		
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr [j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}	
}

void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}