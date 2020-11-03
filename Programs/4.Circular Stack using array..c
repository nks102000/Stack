//Nitish Kumar Sonthalia
//Stack without overflow
#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int max = 10;
int top2;
int *stack;

void push1(int element) {
    if(top1 == top2 - 1) {
        printf("Stack Overflow (Not talking about the website....LOL\n");
    } else {
        stack[top1 + 1] = element;
        top1++;
    }
}

void push2(int element) {
    if(top2 == top1 + 1) {
        printf("Stack Overflow (Not talking about the website....LOL\n");
    } else {
        stack[top2 - 1] = element;
        top2--;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("The stack underflow during pop\n");
        return NULL;
    } else {
        top1 -= 1;
        return stack[top1 + 1];
    }
}

int pop2() {
    if (top2 == max) {
        printf("The stack underflow during pop\n");
        return NULL;
    } else {
        top2 += 1;
        return stack[top2 - 1];
    }
}

void display1() {
    if(top1 == -1) {
        return;
    }
    int temp = pop1();
    printf("%d\n", temp);
    display1();
    push1(temp);
}

void display2() {
    if(top2 == max) {
        return;
    }
    int temp = pop2();
    printf("%d\n", temp);
    display2();
    push2(temp);
}

int main() {
    top2 = max;
    stack = (int *) malloc(max * sizeof(int));
    int choice;
    printf("Menu :-\n1. Add element to Stack 1\n2. Add element to Stack 1\n3. Pop Element from stack 1\n4. Pop Element from stack 2");
    printf("\n5. Display the elements in the stack 1\n6. Display the elements in the stack 2\n7. Exit\n");
    do {
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            push1(data);
        } else if(choice == 2) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            push2(data);
        } else if(choice == 3) {
            int popRes = pop1();
            if(popRes != NULL) {
                printf("%d\n", popRes);
            }
        } else if(choice == 4) {
            int popRes = pop2();
            if(popRes != NULL) {
                printf("%d\n", popRes);
            }
        } else if(choice == 5) {
            display1();
        } else if(choice == 6) {
            display2();
        }
    } while (choice != 7);
    return 0;
}