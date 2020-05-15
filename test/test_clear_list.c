#include "test_functions.h"

void test_clear_list()
{
  printf("-------clear_list------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 0;
  clear_list(list);
  add_to_list(list, num1);

  message = "should clear all the elements in the list and set the list to zero";
  status = clear_list(list);
  int expected[] = {};
  result = status && assert(list, expected, 0);
  print_status(result, message);

  free_list(list);
  free(num1);
}