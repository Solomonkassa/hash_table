#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

void print_list(node *head)
{
    node *tmp = head;
    while(tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

void add_node(node **head, int n)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = n;
    new_node->next = *head;
    *head = new_node;
}
node* search_list(node* head, int n)
{
    node* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == n)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void add_node_at_end(node** head, int n)
{
    node* new_node = malloc(sizeof(node));
    new_node->data = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    node* tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}

void add_node_in_middle(node* head, int pos, int n)
{
    node* new_node = malloc(sizeof(node));
    new_node->data = n;

    node* tmp = head;
    int i = 1;
    while (tmp != NULL && i < pos - 1)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
    {
        printf("Position not found in the list\n");
        return;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
}

void reverse_list(node** head)
{
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
int main()
{
    int d;
    while (1)
    {
        printf("Please enter any number (or -1 to stop): ");
        scanf("%d", &d);
        
        if (d == -1)
            break;

        add_node(&head, d);
    }

    printf("Original List:\n");
    print_list(head);

    printf("\nSearching the list for value 5:\n");
    node* searched_node = search_list(head, 5);
    if (searched_node != NULL)
        printf("Node found with value %d\n", searched_node->data);
    else
        printf("Node not found\n");

    printf("\nAdding a new node with value 10 at the end:\n");
    add_node_at_end(&head, 10);
    print_list(head);

    printf("\nAdding a new node with value 20 at position 3:\n");
    add_node_in_middle(head, 3, 20);
    print_list(head);

    printf("\nReversing the list:\n");
    reverse_list(&head);
    print_list(head);

    return 0;
}
