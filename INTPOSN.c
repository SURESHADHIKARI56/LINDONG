/*INFIX NOTATION TO POST FIX NOTATION
MARTIAL
INFPOS.c
*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

typedef struct StackType {
    char A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(char c);
char Pop();
char Peek(); 
int StackEmpty();
int Precedence(char op);
void InfixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    InitStack();
    
    InfixToPostfix(infix, postfix);

    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}

void InitStack() {
    S.Top = -1;
}

int StackEmpty() {
    if (S.Top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void Push(char c) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = c;
}

char Pop() {
    char c;
    if (StackEmpty() == 1) {
        return '\0'; 
    }
    c = S.A[S.Top];
    S.Top--;
    return c;
}

char Peek() {
    if (StackEmpty() == 1) {
        return '\0';
    }
    return S.A[S.Top];
}

int Precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // Lowest precedence for '('
}

void InfixToPostfix(char infix[], char postfix[]) {
    int i = 0;
    int j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(') {
            Push(ch);
        }
        else if (ch == ')') {
            while (StackEmpty() == 0 && Peek() != '(') {
                postfix[j] = Pop();
                j++;
            }
            Pop();
        }
        else {
            while (StackEmpty() == 0 && Precedence(Peek()) >= Precedence(ch)) {
                postfix[j] = Pop();
                j++;
            }
            Push(ch);
        }
        i++;
    }
    while (StackEmpty() == 0) {
        postfix[j] = Pop();
        j++;
    }
    postfix[j] = '\0'; 
}