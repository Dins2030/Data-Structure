#include <stdio.h>
int push(int,int stack[],int);
int pop(int,int stack[]);
int peak(int,int stack[]);
int empty(int);
int display(int stack[],int);
int main(){
	int size;
	printf("Enter the stack size:\n");
	scanf("%d",&size);
	int top=-1;
	int stack[size];
	int ch;
	printf("1.Push\n");
	printf("2.pop\n");
	printf("3.peak\n");
	printf("4.empty\n");
	printf("5.display\n");
	printf("6.Exit");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	do{
		switch(ch){
			case 1:{push(top,stack,size);
				break;}
			case 2:{pop(top,stack);
				break;}
			case 3:{peak(top,stack);
				break;}
			case 4:{empty(top);
				break;}
			case 5:{display(stack,top);
				break;}}}
	while(ch==6);
	return 0;}
int push(int top,int stack[],int size){
	int element;
	printf("Enter the element\n");
	scanf("%d",&element);
	if(top>=size-1){
		printf("Overflow: The stack is full\n");}
	else{
		top=top+1;
		stack[top]=element;
		printf("Element added in the stack successfully\n");}
	return 0;}
int pop(int top,int stack[]){
	if(top==-1){
		printf("Underflow: The stack is empty\n");}
	else{
		printf("%d\n",stack[top]);
		top=top-1;}
	return 0;}
int peak(int top,int stack[]){
	if(top==-1){
		printf("Underflow: The stack is empty\n");}
	else{
		printf("%d\n",stack[top]);}
	return 0;}
int empty(int top){
	if(top==-1){
		printf("Stack empty\n");}
	else{
		printf("Stack is not empty\n");}
	return 0;}
int display(int stack[],int top){
	if(top==-1){
		printf("Underflow: The stack is empty\n");}
	else{
		int len=sizeof(stack)/sizeof(stack[0]);
		for(int i=(len-1);i<len;i--){
			printf("%d\n",stack[i]);}}
	return 0;}
		

