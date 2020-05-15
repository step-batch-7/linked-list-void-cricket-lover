#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 4);
  number[0] = 2;
  number[1] = 5;
  number[2] = 3;
  add_to_start(list, &number[0]);
  add_to_list(list, &number[1]);
  insert_at(list, &number[2], 1);
  display_list(list, &display_int);
  forEach(list, &display_int);
  destroy_list(list);
  return 0;
}
