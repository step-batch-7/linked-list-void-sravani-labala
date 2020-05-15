#include "test_functions.h"

void test_add_to_start()
{
  printf("-------add_to_start------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  message = "should be able to add at the start for an empty list";
  status = add_to_start(list, num1);
  int expected_values1[] = {1};
  result = status && assert(list, expected_values1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  message = "should be able to add at the start of the larger list";
  status = add_to_start(list, num2);
  int expected_values2[] = {2, 1};
  result = status && assert(list, expected_values2, 2);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
}