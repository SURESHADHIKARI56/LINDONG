/*stack program*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct stack
{
    long long fact[SIZE];
    int top;
}Stack;
Stack s;
void initStack()
{
    s.top=0;
}
void push(int x)
{
    if(s.top==SIZE-1)
    {
        printf("stack is full\n");
        return;
    }
    else{
        s.top++;
        s.fact[s.top]=x;
    }
}
int pop()
{
    if(s.top==0)
    {
        printf("stack is empty\n");
        return -1;
    }
    else{
        int x=s.fact[s.top];
        s.top--;
        return x;
    }
}
int main()
{
    /* -------- Factorial using your algorithm -------- */

    int N, x;
    long long fact;
    int i;   // use different variable

    printf("Enter N for factorial: ");
    scanf("%d", &N);

    initStack();   // clear stack

    i = 1;
    push(1);

    while(i <= N)
    {
        x = pop();
        push(x * i);
        i = i + 1;
    }

    fact = pop();
    printf("Factorial of %d = %lld\n", N, fact);

    return 0;
}
