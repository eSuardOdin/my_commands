#include <stdio.h>
#include <string.h>
#include "../errors/errors.h"
#include "../ds/linked_list.h"
#include "options.h"


void processOption(char *option, CharNode *head)
{
    int len = strlen(option);
    int checked;
    for(int i = 1; i < len; i++)
    {
        checked = *(option + i);
        // Check if char is valid
        if(isOptionValid(checked))
        {
            // Check if already in options list
            if(!isElementPresent(checked, head))
            {
                push(&head, checked);
            }
        }
    }
    printList(head);
}
/**
 * @brief Checks if an option is valid
 * 
 * @param option The option string to check
 * @return int 0 = Not valid | 1 = Valid
 */
int isOptionValid(char c)
{
    const int ASCII_MIN = 97;
    const int ASCII_MAX = 122;
    
        // printf("Checking %c -> %d\n", checked, checked);
    if(c < ASCII_MIN || c > ASCII_MAX)
    {
        char err[1024];
        printf("WARNING : \"%c\" is not a valid option (only alpa characters allowed)\n", c);
        return 0;
    }    
    return 1;
}
