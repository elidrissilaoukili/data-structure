#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // insert at beginning
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList()
{
    printf("\n This is the list: \n");
    struct Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->", temp->data);
}

void insertAtPos(int value, int pos)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp;
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteBeginning()
{
    if (head == NULL)
        printf("List is empty\n");
    else
    {
        struct Node *temp;
        temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
        }
    }
}

void deleteEnd()
{
    if (head == NULL)
        printf("list is empty\n");
    else
    {
        struct Node *temp1, *temp2;
        temp1 = head;
        if (temp1->next == NULL)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL;
            free(temp1);
        }
    }
}

void deleteFromPos(int pos)
{
     int i, flag = 0;
     if (head == NULL)
          printf("List is already empty!\n");
     if (pos == 0 || pos == 1)
          deleteBeginning();
     else
     {
          struct Node *temp = head, *temp2;
          for (i = 0; i < pos - 1; i++)
          {
               temp2 = temp;
               temp = temp->next;
          }
          temp2->next = temp->next;
          free(temp);
     }
}

int main()
{

    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAtBeginning(5);
    displayList();

    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtEnd(9);
    insertAtEnd(10);
    displayList();

    insertAtPos(99, 5);
    displayList();

    deleteBeginning();
    displayList();
    deleteEnd();
    displayList();
    deleteFromPos(4);
    displayList();
}