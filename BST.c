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
    createNode(100);
    insertNode(&r, 100);
    insertNode(&r, 90);
    insertNode(&r, 80);
    insertNode(&r, 10);
    insertNode(&r, 20);
    insertNode(&r, 50);
    insertNode(&r, 40);
    printf("In-order: ");
    inOrder(r);
    printf("\n");
    printf("Post-order: ");
    postOrder(r);
    printf("\n");
    printf("Pre-order: ");
    preOrder(r);
    printf("\n");
    max(r);
    min(r);
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