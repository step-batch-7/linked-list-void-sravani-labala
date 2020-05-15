#include "test_functions.h"

void test_remove_at()
{
  printf("-------remove_at------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  int *actual;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  actual = remove_at(list, 0);
  add_to_list(list, num1);

  message = "should be able to remove at position 0 for a list containing one element";
  actual = remove_at(list, 0);
  int expected1[] = {};
  result = *actual == 1 && assert(list, expected1, 0);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 1;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 2;
  add_to_list(list, num3);
  int *num4 = malloc(sizeof(int));
  *num4 = 3;
  add_to_list(list, num4);
  int *num5 = malloc(sizeof(int));
  *num5 = 4;
  add_to_list(list, num5);
  int *num6 = malloc(sizeof(int));
  *num6 = 5;
  add_to_list(list, num6);

  message = "should be able to remove at the position 0 for larger list";
  actual = remove_at(list, 0);
  int expected2[] = {2, 3, 4, 5};
  result = *actual == 1 && assert(list, expected2, 4);
  print_status(result, message);

  message = "should be able to remove at the middle of the list";
  actual = remove_at(list, 1);
  int expected3[] = {2, 4, 5};
  result = *actual == 3 && assert(list, expected3, 3);
  print_status(result, message);

  message = "should be able to remove at the end of the larger list";
  actual = remove_at(list, 2);
  int expected4[] = {2, 4};
  result = *actual == 5 && assert(list, expected4, 2);
  print_status(result, message);

  message = "should not remove if the position is invalid (position greater than the list)";
  actual = remove_at(list, 2);
  result = actual == NULL && assert(list, expected4, 2);
  print_status(result, message);

  message = "should not remove if the position is invalid (negative position)";
  actual = remove_at(list, -5);
  result = actual == NULL && assert(list, expected4, 2);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  free(num6);
}