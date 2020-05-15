#include "test_functions.h"

void test_map()
{
  printf("-------map------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should map an empty list";
  List_ptr mapped_list1 = map(list, &mapper_inc);
  int expected1[] = {};
  result = assert(list, expected1, 0) && assert(mapped_list1, expected1, 0);
  print_status(result, message);
  free_list(mapped_list1);

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  add_to_list(list, num1);
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should map the values for the larger list";
  List_ptr mapped_list2 = map(list, &mapper_inc);
  int expected2[] = {2, 3, 4};
  int original_list[] = {1, 2, 3};
  result = assert(list, original_list, 3) && assert(mapped_list2, expected2, 3);
  print_status(result, message);
  free_list(mapped_list2);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}