#include <stdio.h>

/* Function to input elements into the array */
void inputArray(int a[], int n)
{
    int i;
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

/* Function to print array elements */
void printArray(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* Function to sort array using Bubble Sort */
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* Main program */
int main()
{
    int a[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    inputArray(a, n);

    printf("\nArray before sorting:\n");
    printArray(a, n);

    bubbleSort(a, n);

    printf("\nArray after Bubble Sort:\n");
    printArray(a, n);

    return 0;
}
