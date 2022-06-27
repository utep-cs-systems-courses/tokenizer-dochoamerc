#ifndef _HISTORY_
#define _HISTORY_
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List* histList = (List*) malloc(sizeof(Item)*2);
  histList->root = malloc(sizeof(Item)*1);
  histList->root->id = 1;
  histList->root->next = NULL;
  return histList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  char *copy = copy_str(str, length(str));
  if(list->root->str == 0)
  {
    list->root->str = copy;
    list->root->next = 0;
  } else {
    int id = 2;
    Item* lastNode = list->root;
    while(lastNode->next != NULL)
    {
      id++;
      lastNode = lastNode->next;
    }
    Item* newNode = (Item*) malloc(sizeof(Item)*1);
    newNode->id = id;
    newNode->str = copy;
    newNode->next = NULL;
    lastNode->next = newNode;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item* currentNode = list->root;
  while((currentNode->id) != id)
  {
    if(currentNode->next == NULL) return "No match";
    currentNode = currentNode->next;
  }
  
  return currentNode->str;
}
      
    

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item* currentNode = list->root;

  while(currentNode != NULL)
  {
    printf("ID: %d - '%s'\n", currentNode->id, currentNode->str);
    currentNode = currentNode->next;
  }      
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item* currentNode = list->root;
  Item* next;
  while(currentNode != NULL)
  {
    next = currentNode->next;
    free(currentNode->str);
    free(currentNode);
    currentNode = next;
  }
}
#endif
