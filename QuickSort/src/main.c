#include <stdio.h>

//---------functions----------
void swap(int *xp, int *yp);
int partition(int arr[], int min, int max);
void quickSort(int arr, int min, int max);
void printArray(int arr[], int size);




int main()
{
	int arr [] = {84, 82, 99, 54 , 59};

	int n = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	system("pause");
	return (0);
}

void swap(int *xp, int *yp){
	int aux;

	aux = *xp;
	*xp = *yp;
	*yp = aux;
}

int partition(int arr[], int min, int max){
	int pivot = arr[max];
	int i = (min -1);

	for (int j = min; j < max; j++){
		if (arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}		
	}

	swap(&arr[i + 1], &arr[max]);

	return (i+1);
}

void quickSort(int arr, int min, int max){
	if (min < max){
		int aux = partition(arr, min, max);
		quickSort(arr, min, aux - 1);
		quickSort(arr, aux + 1, max);
	}	
}

void printArray(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}