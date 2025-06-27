#include <stdlib.h>
#include <stdio.h>

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

typedef struct ll_node
{
    unsigned int val;
    struct ll_node *next;
} ll_node;

void append_linked_list(ll_node **list, unsigned int val);
int is_in_linked_list(ll_node *list, unsigned int val);
void free_linked_list(ll_node **list);
void print_linked_list(ll_node *list);
#endif