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
void display()
{
    if(s.top==0)
    {
        printf("stack is empty\n");
        return;
    }
    int i;
    for(i=s.top;i>=0;i--)
    {
        printf("%d ",s.fact[i]);
    }
    printf("\n");
}

int main()
{
    initStack();

    int n, num;

    printf("How many numbers you want to push? ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        push(num);
    }

    display();

  
    int k;
    printf("How many numbers you want to pop? ");
    scanf("%d", &k);

    for(int i = 1; i <= k; i++)
    {
        if(s.top == 0)
        {
            printf("Stack became empty\n");
            break;
        }
        printf("Popped: %d\n", pop());
    }

    display();
    /* -------- Factorial using your algorithm -------- */

    int N, x;
    long long fact;
    int j;   // use different variable

    printf("Enter N for factorial: ");
    scanf("%d", &N);

    initStack();   // clear stack

    j = 1;
    push(1);

    while(j <= N)
    {
        x = pop();
        push(x * j);
        j = j + 1;
    }

    fact = pop();
    printf("Factorial of %d = %lld\n", N, fact);

    return 0;
}
