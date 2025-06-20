#include <stdio.h>
void push(char stack[], int size, int *top);
void reverse_print(char stack[], int top);
int main() {
    int size;
    printf("Enter the stack size: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    char stack[size];
    int top = 0;  
    reverse_print(stack, top);
    return 0;
}
void push(char stack[], int size, int *top) {
    char ele;
    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf(" %c", &ele);  
        stack[*top] = ele;
        (*top)++;
    }
}
void reverse_print(char stack[], int top) {
    if (top == 0) {
        printf("Underflow: Stack empty\n");
        return;
    }
    printf("Reversed stack elements:\n");
    for (int j = top - 1; j >= 0; j--) {
        printf("%c\n", stack[j]);
    }
}

