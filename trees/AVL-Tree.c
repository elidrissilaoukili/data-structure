// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get the height of the tree
int height(struct treeNode *N)
{
    if (N == NULL)
        return 0;
    return 1 + max(height(N->left), height(N->right));
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given data and
     NULL left and right pointers. */
struct treeNode *newNode(int data)
{
    struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // new node is initially added at leaf
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct treeNode *rightRotate(struct treeNode *y)
{
    struct treeNode *x = y->left;
    struct treeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = height(y);
    x->height = height(x);

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct treeNode *leftRotate(struct treeNode *x)
{
    struct treeNode *y = x->right;
    struct treeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = height(x);
    y->height = height(y);

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct treeNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a data in the subtree rooted
// with node and returns the new root of the subtree.
struct treeNode *insert(struct treeNode *node, int data)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = height(node);

    /* 3. Get the balance factor of this ancestor
         node to check whether this node became
         unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct treeNode *root)
{
    if (root != NULL)
    {
        printf("%d -> ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
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

/* Driver program to test above function*/
int main()
{
    struct treeNode *root = NULL;

    /* Constructing tree given in the above figure */
    int value[] = {43, 69, 35, 71, 70};
    for (int i = 0; i < 5; i++)
    {
        root = insert(root, value[i]);
    }
    printtree(root, 0);

    /* The constructed AVL Tree would be
               30
              /  \
            20    40
           /  \	 \
         10   25    50
    */

    // printf("Preorder traversal of the constructed AVL"
    //        " tree is \n");
    // preOrder(root);

    return 0;
}
