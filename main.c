#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 2);
  *(number + 0) = 3;
  *(number + 1) = 4;
  add_to_start(list, number + 0);
  add_to_last(list, number + 1);
  display_list(list, &display_int);
  return 0;
}
