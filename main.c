#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 3);
  number[0] = 3;
  number[1] = 4;
  number[2] = 5;
  add_to_start(list, &number[0]);
  add_to_list(list, &number[1]);
  insert_at(list, &number[2], 1);
  display_list(list, &display_int);
  Element removed_element = remove_first_occurrence(list, &number[1], &match_int);
  display_list(list, &display_int);
  return 0;
}
