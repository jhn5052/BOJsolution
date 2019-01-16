#include <stdio.h>
#include <string.h>
#define MAX 10000
#define true 1
#define false 0

typedef struct stack {
	int arr[MAX];
	int top;
}Stack;


void init(Stack *stack) {
	stack->top = -1;
}

int isFull(Stack *stack) {
	if (stack->top + 1 >= MAX) {
		return true;
	}
	return false;
}

int push(Stack *stack, int data) {
	if (isFull(stack) == true) {
		return 0;
	}
	stack->arr[(stack->top) + 1] = data;
}

int empty(Stack *stack) {
	if (stack->top = -1) {
		return 1;
	}
	return 0;
}
int pop(Stack *stack) {
	if (empty(stack) == 1) {
		return 0;
	}

	return stack->arr[(stack->top)--];

}
int size(Stack *stack) {
	return stack->top + 1;
}


int top(Stack *stack) {
	if (empty(stack) == true) {
		return -1;
	}
	return stack->arr[stack->top];
}

int main() {
	int num;
	char str[6];
	Stack stack;
	int i, k;
	scanf("%d", &num);
	fgetc(stdin);
	init(&stack);
	for (i = 0; i < num; i++) {
		scanf("%s", str);
		fgetc(stdin);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &k);
			fgetc(stdin);
			push(&stack, k);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d", pop(&stack));
		}
		else if (strcmp(str, "top") == 0) {
			printf("%d", top(&stack));
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d", size(&stack));
		}
	}
	return 0;
}