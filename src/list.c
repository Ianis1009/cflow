#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* node_create (int value) {

    Node* node = malloc(sizeof(*node));

    if (node == NULL) {
        return NULL;
    }

    node->data = value;
    node ->next = NULL;
    return node;
}

void list_push_front (Node** head, int value) {
    
    if (head == NULL) {
        return;
    }

    Node* node = node_create(value);
    
    if (node == NULL) {
        return;
    }
    node ->next = *head;
    *head = node;
}

void list_push_back (Node** head, int value) {
    if (head == NULL) {
        return;
    }

    Node* node = node_create(value);

    if (node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = node;
        return;
    }

    Node* current = *head;

    while (current ->next != NULL) {
        current = current ->next;
    }
    current ->next = node;
}

Node* list_find (Node* head, int value) {

    Node* current = head;

    while (current != NULL) {
        if (current ->data == value) {
            return current;
        }

        current = current ->next;
    }

    return NULL;
}

size_t list_length(const Node *head) {
    size_t length = 0; 
    const Node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

int list_insert_at (Node** head, size_t index, int value) {

    if (head == NULL) {
        return 0;
    }

    if (index == 0) {
        Node* node = node_create(value);

        if (node == NULL) {
            return 0;
        }

        node ->next = *head;
        *head = node;
        return 1;
    }

    Node* current = *head;

    for (size_t i = 0; i < index -1; i++ ) {
        if (current == NULL) {
            return 0;
        }

        current = current ->next;
    }

    if (current == NULL) {
        return 0;
    }

    Node* node = node_create(value);

    if (node == NULL) {
        return 0;
    }

    node ->next = current ->next;
    current ->next = node;
    return 1;
}

int list_delete_value (Node **head, int value) {

    if (head == NULL || *head == NULL ) {
        return 0;
    }

    Node* current = *head;
    if (current->data == value) {
        *head = current ->next;
        free(current);

        return 1;
    }

    while (current ->next != NULL ) {

        if (current ->next->data == value) {
            Node* to_delete = current->next;
            current ->next = to_delete ->next;
            free(to_delete);
            return 1;
        }

        current = current ->next;
    }

    return 0; 
}

int list_delete_at (Node** head, size_t index ) {

    //TODO
}

void list_reverse (Node **head) {
    //TODO
}

Node* list_middle (Node *head) {
    //TODO
}

void list_print (const Node *head) {
    //TODO
}

void list_free (Node **head) {

    //TODO
}
