#include <windef.h>
#include <malloc.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inOrder( struct node* root){

}


struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return(node);
}


int main()
{
    struct node *root = newNode(1);


    root->left        = newNode(2);
    root->right       = newNode(3);

    root->left->left  = newNode(4);
    root->left->right  = newNode(5);
    root->right->right  = newNode(6);
    root->right->right  = newNode(7);
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);

    getchar();
    return 0;
}
