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
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// A utility function to get the height of the tree
int height(struct treeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

/* Helper function that allocates a new node with the given data and
    NULL left and right pointers. */
struct treeNode *createNode(int data)
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
struct treeNode *rightRotate(struct treeNode *node)
{

    // Ensure the node and its left child are valid
    if (node == NULL || node->left == NULL) {
        return node; // Cannot perform rotation
    }

    // perform rotation
    struct treeNode *left = node->left;
    struct treeNode *right = left->right;

    // Perform rotation
    left->right = node;
    node->left = right;

    // Update heights
    node->height = height(node);
    left->height = height(left);

    // Return new root
    return left;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct treeNode *leftRotate(struct treeNode *node)
{
    struct treeNode *right = node->right;
    struct treeNode *left = right->left;

    // Perform rotation
    right->left = node;
    node->right = left;

    // Update heights
    node->height = height(node);
    right->height = height(right);

    // Return new root
    return right;
}

// Get Balance factor of node N
int getBalance(struct treeNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Recursive function to insert a data in the subtree rooted
// with node and returns the new root of the subtree.
struct treeNode *insert(struct treeNode *node, int data)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (createNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;

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


// Function to find the node with the minimum value greater than the given node
struct treeNode *minValueNode(struct treeNode *node) {
    struct treeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with given data from the subtree rooted with node
struct treeNode *delete(struct treeNode *node, int data)
{
    // STEP 1: Perform standard BST delete
    if (node == NULL) {
        return node; // Node not found
    }

    // If the data to be deleted is smaller than the node's data, go left
    if (data < node->data) {
        node->left = delete(node->left, data);
    }
    // If the data to be deleted is larger than the node's data, go right
    else if (data > node->data) {
        node->right = delete(node->right, data);
    }
    // If data matches the node's data, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (node->left == NULL) {
            struct treeNode *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct treeNode *temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct treeNode *temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = delete(node->right, temp->data);
    }

    // STEP 2: Update the height of the current node
    node->height = height(node);

    // STEP 3: Get the balance factor of this node
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (potentially updated) node pointer
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

    // delete(root, 71);
    // printtree(root, 0);
    return 0;
}
