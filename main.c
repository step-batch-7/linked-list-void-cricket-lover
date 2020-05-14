#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  display_list(list, &display_int);
  return 0;
}
