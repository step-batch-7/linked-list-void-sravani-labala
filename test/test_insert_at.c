#include "test_functions.h"

void test_insert_at()
{
  printf("-------insert_at------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  message = "should be able to add at the position 0 for empty list";
  status = insert_at(list, num1, 0);
  int expected1[] = {1};
  result = status && assert(list, expected1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  message = "should be able to add at the position 0 for larger list";
  status = insert_at(list, num2, 0);
  int expected2[] = {2, 1};
  result = status && assert(list, expected2, 2);
  print_status(result, message);

  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  message = "should be able to add at the middle of the list";
  status = insert_at(list, num3, 1);
  int expected3[] = {2, 3, 1};
  result = status && assert(list, expected3, 3);
  print_status(result, message);

  int *num4 = malloc(sizeof(int));
  *num4 = 4;
  message = "should be able to add at the last position of the list";
  status = insert_at(list, num4, 2);
  int expected4[] = {2, 3, 4, 1};
  result = status && assert(list, expected4, 4);
  print_status(result, message);

  int *num5 = malloc(sizeof(int));
  *num5 = 5;
  message = "should be able to add at the end of the larger list";
  status = insert_at(list, num5, 4);
  int expected5[] = {2, 3, 4, 1, 5};
  result = status && assert(list, expected5, 5);
  print_status(result, message);

  int *num6 = malloc(sizeof(int));
  *num6 = 6;
  message = "should not add if the position is invalid (negative position)";
  status = insert_at(list, num6, -1);
  result = !status && assert(list, expected5, 5);
  print_status(result, message);

  message = "should not add if the position is invalid (position greater than the list)";
  status = insert_at(list, num6, 10);
  result = !status && assert(list, expected5, 5);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  free(num6);
}