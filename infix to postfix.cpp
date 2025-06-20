#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX-1) stack[++top] = c;
}
char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}
char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int isOperand(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}
void infixToPostfix(const char *infix, char *postfix) {
    int i=0, j=0;
    char c;
    while ((c = infix[i++]) != '\0') {
        if (isOperand(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else if (isOperator(c)) {
            while (top >= 0 && isOperator(peek()) &&
                   ((prec(peek()) > prec(c)) ||
                    (prec(peek()) == prec(c) && c != '^'))) {
                postfix[j++] = pop();
            }
            push(c);
        }      
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix: ");
    if (!fgets(infix, MAX, stdin)) return 0;
    infix[strcspn(infix,"\n")] = '\0'; 
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}

