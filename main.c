#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *number1 = malloc(sizeof(int));
  *number1 = 3;
  add_to_start(list, number1);
  display_list(list, &display_int);
  return 0;
}
