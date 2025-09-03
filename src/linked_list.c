#include "linked_list.h"
void append_linked_list(ll_node **list, unsigned int val)
{

    if (*list == NULL)
    {
        *list = (ll_node *)malloc(sizeof(ll_node));
        if (*list == NULL)
        {
            return;
        }
        ll_node *local_list = *list;
        local_list->next = NULL;
        local_list->val = val;
        return;
    }
    ll_node *local_list = *list;
    while (local_list->next != NULL)
    {
        local_list = local_list->next;
    }
    local_list->next = (ll_node *)malloc(sizeof(ll_node));
    if (local_list->next == NULL)
    {
        return;
    }
    local_list = local_list->next;
    local_list->next = NULL;
    local_list->val = val;
}

int is_in_linked_list(const ll_node *list, unsigned int val)
{
    if (list == NULL)
    {
        return 0;
    }
    const ll_node *tracker = list;

    while (tracker != NULL)
    {
        if (tracker->val == val)
        {
            return 1;
        }
        tracker = tracker->next;
    }
    return 0;
}

void free_linked_list(ll_node **list)
{
    ll_node *tracker = *list, *prev;

    while (tracker != NULL)
    {
        prev = tracker;
        tracker = tracker->next;
        free(prev);
    }
    *list = NULL;
}

void print_linked_list(const ll_node *list)
{
    const ll_node *tracker = list;
    while (tracker != NULL)
    {
        printf("%d ", tracker->val);
        tracker = tracker->next;
    }
    printf("\n");
}