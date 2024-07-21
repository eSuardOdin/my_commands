#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct
{
    void *next;
    char value;
} CharNode;


void push(CharNode **head, char data);
CharNode *createCharList();
void printList(CharNode *head);
int isElementPresent(char el, CharNode *head);
#endif