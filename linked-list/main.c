#include <malloc.h>
#include "stdio.h"

typedef struct {
    void *next;
    int data;
} Node;

Node *head = NULL;

Node *addNode(int data)
{
    Node *new = NULL;

    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;

        new->data = data;
        head = new;
        new->next = NULL;
    } else  {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;

        new->data = data;
        new->next = head;
        head = new;
    }

    return new;
}

int removeNode(int data)
{
    Node *current = head;
    Node *prev = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current == head)
            {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

int insertNode(int afterData, int dataToInsert)
{
    Node *current = head;
    Node *new = malloc(sizeof (Node));
    if (new == NULL)
        return -1;

    new->data = dataToInsert;

    while (current != NULL)
    {
        if (current->data == afterData)
        {
            if (current->next == NULL)
            {
                current->next = new;
                new->next = NULL;
            } else {
                new->next = current->next;
                current->next = new;
            }

            return 1;
        }
        current = current->next;
    }

    return 0;
}

void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
    return;
}

void printMenu()
{
    printf("You have following options:\n");
    printf("\t1. Add node\n");
    printf("\t2. Remove node\n");
    printf("\t3. Insert node\n");
    printf("\t4. Print list\n");
    printf("\t5. Quit\n");
}

int main()
{
    int option = -1;
    while (option != 5)
    {
        printMenu();
        int num_received = scanf("%d", &option);
        if (num_received == 1 && option > 0 && option <= 4)
        {
            int data;
            switch (option) {
                case 1:
                    printf("Input data:");
                    scanf("%d", &data);
                    addNode(data);
                    break;
                case 2:
                    printf("Input data:");
                    scanf("%d", &data);
                    removeNode(data);
                    break;
                case 3:
                    printf("Input after data to insert:");
                    scanf("%d", &data);
                    int dataToInsert;
                    printf("Input data to insert:");
                    scanf("%d", &dataToInsert);
                    insertNode(data, dataToInsert);
                    break;
                case 4:
                    printList();
                    break;
            }
        }
    }
    return 0;
}