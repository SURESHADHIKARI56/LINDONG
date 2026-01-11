/*INSERTION SORT
NAME:SURESH
DATE:23/01//2026
FILENAME:INSSORT.c*/
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
void InsertionSort(int arr[], int n) {
    int key, j;
    for (int i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    InsertionSort(arr, n);
    printf("After sorting:\n");
    PrintArray(arr, n);
    return 0;
}