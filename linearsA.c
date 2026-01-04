#include <stdio.h>

/* Function to input array elements */
void inputArray(int a[], int n)
{
    int i;
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

/* Function to search element using linear search */
int linearSearchArray(int a[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return 1;   // found
    }
    return -1;          // not found
}

int main()
{
    int a[50], n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    inputArray(a, n);

    printf("Enter number to search: ");
    scanf("%d", &key);

    result = linearSearchArray(a, n, key);

    if(result == 1)
        printf("Number FOUND in array\n");
    else
        printf("Number NOT FOUND in array\n");

    return 0;
}
