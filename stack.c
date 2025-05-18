/*
Stack implementation
Sneha Chowdhury
241003003092
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack
{
    int* arr;
    int size;
    int top;
}stack;

void init(stack** s,int size);
bool isEmpty(stack* s);
bool isFull(stack* s);
void push(stack* s,int data);
int pop(stack* s);
int peak(stack* s);
void printStack(stack* s);

int main()
{
    stack* s=NULL;
    int size,choice,d;
    bool pass= true;
    printf("\n Enter your choice from below:\n1.Create Stack\n2.Stack underflow check\n3.Stack overflow check\n4.Push into stack\n5.Pop from stack\n6.Peak of stack\n7.Print the stack\n0.Exit\n");
    while (pass)
    {
        printf("\nMy choice is: ");
        scanf("%d",&choice);
        if(choice==0)
        {
            pass=false;
            printf("\nThank you for using me, according to yor request EXITING...\n");
        }
        switch(choice)
        {
             case 1:
                printf("\nEnter the size of the stack: ");
                scanf("%d",&size);
                init(&s,size);
                printf("Congrats! Your stack is successfully created.\n");
                break;
            case 2:
                printf("\nChecking...\n");
                if(isEmpty(s))
                {
                    printf("\nStack is Empty\n");
                }
                else
                {
                    printf("\nStack is not Empty\n");
                }
                break;
            case 3:
                printf("\nChecking...\n");
                if(isFull(s))
                {
                    printf("\nStack is Full\n");
                }
                else
                {
                    printf("Stack is not Full\n");
                }
                break;
            case 4:
                push(s,d);
                printf("Stack Updated !!");
                break;
            case 5:
                printf("\n The deleted value of your stack is: ");
                printf("%d",pop(s));
                break;
            case 6:
                printf("\nThe topmost value is: ");
                printf("%d",peak(s));
                break;
            case 7:
                printf("\nYour data in your stack are: ");
                printStack(s);
                break;
            default:
                printf("Sorry!!Please give valid choices from next time by referring to the list given at the first.");
                break;
        }
    }
}

void init(stack** s,int size)
{
    stack* temp=(stack*)calloc(1,sizeof(stack));
    temp->size=size;
    temp->top=-1;
    temp->arr=(int*)calloc(size,sizeof(int));
    *s=temp;
}
bool isEmpty(stack* s)
{
    return(s->top==-1);
}
bool isFull(stack* s)
{
    return(s->top==(s->size)-1);
}
void push(stack* s,int data)
{
    printf("\nEnter the data for your stack: ");
    scanf("%d",&data);

    if(isFull(s))
    {
        printf("\nStack is Full\n");
    }
    else
    {
        s->arr[++(s->top)]=data;
    }
}
int pop(stack* s)
{
    if(isEmpty(s))
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        return(s->arr[(s->top)--]);
    }
}
int peak(stack* s)
{
    if(isEmpty(s))
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        return(s->arr[(s->top)]);
    }
}
void printStack(stack* s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {
        printf("%d\t",s->arr[i]);
    }
}