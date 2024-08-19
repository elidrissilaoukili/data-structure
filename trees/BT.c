#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

// Utility function to create a new tree node
struct treeNode *createNode(int data) {
    struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with given data into the BST
struct treeNode *insert(struct treeNode *node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to find the minimum value node in a given subtree
struct treeNode *minValueNode(struct treeNode *node) {
    struct treeNode *current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with given data from the BST
struct treeNode *delete(struct treeNode *root, int data) {
    // STEP 1: Perform standard BST delete
    if (root == NULL) {
        return root; // Node not found
    }

    // If the data to be deleted is smaller than the root's data, go left
    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    // If the data to be deleted is larger than the root's data, go right
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    // If data matches the root's data, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct treeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct treeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct treeNode *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }

    // Return the (potentially updated) root pointer
    return root;
}

// Function to print the binary tree in-order traversal
void inOrder(struct treeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct treeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct treeNode *root) {
    if (root != NULL) {
        postOrder(root->right);
        postOrder(root->left);
        printf("%d ", root->data);
    }
}

// Main function to test the binary tree operations
int main() {
    struct treeNode *root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the binary tree:\n");
    inOrder(root);
    printf("\n");

    // Delete nodes
    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 50);

    printf("In-order traversal after deletion:\n");
    inOrder(root);
    printf("\n");

    return 0;
}
