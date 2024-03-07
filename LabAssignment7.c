/*
Auther: Quianna Numa
Title:  Lab Assignment 7
Class:  COP3502 Sec 0003
*/

#include <stdio.h>

// Function prototypes
void swap(int *xp, int *yp);
void printArray(int arr[], int swaps[][2], int size);
void bubbleSort(int arr[], int swaps[][2], int n);
void selectionSort(int arr[], int swaps[][2], int n);
void updateSwaps(int swaps[][2], int n, int a, int b);

int main() {
    // Declare variables
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps1[][2] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    int swaps2[][2] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};
    int n = 9;

    //  use bubble sort on arr1
    printf("\nArray 1 Bubble Sort:\n--------------------\n");
    bubbleSort(arr1, swaps1, n);

    //  use selection sort on arr1
    printf("\nArray 1 Selection Sort:\n-----------------------\n");
    selectionSort(arr1, swaps1, n);

    //  use bubble sort on arr2
    printf("\nArray 2 Bubble Sort:\n--------------------\n");
    bubbleSort(arr2, swaps2, n);

    //  use selection sort on arr2
    printf("\nArray 2 Selection Sort:\n-----------------------\n");
    selectionSort(arr2, swaps2, n);

    return 0;
}

void swap(int *xp, int *yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int swaps[][2], int n) 
{
    int i, j, total = 0;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
                updateSwaps(swaps, n, arr[j], arr[j + 1]);
                total++;
            }
        }
    }
    printArray(arr, swaps, n);
    printf("Total # of swaps: %d\n", total);
}

void selectionSort(int arr[], int swaps[][2], int n)
{
	int i, j, min_idx, temp, total = 0;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;

		for (j = i+1; j < n; j++)
		    if (arr[j] < arr[min_idx])
			    min_idx = j;
        
		// Swap the found minimum element with the first element
		swap(&arr[i], &arr[min_idx]);
        updateSwaps(swaps, n, arr[i], arr[min_idx]);
        total++;
	}
    
    printArray(arr, swaps, n);
    printf("Total # of swaps: %d\n", total);
}

void updateSwaps(int swaps[][2], int n, int a, int b) 
{
    // Loop through swaps rows
    for (int r = 0; r < n; r++) 
    {
        if (a == swaps[r][0])
            swaps[r][1]++;
        if (b == swaps[r][0])
            swaps[r][1]++;
    }
}

void printArray(int arr[], int swaps[][2], int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d:\t", arr[i]);
        for (int r = 0; r < size; r++) 
        {
            if (swaps[r][0] == arr[i])
                printf("%d", swaps[r][1]);
        }
        printf("\n");
    }
}
