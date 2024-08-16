#include "functions.h"

void insertAtBeginnig(int value)
{
     node *newNode;
     newNode = createNode(newNode, value);
     if (head == NULL)
          head = newNode;
     else
     {
          newNode->next = head;
          head->prev = newNode;
          head = newNode;
     }
}

void insertAtEnd(int value)
{
     node *newNode;
     newNode = createNode(newNode, value);
     if (head == NULL)
          head = newNode;
     else
     {
          node *temp = head;
          while (temp->next != NULL)
               temp = temp->next;
          newNode->prev = temp->next;
          temp->next = newNode;
     }
}

void insertAtPosition(int value, int pos)
{
     int flag = 1, i;
     node *newNode, *temp = head;
     newNode = createNode(newNode, value);
     if (head == NULL)
          head = newNode;
     else
     {
          if (pos == 0)
               insertAtBeginnig(value);
          else
          {
               for (i = 1; i < pos - 1; i++)
               {
                    temp = temp->next;
                    if (temp->next == NULL)
                    {
                         flag = 0;
                         break;
                    }
               }
               if (flag)
               {
                    newNode->next = temp->next;
                    newNode->prev = temp;
                    temp->next->prev = newNode;
                    temp->next = newNode;
               }
          }
     }
}
