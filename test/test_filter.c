#include "test_functions.h"

void test_filter()
{
  printf("-------filter------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should filter an empty list";
  List_ptr filtered1 = filter(list, &is_even);
  int expected1[] = {};
  result = assert(list, expected1, 0) && assert(filtered1, expected1, 0);
  print_status(result, message);
  free_list(filtered1);

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  add_to_list(list, num1);
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should filter for a larger list";
  List_ptr filtered2 = filter(list, &is_even);
  int expected2[] = {2};
  int original_list[] = {1, 2, 3};
  result = assert(list, original_list, 3) && assert(filtered2, expected2, 1);
  print_status(result, message);
  free_list(filtered2);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}