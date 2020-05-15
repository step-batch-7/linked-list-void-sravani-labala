#include "test_functions.h"

void test_for_each()
{
  printf("-------for each list------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should iterate in an empty list";
  forEach(list, &increment_processor);
  int expected1[] = {};
  result = assert(list, expected1, 0);
  print_status(result, message);

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  add_to_list(list, num1);
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should iterate and modify on the list";
  forEach(list, &increment_processor);
  int expected2[] = {2, 3, 4};
  result = assert(list, expected2, 3);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}