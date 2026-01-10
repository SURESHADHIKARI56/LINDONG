#include<stdio.h>
void INPUTARRAY(int arr[], int n)
{
    int i;
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void PRINTARRAY(int arr[], int n)
{
    int i;
    printf("Array elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void BUBBLESORT(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int BINARYSEARCH(int arr[],int n,int key)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            return mid+1;  //position is index+1
        }
        else if (arr[mid]<key)
        {
            low =mid+1;
        }
        else
        {
            high=mid-1;
    }
}
    return -1;

}
int main()
{
    int n, arr[100], key, result;
    printf("How many elements: ");
    scanf("%d", &n);
    INPUTARRAY(arr, n);
    PRINTARRAY(arr, n);
    BUBBLESORT(arr, n);
    PRINTARRAY(arr, n);
    printf("Enter element to search: ");
    scanf("%d", &key);
    result = BINARYSEARCH(arr, n, key);
    if(result != -1)  //if we write result ==1 then it will show position 1 only
    {
        printf("NUMBER %d found AT %d POSITION ",key,result);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}
