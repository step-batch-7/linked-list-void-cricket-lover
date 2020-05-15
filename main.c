#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 4);
  if (number == NULL || list == NULL)
  {
    return 1;
  }
  number[0] = 2;
  number[1] = 5;
  number[2] = 2;
  add_to_start(list, &number[0]);
  add_to_list(list, &number[1]);
  insert_at(list, &number[2], 1);
  display_list(list, &display_int);
  List_ptr new_list = remove_all_occurrences(list, &number[0], &match_int);
  display_list(new_list, &display_int);
  free(number);
  destroy_list(list);
  return 0;
}
