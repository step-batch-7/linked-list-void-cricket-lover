#include "linkedlist.h"

void display_int(Element data)
{
  printf("%d ", *(int *)data);
}

void display_list(List_ptr list, DisplayData displayer)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->first;
  while (node_pair.current != NULL)
  {
    (*displayer)(node_pair.current->element);
    node_pair.current = node_pair.current->next;
  }
  printf("total number of nodes are %d\n", list->length);
}

List_ptr create_list()
{
  List_ptr new_list = malloc(sizeof(LinkedList));
  if (new_list == NULL)
  {
    return new_list;
  }
  new_list->first = NULL;
  new_list->last = NULL;
  new_list->length = 0;
  return new_list;
}
