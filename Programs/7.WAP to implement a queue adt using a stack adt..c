//1905622
//Nitish Kumar Sonthalia

//WAP to implement a queue adt using a stack adt


#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **st,int n){
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->next=*st;
    *st=new1;
}

int pop(struct node **st){
    struct node *temp=*st;
    if(*st==NULL){
        printf("Underflow");
    }
    else{
        int b=temp->data;
        *st=temp->next;
        free(temp);
        return(b);
    }
}

void enqueue(struct node **st, int data){
    struct node *top=NULL;
    while((*st)!=NULL){
        int t= pop(st);
        push(&top,t);
    }

    push(st,data);

    while(top!=NULL){
        int t= pop(&top);
        push(st,t);
    }
}
int dequeue(struct node **st){
    int t=pop(st);
    return t;
}
void Display(struct node **st){
    if(*st==NULL){
        return;
    }
    int b=pop(st);
    printf("%d",b);
    if((*st)!=NULL){
        printf("--");
    }
    Display(st);
    push(st,b);
}

int main(){
    struct node *top=NULL;
    int choice;
    printf("1. Insert element to Queue \n");
    printf("2. Delete element from Queue \n");
    printf("3. Display all elements of Queue \n");
    printf("4. Quit \n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            enqueue(&top,data);
        } else if(choice == 2) {
            int data = dequeue(&top);
            if(data != NULL) {
                printf("Deleted data : %d\n", data);
            }
        } else if(choice == 3) {
            Display(&top);
            printf("\n");
        } else {
            exit(0);
        }
    }
    return 0;
}