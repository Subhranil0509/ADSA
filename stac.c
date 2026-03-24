#include <stdio.h>
#define MAX 100   

int stack[MAX];
int top = -1;

int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No top element.\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(40);
    push(99);
    push(55);

    printf("Top element (peek): %d\n", peek());

    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    printf("Top element (peek): %d\n", peek());

    if (isEmpty())
        printf("Stack is empty now.\n");
    else
        printf("Stack is not empty.\n");

    return 0;
}
