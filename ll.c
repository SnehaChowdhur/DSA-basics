include "ll.c"
typedef struct stack
{
    ll* l;
}stack;
void init\_Stack(stack\*\* s);
bool isEmpty(stack\* s);
void push(stack\* s, int data);
int pop(stack\* s);

int main()
{
    l* ml;
    int choice;
    bool pass = true;
    int d, p;
    while(pass)
}
printf("\nEnter your choice from below:\n1.Create a stack\n2.Empty checking\n3.Insert element\n4.Delete the stack\n0.Exit\nMy Choice is: ");
scanf("%d", \&choice);
if(choice == 0)
{
printf("GOODBYE!");
pass = false;
}
else
{
switch(choice)
{
case 1:
initList(\&ml);
printf("Linked List created successfully.");
break;
case 2:
isEmpty(ml);
case 3:
printf("Enter the data: ");
scanf("%d", \&d);
push(ml,d);
printf("Data updated");
case 4:
pop(ml);
printf("Data deleted");
break;
default:
printf("SORRY!! Invalid Choice, Try Again Later.");
break;
}
}
}
return 0;
}

void init_Stack(stack\*\* s)
{
stack* temp=(stack*)calloc(1,sizeof(stack));
initList(&(temp->l));
*s=temp;
}
bool isEmpty(stack* s)
{
return ((s->count)==0);
}
void push(stack* s, int data)
{
insertFirst(s->l,data);
}
int pop(stack\* s)
{
node\* temp=deleteFirst(s->l);
int data=temp->data;
free(temp);
return data;
}
