#include "test_functions.h"

void test_add_to_list()
{
  printf("-------add_to_list------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  message = "should be able to add at the end for an empty list";
  int expected_values1[] = {1};
  status = add_to_list(list, num1);
  result = status && assert(list, expected_values1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  message = "should be able to add at the end of the larger list";
  int expected_values2[] = {1, 2};
  status = add_to_list(list, num2);
  result = status && assert(list, expected_values2, 2);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
}