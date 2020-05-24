#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 5);
  if (number == NULL || list == NULL)
  {
    return 1;
  }
  number[0] = 5;
  number[1] = 4;
  number[2] = 3;
  number[3] = 2;
  number[4] = 1;
  add_to_list(list, &number[0]);
  add_to_list(list, &number[1]);
  add_to_list(list, &number[2]);
  add_to_list(list, &number[3]);
  add_to_list(list, &number[4]);
  display_list(list, &display_int);
  insertion_sort(list, &compare_int);
  display_list(list, &display_int);
  free(number);
  destroy_list(list);
  return 0;
}
