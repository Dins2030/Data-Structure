#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Overflow: Queue is full\n");} 
		else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);}}
void dequeue() {
    if (front == -1 || front > rear){
        printf("Underflow: Queue is empty ()\n");} 
		else {
        printf("Dequeued: %d\n", queue[front]);
        front++;}}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");} 
		else {
        printf("Queue contents: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);}
        printf("\n");}}
int main() {
    int choice, value;   
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
		}
	}
} 
