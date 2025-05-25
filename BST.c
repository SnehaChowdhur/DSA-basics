#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* right;
    struct node* left;
}node;

node* createNode(int data);
void insertNode(node** root, int data);
void inOrder(node* root);
void postOrder(node* root);
void preOrder(node* root);
void max(node* root);
void min(node* root);

int main()
{
    //
    node* r=NULL;
    int choice, d;
    while(1)
    {
        printf("\n---BST MENU---\n1.Node insertion\n2.In-Order Arrangement\n3.Post-Order Arrangement\n4.Pre-Order Arrangement\n5.Maximum value\n6.Minimum value\n0.Exit\nMy choice is: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&d);
                insertNode(&r,d);
                printf("Node is successfully created.\n");
                break;
            case 2:
                printf("In-order: ");
                inOrder(r);
                printf("\n");
                break;
            case 3:
                printf("Post-order: ");
                postOrder(r);
                printf("\n");
                break;
            case 4:
                printf("Pre-order: ");
                preOrder(r);
                printf("\n");
                break;
            case 5:
                max(r);
                break;
            case 6:
                min(r);
                break;
            case 0:
                printf("GOOD BYEEE!!");
                return 0;
                break;
            default:
                printf("Sorry!Wrong Choice, Try again Later!!");
                break;
        }
    }
    return 0;
}

node* createNode(int data)
{
    //
    node* temp=(node*)calloc(1,sizeof(node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void insertNode(node** root, int data)
{
    //
    node* new_node=createNode(data);
    if(*root==NULL)
    {
        *root=new_node;
    }
    else
    {
        node* temp=*root;
        while(true)
        {
            if(temp->data>data)
            {
                if(temp->left==NULL)
                {
                    temp->left=new_node;
                    break;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=new_node;
                    break;
                }
                temp=temp->right;
            }
        }
    }
}

void inOrder(node* root)
{
    //
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}

void postOrder(node* root)
{
    //
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
}

void preOrder(node* root)
{
    //
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void max(node* root)
{
    node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    printf("MAXIMUM VALUE: %d\t",temp->data);
}
void min(node* root)
{
    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    printf("MINIMUM VALUE: %d",temp->data);
}
