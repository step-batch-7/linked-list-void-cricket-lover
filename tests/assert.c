#include <stdio.h>
#include "../linkedlist.h"
#include "assert.h"

void display_test_result(Status actual, Status expected, char *message)
{
  char *symbol = actual == expected ? "✓" : "✗";
  printf("%s %s\n", symbol, message);
}

Status assert_lists(Element expected, int length, List_ptr actual, Comparator comparator, Status actual_status)
{
  if (actual->length != length)
  {
    return Failure;
  }
  int index = 0;
  Node_ptr p_walk = actual->first;
  while (p_walk != NULL && (*comparator)(p_walk->element, expected, index))
  {
    p_walk = p_walk->next;
    index++;
  }
  Status status = p_walk == NULL ? Success : Failure;
  return status == actual_status;
}