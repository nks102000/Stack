//Nitish Kumar Sonthalia
//Stack Global Diclaration
#include<stdio.h>
#include<stdlib.h>
const int max = 50;
int st[max];
int top=-1;

void push(int e){
    if(top==max-1){
        printf("\nOverflow");
        return;
    }
    else{
        (top)++;
        st[(top)]=e;
    }
}


int pop(){
    int n;
    if(top==-1){
        printf("\nOverflow");
        return;
    }
    else{
        n=st[(top)];
        (top)--;
        return(n);
    }
}


void display(){
    if(top!=-1){
        int n=pop();
        printf("%d",n);
        if(top!=-1){
            printf("--");
        }
        display();
        push(n);
    }
}

int main(){
    
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
                push(e);
                //display(stack,top);
                break;
            case 2:
                e=pop();
                printf("\nElement %d has been poped.",e);
                //display(stack,top);
                break;
            case 3:
                printf("\nElement In the stack are:");
                display();
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