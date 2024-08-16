#include "functions.h"

void deleteFromBeginnig()
{
     if (head == NULL)
          printf("List is already empty!\n");
     else
     {
          node *temp = head;
          if ((temp->prev == NULL) && (temp->next == NULL))
          {
               head = NULL;
               free(temp);
          }
          else
          {
               head = temp->next;
               head->prev = NULL;
               free(temp);
          }
          printf("Deleted successful.\n");
     }
}

void deleteFromEnd()
{
     node *temp = head, *temp2;
     if (head == NULL)
          printf("List is already empty!\n");
     if (temp->next == NULL && temp->prev == NULL)
     {
          head = NULL;
          free(temp);
     }
     else
     {
          while (temp->next != NULL)
          {
               temp2 = temp;
               temp = temp->next;
          }
          temp2->next = NULL;
          free(temp);
     }
}

void deleteFromPosition(int pos)
{
     if (head == NULL)
          printf("List is already empty!\n");
     if (pos == 0 || pos == 1)
          deleteFromBeginnig();
     else
     {
          node *temp = head, *temp2;
          for (int i = 0; i < pos - 1; i++)
          {
               temp2 = temp;
               temp = temp->next;
          }
          temp2->next = temp->next;
          free(temp);
     }
}
