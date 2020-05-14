#include <stdio.h>
#include "../linkedlist.h"
#include "assert.h"

Status assert_int(Node_ptr p_walk, Element *expected, int index)
{
  return *(int *)expected[index] == *(int *)p_walk->element;
}

void test_add_to_last(void)
{
  printf("#add_to_last\n");
  List_ptr list = create_list();
  int *number = malloc(sizeof(int) * 2);
  *(number + 0) = 3;
  int *expected[2] = {number + 0};
  add_to_list(list, number);
  Status result = assert_lists(expected, 1, list, &assert_int);
  display_test_result(result, "should add one element to the last of the list, when the list is empty");

  *(number + 1) = 4;
  expected[1] = number + 1;
  add_to_list(list, number + 1);
  result = assert_lists(expected, 2, list, &assert_int);
  display_test_result(result, "should add one element to the last of the list, when the list is not empty");
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_last();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}