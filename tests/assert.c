#include <stdio.h>
#include "../linkedlist.h"
#include "assert.h"

void display_test_result(Status actual, char *message)
{
  char *symbol = actual == Success ? "✓" : "✗";
  printf("%s %s\n", symbol, message);
}

Status assert_lists(Element expected, int length, List_ptr actual, Comparator comparator)
{
  if (actual->length != length)
  {
    return Failure;
  }
  int index = 0;
  Node_ptr p_walk = actual->first;
  while (p_walk != NULL && (*comparator)(p_walk, expected, index))
  {
    p_walk = p_walk->next;
    index++;
  }
  return p_walk == NULL ? Success : Failure;
}