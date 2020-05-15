#include "test_functions.h"

void test_add_unique()
{
  printf("-------add_unique------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  message = "should add to an empty list";
  int *number1 = malloc(sizeof(int));
  *number1 = 1;
  status = add_unique(list, number1, &is_equal);
  int expected1[] = {1};
  result = status && assert(list, expected1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);

  message = "should add the element if it unique";
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  status = add_unique(list, num3, &is_equal);
  int expected2[] = {1, 2, 3};
  result = status && assert(list, expected2, 3);
  print_status(result, message);

  message = "should not add the element if it not unique";
  int *num4 = malloc(sizeof(int));
  *num4 = 1;
  status = add_unique(list, num4, &is_equal);
  int expected3[] = {1, 2, 3};
  result = !status && assert(list, expected3, 3);
  print_status(result, message);

  free_list(list);
  free(number1);
  free(num2);
  free(num3);
  free(num4);
}