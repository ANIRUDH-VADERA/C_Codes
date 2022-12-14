#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *left;
    struct node *right;
};

void preOrder(struct node *root)
{

    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

/* you only have to complete the function given below.
node is defined as

struct node {

    int data;
    struct node *left;
    struct node *right;

};

*/
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
        return root;
    }
    else
    {
        if (root->data > data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                struct node *new_node = malloc(sizeof(struct node));
                new_node->data = data;
                new_node->left = NULL;
                new_node->right = NULL;
                root->left = new_node;
                return root;
            }
            insert(root->left, data);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                struct node *new_node = malloc(sizeof(struct node));
                new_node->data = data;
                new_node->left = NULL;
                new_node->right = NULL;
                root->right = new_node;
                return root;
            }
            insert(root->right, data);
        }
    }
    return root;
}

int main()
{

    struct node *root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    preOrder(root);
    return 0;
}
