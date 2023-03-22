// This program uses Bubble Sorting and tracks the number of swaps that occur each pass/iteration

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 9

// Swaps the values of two given integers using pointers
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Displays the number of swaps that occur in a given pass
void displaySwaps(int pass, int swaps)
{
    printf("Pass #%d: %d\n", pass, swaps);
}

// A function to implement bubble sort  
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        int swaps = 0;
        // Last i elements are already in place. So, stop j before n-i
        // As we will compare j with j+1, we will stop j before n-i-1
        for (j = 0; j < n-i-1; j++)  
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]); 
                swaps++;
            }          
        }
        displaySwaps(i + 1, swaps);
    }
}

// Displays a given array to the terminal
void displayArray(int arr[], int size)
{
    int i;
    printf("Array: [ ");
    for (i=0; i < size; i++)  
        printf("%d ", arr[i]);
    printf("]\n");
}

int main(void)
{
    int og_array[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    displayArray(og_array, SIZE);
    printf("~~~~~~~\n");
    bubbleSort(og_array, SIZE);
    printf("~~~~~~~\n");
    displayArray(og_array, SIZE);
    return 0;
}