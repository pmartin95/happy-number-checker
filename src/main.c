#include <stdio.h>
#include "linked_list.h"

ll_node *number_to_digits(const unsigned int val);
unsigned int square_list(ll_node *list);
int is_happy(const unsigned int val);

int main()
{
    for(unsigned int i = 0; i < 300;i++)
    {
        if(is_happy(i))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

ll_node *number_to_digits(const unsigned int val)
{
    ll_node *digits = NULL;
    unsigned int local_val = val;
    do
    {
        append_linked_list(&digits, local_val % 10);
        local_val /= 10;
    } while (local_val > 0);
    return digits;
}

unsigned int square_list(ll_node *list)
{
    unsigned int total = 0;
    ll_node *tracker = list;
    while (tracker != NULL)
    {
        total += tracker->val * tracker->val;
        tracker = tracker->next;
    }
    return total;
}

int is_happy(const unsigned int val)
{
    if (val == 1)
    {
        return 1;
    }
    ll_node *prev_numbers = NULL;
    append_linked_list(&prev_numbers, val);
    unsigned int number = val;
    unsigned int squared = 0;
    while (squared != 1)
    {
        ll_node *digits = number_to_digits(number);
        squared = square_list(digits);
        number = squared;
        free_linked_list(&digits);
        if (is_in_linked_list(prev_numbers, squared))
        {
            free_linked_list(&prev_numbers);
            return 0;
        }
        append_linked_list(&prev_numbers, squared);
    }

    free_linked_list(&prev_numbers);
    return 1;
}