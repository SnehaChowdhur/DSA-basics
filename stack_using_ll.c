// stack_ll.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* link;
} node;

typedef struct linked_list
{
    node* head;
    node* tail;
    int count;
} ll;

typedef struct stack
{
    ll* l;
} stack;

void initList(ll** l);
void insertFirst(ll* l, int data);
node* deleteFirst(ll* l);
void initStack(stack** s);
bool isEmpty(stack* s);
void push(stack* s, int data);
int pop(stack* s);

int main()
{
    stack* st = NULL;
    int choice, d;
    bool pass = true;

    while (pass) {
        printf("\nSTACK OPERATIONS\n1. Create Stack\n2. Check if Empty\n3. Push\n4. Pop\n0. Exit\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initStack(&st);
                printf("Stack created.\n");
                break;
            case 2:
                printf("Stack is %sempty.\n", isEmpty(st) ? "" : "not ");
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &d);
                push(st, d);
                printf("Pushed %d\n", d);
                break;
            case 4:
                d = pop(st);
                if (d != -1) printf("Popped: %d\n", d);
                break;
            case 0:
                pass = false;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void initList(ll** l)
{
    ll* temp = (ll*)calloc(1, sizeof(ll));
    temp->head = temp->tail = NULL;
    temp->count = 0;
    *l = temp;
}

void insertFirst(ll* l, int data)
{
    node* temp = (node*)calloc(1, sizeof(node));
    temp->data = data;
    temp->link = l->head;
    l->head = temp;
    l->count++;
    if (l->count == 1)
        l->tail = l->head;
}

node* deleteFirst(ll* l)
{
    if (l->count == 0) {
        printf("Stack is empty.\n");
        return NULL;
    }
    node* temp = l->head;
    l->head = l->head->link;
    l->count--;
    if (l->count == 0)
        l->tail = NULL;
    return temp;
}

void initStack(stack** s)
{
    stack* temp = (stack*)calloc(1, sizeof(stack));
    initList(&(temp->l));
    *s = temp;
}

bool isEmpty(stack* s)
{
    return s->l->count == 0;
}

void push(stack* s, int data)
{
    insertFirst(s->l, data);
}

int pop(stack* s)
{
    node* temp = deleteFirst(s->l);
    if (temp == NULL) return -1;
    int val = temp->data;
    free(temp);
    return val;
}