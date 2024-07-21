#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/**
 * @brief Create a char List head as NULL and return it
 * 
 * @return CharNode* (list's head)
 */
CharNode *createCharList()
{
    CharNode *head = NULL;
    return head;
}
void push(CharNode **head, char data)
{
    CharNode *new = malloc(sizeof(CharNode));
    new->next = *head;
    new->value = data;
    *head = new;
    
    /*
    // Debug
    printf("Added %c to the list\n", data);
    */
}

/**
 * @brief Check if an element is present in list
 * 
 * @param el Element to find in list
 * @param head Pointer to the head of list
 * @return 0 = Absent / 1 = Present
 */
int isElementPresent(char el, CharNode *head)
{
    // Copy head in order not to modifiy what it points to
    CharNode *iterator = head;
    CharNode *temp = NULL;
    // Iterate through list
    while(iterator != NULL)
    {
        // printf("Checking %c against %c\n", el, iterator->value);
        if(el == iterator->value)
        {
            // puts("found");
            return 1;
        }
        temp = iterator->next;
        iterator = temp;
    }
    // puts("not found");
    return 0;
}
/**
 * @brief Prints list and give addresses info
 * 
 * @param head Pointer to the head of list
 */
void printList(CharNode *head)
{
    while (head != NULL)
    {
        printf("Head is on adress %p\n", head);
        printf("Head has value '%c'\n", head->value);
        CharNode *temp = head->next;
        head = temp;
    }
    
}
