/*
Double linked list
Sneha Chowdhury
241003003092
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
}node;


typedef struct linked_list
{
	node* head;
	node* tail;
	int count;
}ll;

void initList(ll** l);
void insertFirst(ll* l,int data);
void insertLast(ll* l,int data);
void insertAt(ll* l,int data, int pos);
node* deleteFirst(ll* l);
node* deleteLast(ll* l);
node* deleteAt(ll* l, int pos);
void printList(ll* l);
void printListReverse(ll* l);

int main()
{
	ll* ml=NULL;
	int choice;
	bool pass=true;
	int d,p;
	while (pass)
	{
		printf("\nEnter your choice from below:\n1.Create a linked list\n2.Insert element at first\n3.Insert element at last\n4.Insert element at given position\n5.Delete element at first\n6.Delete element at last\n7.Delete element at given position\n8.Print the linked list from first\n9.Print the linked list from last\n0.Exit\nMy choice is: ");
		scanf("%d",&choice);
        switch (choice)
		{
			case 1:
                initList(&ml);
				printf("Linked list created successfully.");
				break;
			case 2:
				printf("\nEnter the data: ");
				scanf("%d",&d);
				insertFirst(ml,d);
				printf("Data updated.\n");
				break;
			case 3:
                printf("Enter the data: ");
			    scanf("%d",&d);
				insertLast(ml,d);
				printf("Data updated.");
				break;
			case 4:
				printf("Enter the data: ");
			    scanf("%d",&d);
				printf("Enter the position: ");
			    scanf("%d",&p);
				insertAt(ml,d,p);
				printf("Data updated.");
				break;
			case 5:
				deleteFirst(ml);
				printf("Data updated.");
				break;
			case 6:
				deleteLast(ml);
                printf("Data updated.");
				break;
			case 7:
				printf("Enter the position: ");
			    scanf("%d",&p);
				deleteAt(ml,p);
				printf("Data updated.");
				break;
			case 8:
				printList(ml);
				break;
            case 9:
				printListReverse(ml);
				break;
			case 0:
				pass=false;
				break;
			default:
				printf("Sorry!!Please give valid choices from next time by referring to the list given at the first.");
				    break;
		}
	}
	return 0;
}

void initList(ll** l)
{
	ll* temp=(ll*)calloc(1,sizeof(ll));
	temp->head=NULL;
	temp->tail=NULL;
	temp->count=0;
	*l=temp;
}
void insertFirst(ll* l,int data)
{
	node* temp=(node*)calloc(1,sizeof(node));
	temp->data=data;
	temp->next=l->head;
	temp->prev=NULL;
	if(l->head==NULL)
	{
		l->head=l->tail=temp;
		
	}
	else
	{
		l->head->prev=temp;
	}
    l->head=temp;
	l->count++;
}
void insertLast(ll* l,int data)
{
	if(l->count==0)
	{
		insertFirst(l,data);
	}
	else
	{
		node* temp=(node*)calloc(1,sizeof(node));
		temp->data=data;
		temp->next=NULL;
		temp->prev=l->tail;
		l->tail->next=temp;
		l->tail=temp;
		
		l->count++;
	}
}
void insertAt(ll* l,int data, int pos)
{
	if(pos==1)
	{
		insertFirst(l,data);
	}
	else if(pos==l->count+1)
	{
		insertLast(l,data);
	}
	else if(pos>1 && pos<l->count)
	{
		node* temp=l->head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
			//printf("%d",temp->data);
		}
		
		node* temp1=(node*)calloc(1,sizeof(node));
		temp1->data=data;
		temp1->next=temp->next;
		temp1->prev=temp;
		if(temp->next!=NULL)
		{
			temp->next->prev=temp1;
		}
		temp->next=temp1;
		l->count++;
	}
}
node* deleteFirst(ll* l)
{
	if(l->count==0)
	{
		printf("List is empty cannot delete.");
		return NULL;
	}
	else
	{
		node* temp=l->head;
        node* temp1=l->head->next;
        temp1->prev=NULL;
        l->head=temp1;
        int v=temp->data;
        free (temp);
		l->count--;
		if(l->count==0)
		{
			l->tail=NULL;
		}
        else
        {
            printf("The deleted value is: %d\n",v);
		    return NULL;
        }
	}
}
node* deleteLast(ll* l)
{
	if(l->count==0)
	{
		printf("List is empty cannot delete.");
		return NULL;
	}
	else if(l->count==1)
	{
		return deleteFirst(l);
	}
	else
	{
		node* temp=l->tail;
        node* temp1=l->tail->prev;
        temp1->next=NULL;
        l->tail=temp1;
        int v=temp->data;
        free (temp);
		l->count--;
		if(l->count==0)
		{
			l->tail=NULL;
		}
        else
        {
            printf("The deleted value is: %d\n",v);
		    return NULL;
        }
	}
}
node* deleteAt(ll* l, int pos)
{
    if(pos == 1)
    {
        return deleteFirst(l);
    }
    else if(pos == l->count)
    {
        return deleteLast(l);
    }
    else if(pos > 1 && pos < l->count)
    {
        node* temp = l->head;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        int v = temp->data;
        free(temp);

        printf("The deleted value is: %d\n", v);
        l->count--;

        return NULL;
    }
    else
    {
        printf("Invalid position!\n");
        return NULL;
    }
}
void printList(ll* l)
{
	node* temp=l->head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void printListReverse(ll* l)
{
	node* temp=l->tail;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
}