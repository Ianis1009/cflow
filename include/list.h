#ifndef LIST_H
#define LIST_H

// usef functions

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* node_create(int value);

void list_push_front (Node **head, int value);
void list_push_back (Node **head, int value);
int list_insert_at (Node **head, size_t index, int value);

Node* list_find (Node* head, int value);

size_t list_length (const Node* head);
Node* list_middle (Node* head);

int list_delete_value (Node** head, int value);
int list_delete_at (Node** head, size_t index);

void list_reverse (Node **head);

void list_print (const Node* head);
void list_free (Node **head);


#endif