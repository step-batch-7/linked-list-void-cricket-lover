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
  Status actual_status, expected_status;
  int *number = malloc(sizeof(int) * 2);
  *(number + 0) = 3;
  int *expected[2] = {number + 0};
  actual_status = add_to_list(list, number);
  expected_status = assert_lists(expected, 1, list, &assert_int);
  display_test_result(actual_status, expected_status, "should add one element to the last of the list, when the list is empty");

  *(number + 1) = 4;
  expected[1] = number + 1;
  actual_status = add_to_list(list, number + 1);
  expected_status = assert_lists(expected, 2, list, &assert_int);
  display_test_result(actual_status, expected_status, "should add one element to the last of the list, when the list is not empty");
}

void test_add_to_start(void)
{
  printf("#add_to_start\n");
  List_ptr list = create_list();
  Status actual_status, expected_status;
  int *number = malloc(sizeof(int) * 2);
  *(number + 0) = 3;
  int *expected[2] = {number + 0};
  actual_status = add_to_start(list, number);
  expected_status = assert_lists(expected, 1, list, &assert_int);
  display_test_result(actual_status, expected_status, "should add one element to the start of the list, when the list is empty");

  *(number + 1) = 4;
  expected[0] = number + 1;
  expected[1] = number + 0;
  actual_status = add_to_start(list, number + 1);
  expected_status = assert_lists(expected, 2, list, &assert_int);
  display_test_result(actual_status, expected_status, "should add one element to the start of the list, when the list is not empty");
}

void insert_at_start(List_ptr list, Int_ptr *expected)
{
  int *number = malloc(sizeof(int) * 2);
  *(number + 0) = 3;
  Status actual_status, expected_status;
  actual_status = insert_at(list, number, 1);
  expected_status = assert_lists(expected, 1, list, &assert_int);
  display_test_result(actual_status, expected_status, "should not insert at any position other than start when the list is empty");

  expected[0] = number + 0;
  actual_status = insert_at(list, number + 0, 0);
  expected_status = assert_lists(expected, 1, list, &assert_int);
  display_test_result(actual_status, expected_status, "should insert one element to the start of the list, when the list is empty");

  *(number + 1) = 4;
  expected[0] = number + 1;
  expected[1] = number + 0;
  actual_status = insert_at(list, number + 1, 0);
  expected_status = assert_lists(expected, 2, list, &assert_int);
  display_test_result(actual_status, expected_status, "should insert one element to the start of the list, when the list is not empty");
}

void insert_at_middle(List_ptr list, Int_ptr *expected)
{
  Status actual_status, expected_status;
  int *number = malloc(sizeof(int));
  *(number + 0) = 5;

  actual_status = insert_at(list, number + 0, 6);
  expected_status = assert_lists(expected, 3, list, &assert_int);
  display_test_result(actual_status, expected_status, "should not insert when the position is more than than maximum position");

  actual_status = insert_at(list, number + 0, -1);
  expected_status = assert_lists(expected, 3, list, &assert_int);
  display_test_result(actual_status, expected_status, "should not insert when the position less than zero");
}

void test_insert_at(void)
{
  printf("#insert_at\n");
  List_ptr list = create_list();
  int *expected[5] = {};
  insert_at_start(list, expected);
  insert_at_middle(list, expected);
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_last();
  test_add_to_start();
  test_insert_at();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}