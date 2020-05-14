#include "linkedlist.h"

void display_int(Element data)
{
  printf("value is %d\n", *(int *)data);
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

Node_ptr create_node(Element value, Node_ptr next_reference)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return new_node;
  }
  new_node->element = value;
  new_node->next = next_reference;
  return new_node;
}

Status add_to_start(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value, list->first);
  if (new_node == NULL)
  {
    return Failure;
  }
  if (list->first == NULL)
  {
    list->last = new_node;
  }

  list->first = new_node;
  list->length++;
  return Success;
}

Status add_to_list(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value, NULL);
  if (new_node == NULL)
  {
    return Failure;
  }
  if (list->first == NULL)
  {
    list->first = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)

{
  if (position > list->length || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }
  if (position == list->length)
  {
    return add_to_list(list, element);
  }

  Prev_Current_Pair node_pair;
  node_pair.current = list->first;
  for (int i = 1; i < position; i++)
  {
    if (node_pair.current->next != NULL)
    {
      node_pair.current = node_pair.current->next;
    }
  }

  Node_ptr new_node = create_node(element, node_pair.current->next);
  if (new_node == NULL)
  {
    return Failure;
  }
  node_pair.current->next = new_node;
  list->length++;
  return Success;
}

Status clear_list(List_ptr list)
{
  Prev_Current_Pair pair;
  if (list->length == 0)
  {
    return Failure;
  }
  pair.prev = list->first;
  while (pair.prev != NULL)
  {
    pair.current = pair.prev->next;
    free(pair.prev);
    pair.prev = pair.current;
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
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
