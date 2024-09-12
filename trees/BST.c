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

struct treeNode *searchNode(struct treeNode *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

struct treeNode *findMin(struct treeNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct treeNode *findMax(struct treeNode *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct treeNode *deleteNode(struct treeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct treeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct treeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printtabs(int numbtabs)
{
    for (int i = 0; i < numbtabs; i++)
        printf("\t");
}

void printtree(struct treeNode *root, int level)
{
    if (root == NULL)
    {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("value = %d\n", root->data);
    printtabs(level);
    printf("left\n");

    printtree(root->left, level + 1);
    printtabs(level);
    printf("right\n");

    printtree(root->right, level + 1);
    printtabs(level);
    printf("DONE!\n");
}

// Function to print the binary tree in-order traversal
void inOrder(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct treeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct treeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->right);
        postOrder(root->left);
        printf("%d ", root->data);
    }
}

int main()
{
    struct treeNode *root = NULL, *min, *max;

    // Inserting nodes into the tree
    int value[] = {10, 4, 18, 2, 6, 14, 23, 1, 3, 8, 13, 20, 25};
    int length = sizeof(value) / sizeof(value[0]);
    for (int i = 0; i < length; i++)
        root = insertNode(root, value[i]);

    printtree(root, 0);

    // min = findMin(root);
    // printf("\nMin: %d\n", min->data);
    // max = findMax(root);
    // printf("max: %d\n\n", max->data);

    printf("In-order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal:\n");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal:\n");
    postOrderTraversal(root);
    printf("\n");

    // Deleting a node
    root = deleteNode(root, 3);

    printf("In-order Traversal after deleting 3:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
