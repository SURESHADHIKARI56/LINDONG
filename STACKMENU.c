/*STACK MENU PROGRAM
NAME:HUANG
DATE:02/03/2026
FILE:STACKMENU.c
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct StackType
{
    int A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(int num);
int Pop();
void Display();

int main()
{
    int choice, num, popnum;

    InitStack();

    while(1)
    {
        printf("\nSTACK MENU");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:{
                int num,i,n;
                printf("Enter number of elements to push: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++)
                {
                    printf("Enter number to push: ");
                    scanf("%d", &num);
                    Push(num);
                }   
                break;
            }

            case 2:
                popnum = Pop();
                if(popnum != -1)
                    printf("Deleted element = %d\n", popnum);
                break;

            case 3:
                Display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}

void InitStack()
{
    S.Top = 0;
}

void Push(int num)
{
    if(S.Top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    S.Top++;
    S.A[S.Top] = num;
}

int Pop()
{
    int num;

    if(S.Top == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    num = S.A[S.Top];
    S.Top--;

    return num;
}

void Display()
{
    int i;

    if(S.Top == 0)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");

    for(i = S.Top; i > 0; i--)
    {
        printf("%d\n", S.A[i]);
    }
}