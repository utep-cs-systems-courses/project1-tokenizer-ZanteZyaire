#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Allocates a linked-list-data-struct. */
List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

/* Traverses the linked-list then
   allocates space for the next node. */
void add_history(List *list, char *str)
{
  Item *node = list->root;
  int count = 1;
  
  while (node->next) {
    node = node->next;
    count++;
  }

  node->id   = count;
  node->str  = copy_str(str, string_length(str));
  node->next = malloc(sizeof(Item));
}

/* Searches linked list for matching id then
   returns the nodes corresponding string. */
char *get_history(List *list, int id)
{
  Item *node = list->root;
  
  while (node->id != id)
    node = node->next;

  return node->str;
}

/* Prints the id and string of each node in 
   order of them added to the linked list. */
void print_history(List *list)
{
  Item *node = list->root;

  int i = 0;
  do {
    printf("ID %d: %s\n", i, node->str);
    i++;
    node = node->next;
  } while(node->str);
}

/* Frees memory of individual nodes then
   frees the linked list itself. */
void free_history(List *list)
{
  Item *node = list->root;
  
  while (node) {
    Item *next = node->next;
    free(node);
    node = next;
  }
  
  free(list);
}

