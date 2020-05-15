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
  Status actual_status, result;
  int *number = malloc(sizeof(int) * 2);
  number[0] = 3;
  int *expected[2] = {&number[0]};
  actual_status = add_to_list(list, number);
  result = assert_lists(expected, 1, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should add one element to the last of the list, when the list is empty");

  number[1] = 4;
  expected[1] = &number[1];
  actual_status = add_to_list(list, &number[1]);
  result = assert_lists(expected, 2, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should add one element to the last of the list, when the list is not empty");
}

void test_add_to_start(void)
{
  printf("#add_to_start\n");
  List_ptr list = create_list();
  Status actual_status, result;
  int *number = malloc(sizeof(int) * 2);
  number[0] = 3;
  int *expected[2] = {&number[0]};
  actual_status = add_to_start(list, number);
  result = assert_lists(expected, 1, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should add one element to the start of the list, when the list is empty");

  number[1] = 4;
  expected[0] = &number[1];
  expected[1] = &number[0];
  actual_status = add_to_start(list, &number[1]);
  result = assert_lists(expected, 2, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should add one element to the start of the list, when the list is not empty");
}

void insert_at_start(List_ptr list, Int_ptr *expected)
{
  int *number = malloc(sizeof(int) * 2);
  number[0] = 3;
  Status actual_status, result;
  actual_status = insert_at(list, number, 1);
  result = assert_lists(expected, 0, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should not insert at any position other than start when the list is empty");

  expected[0] = &number[0];
  actual_status = insert_at(list, &number[0], 0);
  result = assert_lists(expected, 1, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should insert one element to the start of the list, when the list is empty");

  number[1] = 4;
  expected[0] = &number[1];
  expected[1] = &number[0];
  actual_status = insert_at(list, &number[1], 0);
  result = assert_lists(expected, 2, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should insert one element to the start of the list, when the list is not empty");
}

void insert_at_middle(List_ptr list, Int_ptr *expected)
{
  Status actual_status, result;
  int *number = malloc(sizeof(int));
  number[0] = 5;
  expected[2] = expected[1];
  expected[1] = &number[0];
  actual_status = insert_at(list, &number[0], 1);
  result = assert_lists(expected, 3, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should insert at the requested position if the position is valid");

  actual_status = insert_at(list, &number[0], 6);
  result = assert_lists(expected, 3, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should not insert when the position is more than than maximum position");

  actual_status = insert_at(list, &number[0], -1);
  result = assert_lists(expected, 3, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should not insert when the position less than zero");
}

void insert_at_end(List_ptr list, Int_ptr *expected)
{
  Status actual_status, result;
  int *number = malloc(sizeof(int));
  number[0] = 6;
  expected[3] = &number[0];
  actual_status = insert_at(list, &number[0], 3);
  result = assert_lists(expected, 4, list, &assert_int, actual_status);
  display_test_result(actual_status, result, "should insert at last position when the position is equal to the length of the list");
}

void test_reverse(void)
{
  printf("#reverse\n");
  List_ptr list = create_list();
  Status actual_status, result;
  int *number = malloc(sizeof(int) * 3);
  number[0] = 3;
  number[1] = 4;
  number[2] = 5;
  int *expected[3] = {};
  List_ptr actual = reverse(list);
  result = assert_lists(expected, 0, actual, &assert_int, Success);
  display_test_result(Success, result, "should give back the empty list when an empty list is given");

  expected[0] = &number[2];
  expected[1] = &number[1];
  expected[2] = &number[0];
  add_to_list(list, &number[0]);
  add_to_list(list, &number[1]);
  add_to_list(list, &number[2]);
  actual = reverse(list);
  result = assert_lists(expected, 3, actual, &assert_int, Success);
  display_test_result(Success, result, "should reverse and give back the reversed list");
}

void test_insert_at(void)
{
  printf("#insert_at\n");
  List_ptr list = create_list();
  int *expected[5] = {};
  insert_at_start(list, expected);
  insert_at_middle(list, expected);
  insert_at_end(list, expected);
}

void test_map(void)
{
  printf("#map\n");
  List_ptr list = create_list();
  Status result;
  int *expected[3] = {};
  List_ptr actual = map(list, &void_square);
  result = assert_lists(expected, 0, actual, &assert_int, Success);
  display_test_result(Success, result, "should give back the empty list when an empty list is given");

  int *number = malloc(sizeof(int) * 3);
  number[0] = 3;
  number[1] = 4;
  number[2] = 5;
  int *squares = malloc(sizeof(int) * 3);
  squares[0] = 9;
  squares[1] = 16;
  squares[2] = 25;
  expected[0] = &squares[0];
  expected[1] = &squares[1];
  expected[2] = &squares[2];
  add_to_list(list, &number[0]);
  add_to_list(list, &number[1]);
  add_to_list(list, &number[2]);
  actual = map(list, &void_square);
  result = assert_lists(expected, 3, actual, &assert_int, Success);
  display_test_result(Success, result, "should give back the list mapped with the requested mapper");
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_last();
  test_add_to_start();
  test_insert_at();
  test_reverse();
  test_map();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}