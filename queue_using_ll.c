// queue_ll.c
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

typedef struct queue
{
    ll* l;
} queue;

void initList(ll** l);
void insertLast(ll* l, int data);
void initQueue(queue** q);
bool isEmptyq(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);

int main()
{
    queue* qu = NULL;
    int choice, d;
    bool pass = true;

    while (pass) {
        printf("\nQUEUE OPERATIONS\n1. Create Queue\n2. Check if Empty\n3. Enqueue\n4. Dequeue\n0. Exit\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initQueue(&qu);
                printf("Queue created.\n");
                break;
            case 2:
                printf("Queue is %sempty.\n", isEmptyq(qu) ? "" : "not ");
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &d);
                enqueue(qu, d);
                printf("Enqueued %d\n", d);
                break;
            case 4:
                d = dequeue(qu);
                if (d != -1) printf("Dequeued: %d\n", d);
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

void insertLast(ll* l, int data)
{
    node* temp = (node*)calloc(1, sizeof(node));
    temp->data = data;
    temp->link = NULL;
    if (l->count == 0) {
        l->head = l->tail = temp;
    } else {
        l->tail->link = temp;
        l->tail = temp;
    }
    l->count++;
}

node* deleteFirst(ll* l)
{
    if (l->count == 0) {
        printf("Queue is empty.\n");
        return NULL;
    }
    node* temp = l->head;
    l->head = l->head->link;
    l->count--;
    if (l->count == 0)
        l->tail = NULL;
    return temp;
}

void initQueue(queue** q)
{
    queue* temp = (queue*)calloc(1, sizeof(queue));
    initList(&(temp->l));
    *q = temp;
}

bool isEmptyq(queue* q)
{
    return q->l->count == 0;
}

void enqueue(queue* q, int data)
{
    insertLast(q->l, data);
}

int dequeue(queue* q)
{
    node* temp = deleteFirst(q->l);
    if (temp == NULL) return -1;
    int val = temp->data;
    free(temp);
    return val;
}
