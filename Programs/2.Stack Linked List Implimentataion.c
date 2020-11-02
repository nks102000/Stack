//Nitish Kumar Sonthalia
//Stack Linked List Implimentataion
#include<stdio.h>
#include<stdlib.h>

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

void Display_rev(struct node **st){
    if(*st==NULL){
        return;
    }
    int b=pop(st);
        printf("%d",b);
        if((*st)!=NULL){
            printf("--");
        }
        Display_rev(st);
        push(st,b);
}

int main(){
    struct node *top=NULL;
    int f=1;
    while(f){
        printf("\n-------------------------------------------------------------");
        printf("\nMenu:");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        int o,e;
        scanf("%d",&o);
        switch(o){
            case 1:
                printf("\nEnter the value to be pushed:");
                scanf("%d",&e);
                push(&top,e);
                break;
            case 2:
                e=pop(&top);
                printf("\nElement %d has been poped.",e);
                break;
            case 3:
                printf("\nElement In the stack are:");
                Display_rev(&top);
                break;
            case 4:
                f=0;
                break;
            default:
                break;
        }
    }
    return 0;
}