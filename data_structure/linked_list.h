// Grayson Pike, 2016
// Linked list of void pointers

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    void *contents;
    struct node *next;
};

struct node *linked_list_create();
void linked_list_add_item(struct node *head, void *item);
struct node *linked_list_get_item(struct node *head, int index);
void linked_list_free_list(struct node *head);

#endif