/*SELECTION SORT
NAME:LINDONG
DATE:23/01/2026
FILENAME:SELECTIONSORT.c*/
#include <stdio.h>
void InputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void PrintArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void SelectionSort(int arr[], int n) {
    int min, loc;
    for (int i = 0; i < n - 1; i++) {
        min = arr[i];
        loc = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                loc = j;
            }
        } //swap arr[i] and arr[loc] 
        arr[loc] = arr[i];
        arr[i] = min;
    }       
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    InputArray(arr, n);
    printf("Before sorting:\n");
    PrintArray(arr, n);
    SelectionSort(arr, n);
    printf("After sorting:\n");
    PrintArray(arr, n);
    return 0;
}