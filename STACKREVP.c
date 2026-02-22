/* To reverse a string using stack
   suresh
   23/02/2026
   reverse.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 30

typedef struct stack
{
    char str[SIZE];
    int top;
} Stack;

Stack s;

void initStack();
int stackempty();
void push(char x);
char pop();

void initStack()
{
    s.top = 0;   // Start from -1 (important)
}

int stackempty()
{
    return s.top == 0;  // Stack is empty when top is 0
}

void push(char x)
{
    if(s.top == SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }else{
        s.top++;
        s.str[s.top] = x;
    }
}

char pop()
{
    if(stackempty())
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        char x=s.str[s.top];
            s.top--;
            return x;
    }
}

int main()
{
    initStack();

    char str[100], reverse[100];

    printf("Enter a string: ");
    scanf("%s", str);
   
   int i = 0;

    // Push all characters into stack
    while(str[i] != '\0')
    {
       push(str[i]);
        i++;
    }

    // Pop to create reverse string
    i = 0;
    while(!stackempty())
    {
        reverse[i] = pop();
     i++;
    }
    reverse[i] = '\0';

    printf("Reversed string: %s\n", reverse);

    // Check palindrome
    if(strcmp(str, reverse) == 0)
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
