//Nitish Kumar Sonthalia
//Stack Structure Implimentaion
#include<stdio.h>
#include<stdlib.h>

struct MyStack {
    int top;
    int *stack;
    int max;
};

struct MyStack buildNewStack() {
    struct MyStack newStack;
    newStack.top = -1;
    newStack.max = 10;
    newStack.stack = (int *) malloc(newStack.max * sizeof(int));
    return newStack;
}

void push(struct MyStack *myStack, int data) {
    if(myStack->top == myStack->max - 1) {
        printf("Stack Overflow (Not talking about the website....LOL\n");
        printf("Increasing stack size\n");
        myStack->max += 10;
        myStack->stack = (int *) realloc(myStack->stack, myStack->max * sizeof(int));
    }
    myStack->stack[myStack->top + 1] = data;
    myStack->top++;
}

int pop(struct MyStack *myStack) {
    if (myStack->top == -1) {
        printf("The stack underflow during pop\n");
        return NULL;
    } else {
        myStack->top -= 1;
        return myStack->stack[myStack->top + 1];
    }
}

void display(struct MyStack *myStack) {
    if(myStack->top == -1) {
        return;
    }
    int temp = pop(myStack);
    printf("%d\n", temp);
    display(myStack);
    push(myStack, temp);
}

int main() {
    struct MyStack myStack = buildNewStack();
    int choice;
    printf("Menu :-\n1. Add element\n2. Pop Element\n3. Display the elements in the stack\n4. Exit\n");
    do {
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            push(&myStack, data);
        } else if(choice == 2) {
            int popRes = pop(&myStack);
            if(popRes != NULL) {
                printf("%d\n", popRes);
            }
        } else if(choice == 3) {
            display(&myStack);
        }
    } while (choice != 4);
    return 0;
}