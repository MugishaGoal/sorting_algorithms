#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker Sort.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current = NULL;
    int swapped = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL) {
            if (current->n > current->next->n) {
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    *list = current->next;
                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                if (current->next != NULL)
                    current->next->prev = current;
                swapped = 1;
                print_list(*list);
            } else {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        current = current->prev;

        while (current->prev != NULL) {
            if (current->n < current->prev->n) {
                if (current->next != NULL)
                    current->next->prev = current->prev;
                current->prev->next = current->next;
                current->next = current->prev;
                current->prev = current->prev->prev;
                current->next->prev = current;
                if (current->prev != NULL)
                    current->prev->next = current;
                else
                    *list = current;
                swapped = 1;
                print_list(*list);
            } else {
                current = current->prev;
            }
        }
    } while (swapped);
}
