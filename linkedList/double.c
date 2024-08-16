#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL;

void sizeoflist()
{
    int count = 0;
    struct Node *temp = head;
    if (head == NULL)
        printf("List contains 0 node.\n");
    else
    {
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("\nsize of this list is : %d\n", count);
    }
}

void displayList()
{

    if (head == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d->", temp->data);
    }
    printf("\n");
}

void insertAtBeginning(int value)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

struct Node *createNode(int value, struct Node *newnode)
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void insertAtEnd(int value)
{
    struct Node *newnode, *temp;
    newnode = createNode(value, newnode);

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtPos(int value, int pos)
{
    struct Node *newnode, *temp1, *temp2;
    newnode = createNode(value, newnode);
    if (head == NULL)
        insertAtBeginning(value);
    else
    {
        temp1 = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        newnode->next = temp1->next;
        temp1->prev = newnode;
        newnode->prev = temp1;
        temp1->next = newnode;
    }
}

void deleteBeginning()
{
    if (head == NULL)
        printf("list is empty!\n");
    else
    {
        struct Node *temp = head;
        head->next->prev = NULL;
        head = head->next;
        free(temp);
    }
}

void deletEnd()
{
    if (head == NULL)
        printf("list is empty!\n");
    else
    {
        struct Node *temp1 = head, *temp2;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}

void deletePos(int pos)
{
    if (head == NULL)
        printf("List is empty!\n");
    if (pos == 0)
        deleteBeginning();    
    else
    {
        struct Node *temp1 = head, *temp2;
        for (int i = 0; i < pos - 1; i++)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        temp1->next->prev = temp1;
        free(temp1); 
    }
}

int main()
{
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    // displayList();
    // sizeoflist();

    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    // displayList();

    insertAtPos(99, 3);
    displayList();
    deleteBeginning();
    displayList();
    deletEnd();
    displayList();
    deletePos(2);
    displayList();
}