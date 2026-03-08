#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 25

typedef struct StackType {
    int Top;
    float Oprnd[SIZE];
} STACK;

STACK S;

void InitStack();
void Push(float num);
float Pop();
int StackEmpty();
void DisplayStack();
void Process(char Optr);
float EvalPostFix(char PostFix[]);

int main() {
    float result;
    char PostFix[SIZE];

    printf("\nProgram to Evaluate PostFix Expression \n");
    printf("Enter PostFix Expression: ");

    InitStack();

    scanf("%s", PostFix); 

    result = EvalPostFix(PostFix);

    printf("Result = %5.2f\n", result);
    return 0;
}

void InitStack() {
    S.Top = -1;
}

void Push(float num) {
    if(S.Top == SIZE - 1){
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.Oprnd[S.Top] = num;
}

float Pop() {
    float num;
    if(StackEmpty() == 1){
        printf("Stack Underflow.\n");
        return -1;
    }
    num = S.Oprnd[S.Top];
    S.Top--;
    return num;
}

int StackEmpty() {
    if (S.Top == -1) {
        return 1; 
    } else {
        return 0;
    }
}

void DisplayStack() {
    int i;

    if (StackEmpty() == 1) {
        printf("Stack is EMPTY.\n");
        return;
    }
    for (i = S.Top; i >= 0; i--) {
        printf("%5.2f\n", S.Oprnd[i]);
    }
}

void Process(char Optr) {
    float result = 0;
    float n1, n2;

    n2 = Pop(); 
    n1 = Pop();
    
    switch (Optr){
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '^':
            result = pow(n1, n2);
            break;
        case '/':
            if(n2 != 0){
                result = n1 / n2;
            } else {
                printf("Divide by Zero Error.\n");
            }
            break;
        }
    Push(result);
}

float EvalPostFix(char PostFix []) {
    char ch;
    float result, num;
    int i = 0;
    
    while((ch = PostFix[i++]) != '\0'){
        if(ch >= '0' && ch <= '9'){
            num = ch - '0';
            Push(num);
        }
        else if(strchr("+-/*^", ch)){
            Process(ch);
        }
    }
    result = Pop();
    return result;
}