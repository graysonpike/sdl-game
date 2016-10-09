// Grayson Pike, 2016

#include <stdlib.h>
#include "linked_list.h"

struct node *get_last(struct node *head) {
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}

// Creates head node for a new list. Contents of the first
// node are left NULL, then filled by the first call of add_node()
struct node *linked_list_create() {
    struct node *n = malloc(sizeof(struct node));
    n->contents = NULL;
    n->next = NULL;
    return n;
}

void linked_list_add_item(struct node *head, void *item) {
    if(head->contents == NULL) {
        // Head is empty, no need to create another node
        head->contents = item;
    } else {
        // Create new node and add it to the list
        struct node *new = malloc(sizeof(struct node));
        new->contents = item;
        new->next = NULL;
        get_last(head)->next = new;
    }
}

struct node *linked_list_get_item(struct node *head, int index) {
    for(int i = 0; i < index; i++) {
        head = head->next;
    };
    return head->contents;
}

void linked_list_free_list(struct node *head) {
    struct node *tmp;
    while(head != NULL) {
        tmp = head;
        head = head->next;
        if(tmp->contents != NULL) {
            free(tmp->contents);
        }
        free(tmp);
    }
}