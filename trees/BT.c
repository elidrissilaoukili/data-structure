#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

// Queue structure to help in level-order insertion
struct Queue {
    struct treeNode* node;
    struct Queue* next;
};

struct Queue* createQueueNode(struct treeNode* node) {
    struct Queue* newQueueNode = (struct Queue*)malloc(sizeof(struct Queue));
    newQueueNode->node = node;
    newQueueNode->next = NULL;
    return newQueueNode;
}

void enqueue(struct Queue** front, struct Queue** rear, struct treeNode* node) {
    struct Queue* newQueueNode = createQueueNode(node);
    if (*rear == NULL) {
        *front = *rear = newQueueNode;
        return;
    }
    (*rear)->next = newQueueNode;
    *rear = newQueueNode;
}

struct treeNode* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) return NULL;
    struct Queue* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    struct treeNode* node = temp->node;
    free(temp);
    return node;
}

int isQueueEmpty(struct Queue* front) {
    return front == NULL;
}

struct treeNode* createNode(int value) {
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct treeNode* insertNode(struct treeNode* root, int data) {
    struct treeNode* newNode = createNode(data);
    if (root == NULL) return newNode;

    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) {
        struct treeNode* temp = dequeue(&front, &rear);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }

    return root;
}

void inOrderTraversal(struct treeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d -> ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct treeNode* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct treeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d -> ", root->data);
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


int main() {
    struct treeNode *root = NULL;

    // Inserting nodes into the tree
    int value[] = {43, 69, 35, 71, 70};
    for (int i = 0; i < 5; i++)
    {
        root = insertNode(root, value[i]);
    }
    printtree(root, 0);

    // printf("In-order Traversal:\n");
    // inOrderTraversal(root);
    // printf("\n");

    // printf("Pre-order Traversal:\n");
    // preOrderTraversal(root);
    // printf("\n");

    // printf("Post-order Traversal:\n");
    // postOrderTraversal(root);
    // printf("\n");



    return 0;
}
