#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int v) {
    if (top < MAX - 1) 
	stack[++top] = v;
}
int pop() {
    if (top >= 0) 
	return stack[top--];
    return 0; 
}
int isDigit(char c) {
    return c >= '0' && c <= '9';
}
int evaluatePostfix(const char *exp) {
    int i = 0;
    char c;
    while ((c = exp[i++]) != '\0') {
        if (isDigit(c)) {
            push(c - '0');  
        } else {
            int b = pop();
            int a = pop();
            int res = 0;
            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                default: break;}
            push(res);}}
    return pop();}
int main() {
    char exp[MAX];
    printf("Enter postfix expression (no spaces): ");
    if (scanf("%s", exp)==0){
	return 0;}
    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);
    return 0;
}

