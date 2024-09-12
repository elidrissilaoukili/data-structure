#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(int value)
{
    struct treeNode *newNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d -> ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct treeNode *root)
{
    if (root != NULL)
    {
        printf("%d -> ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct treeNode *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d -> ", root->data);
    }
}

struct treeNode *insertNode(struct treeNode *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int somme(struct treeNode *arb)
{
    if (arb == NULL)
        return 0;
    else
        return arb->data + somme(arb->left) + somme(arb->right);
}

int main()
{
    struct treeNode *root = NULL, *min, *max;

    // Inserting nodes into the tree
    int value[] = {10, 4, 18, 2, 6, 14, 23, 1, 3, 8, 13, 20, 25};
    int length = sizeof(value) / sizeof(value[0]);
    for (int i = 0; i < length; i++)
        root = insertNode(root, value[i]);
    


    printf("In-order Traversal after deleting 3:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("%d", somme(root));

    return 0;
}
