#include "test_functions.h"

void test_remove_from_start()
{
  printf("-------remove_from_start------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  int *actual;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  actual = remove_from_start(list);
  add_to_list(list, num1);

  message = "should be able to remove for a list containing one element";
  actual = remove_from_start(list);
  int expected1[] = {};
  result = *actual == 1 && assert(list, expected1, 0);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 1;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 2;
  add_to_list(list, num3);

  message = "should be able to remove at the start of the larger list";
  actual = remove_from_start(list);
  int expected2[] = {2};
  result = *actual == 1 && assert(list, expected2, 1);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}