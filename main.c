#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 5);
  if (number == NULL || list == NULL)
  {
    return 1;
  }
  number[0] = 3;
  number[1] = 51;
  number[2] = 21;
  number[3] = 14;
  number[4] = 12;
  add_to_list(list, &number[0]);
  add_to_list(list, &number[1]);
  add_to_list(list, &number[2]);
  add_to_list(list, &number[3]);
  add_to_list(list, &number[4]);
  display_list(list, &display_int);
  selection_sort(list, &compare_int);
  display_list(list, &display_int);
  free(number);
  destroy_list(list);
  return 0;
}
