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
            switch (option) {
                case 1:
                    printf("Input data:");
                    scanf("%d", &option);
                    addNode(option);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    printList();
                    break;
                case 5:
                    break;
            }
        }
    }
    return 0;
}