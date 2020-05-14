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
  printf("total number of nodes are %d\n\n", list->length);
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

List_ptr reverse(List_ptr list)
{
  List_ptr new_list = create_list();
  Prev_Current_Pair pair;
  pair.prev = list->first;
  while (pair.prev != NULL)
  {
    pair.current = pair.prev->next;
    add_to_start(new_list, pair.prev->element);
    pair.prev = pair.current;
  }
  return new_list;
}

Element remove_from_start(List_ptr list) // Returns Element which was removed
{
  if (list->length == 0)
  {
    return NULL;
  }
  if (list->length == 1)
  {
    list->last = NULL;
  }

  Prev_Current_Pair node_pair;
  node_pair.prev = list->first;
  list->first = list->first->next;
  list->length--;
  return node_pair.prev->element;
}

Element remove_from_end(List_ptr list)
{
  if (list->length == 0)
  {
    return NULL;
  }
  if (list->length == 1)
  {
    return remove_from_start(list);
  }
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->first;
  while (node_pair.current != list->last)
  {
    node_pair.prev = node_pair.current;
    node_pair.current = node_pair.current->next;
  }
  list->last = node_pair.prev;
  list->last->next = NULL;
  list->length--;
  return node_pair.current->element;
}

Element remove_at(List_ptr list, int position)
{
  if (position > list->length || position < 0)
  {
    return NULL;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->length - 1)
  {
    return remove_from_end(list);
  }
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->first;
  for (int i = 0; i < position; i++)
  {
    node_pair.prev = node_pair.current;
    node_pair.current = node_pair.current->next;
  }
  node_pair.prev->next = node_pair.current->next;
  list->length--;
  return node_pair.current->element;
}

Status match_int(Element expected, Element actual)
{
  return *(int *)actual == *(int *)expected;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->first;
  int position = 0;
  while (node_pair.current != NULL && !(*matcher)(node_pair.current->element, element))
  {
    node_pair.current = node_pair.current->next;
    position++;
  }
  if (node_pair.current == NULL)
  {
    return NULL;
  }
  return remove_at(list, position);
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher) // Returns List of removed elements
{
  List_ptr new_list = create_list();
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->first;
  int position = 0;
  Node_ptr removed_element;
  while (node_pair.current != NULL)
  {
    if ((*matcher)(node_pair.current->element, element))
    {
      removed_element = remove_at(list, position);
      add_to_list(new_list, removed_element);
    }
    else
    {
      node_pair.prev = node_pair.current;
      position++;
    }
    node_pair.current = node_pair.current->next;
  }

  return new_list;
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->first;
  while (node_pair.current != NULL && !(*matcher)(node_pair.current->element, element))
  {
    node_pair.current = node_pair.current->next;
  }
  if (node_pair.current == NULL)
  {
    return add_to_list(list, element);
  }
  return Failure;
}

Element void_square(Element a)
{
  int square_of_a = *(int *)a * *(int *)a;
  Element square = malloc(sizeof(int));
  *(int *)square = square_of_a;
  return square;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr new_list = create_list();
  Element present_element = NULL;
  Prev_Current_Pair pair;
  pair.current = list->first;
  while (pair.current != NULL)
  {
    present_element = (*mapper)(pair.current->element);
    add_to_list(new_list, present_element);
    pair.current = pair.current->next;
  }
  return new_list;
}

Status void_filter_even(Element a)
{
  int number = *(int *)a;
  return number % 2 == 0 ? Success : Failure;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  List_ptr new_list = create_list();
  Element present_element = NULL;
  Prev_Current_Pair pair;
  pair.current = list->first;
  while (pair.current != NULL)
  {
    if ((*predicate)(pair.current->element))
    {
      add_to_list(new_list, pair.current->element);
    }
    pair.current = pair.current->next;
  }
  return new_list;
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
