/*
Singly linked list - Menu driven
Sneha Chowdhury
241003003092
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

typedef struct linked_list {
    node* head;
    node* tail;
    int count;
} ll;

// Function declarations
void initList(ll** l);
void insertFirst(ll* l, int data);
void insertLast(ll* l, int data);
node* deleteFirst(ll* l);
node* deleteLast(ll* l);
void printList(ll* l);

int main() {
    ll* ml = NULL;
    int choice, data;
    bool running = true;

    while (running) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Print list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (ml == NULL) {
                    initList(&ml);
                    printf("Linked list created successfully.\n");
                } else {
                    printf("List already created.\n");
                }
                break;

            case 2:
                if (ml == NULL) {
                    printf("Create the list first.\n");
                } else {
                    printf("Enter data to insert at beginning: ");
                    scanf("%d", &data);
                    insertFirst(ml, data);
                }
                break;

            case 3:
                if (ml == NULL) {
                    printf("Create the list first.\n");
                } else {
                    printf("Enter data to insert at end: ");
                    scanf("%d", &data);
                    insertLast(ml, data);
                }
                break;

            case 4:
                if (ml == NULL) {
                    printf("Create the list first.\n");
                } else {
                    deleteFirst(ml);
                }
                break;

            case 5:
                if (ml == NULL) {
                    printf("Create the list first.\n");
                } else {
                    deleteLast(ml);
                }
                break;

            case 6:
                if (ml == NULL) {
                    printf("Create the list first.\n");
                } else {
                    printList(ml);
                }
                break;

            case 0:
                running = false;
                printf("Thank you! Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initList(ll** l) {
    *l = (ll*)calloc(1, sizeof(ll));
    (*l)->head = NULL;
    (*l)->tail = NULL;
    (*l)->count = 0;
}

void insertFirst(ll* l, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = l->head;

    l->head = temp;

    if (l->count == 0) {
        l->tail = temp;
    }

    l->count++;
    printf("Inserted %d at beginning.\n", data);
}

void insertLast(ll* l, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (l->count == 0) {
        l->head = l->tail = temp;
    } else {
        l->tail->next = temp;
        l->tail = temp;
    }

    l->count++;
    printf("Inserted %d at end.\n", data);
}

node* deleteFirst(ll* l) {
    if (l->count == 0) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    node* temp = l->head;
    l->head = l->head->next;
    l->count--;

    if (l->count == 0) {
        l->tail = NULL;
    }

    printf("Deleted from beginning: %d\n", temp->data);
    free(temp);
    return NULL;
}

node* deleteLast(ll* l) {
    if (l->count == 0) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (l->count == 1) {
        return deleteFirst(l);
    }

    node* temp = l->head;
    while (temp->next != l->tail) {
        temp = temp->next;
    }

    printf("Deleted from end: %d\n", l->tail->data);
    free(l->tail);
    l->tail = temp;
    l->tail->next = NULL;
    l->count--;

    return NULL;
}

void printList(ll* l) {
    node* temp = l->head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
