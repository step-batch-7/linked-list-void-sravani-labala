#include "test_functions.h"

void test_reverse()
{
  printf("-------reverse list------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should reverse if the list is empty";
  int expected1[] = {};
  List_ptr reversed1 = reverse(list);
  result = assert(list, expected1, 0) && assert(reversed1, expected1, 0);
  print_status(result, message);
  free_list(reversed1);

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  add_to_list(list, num1);
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should reverse a list containing large elements";
  int reverse_expected[] = {3, 2, 1};
  int original_list[] = {1, 2, 3};
  List_ptr reversed2 = reverse(list);
  result = assert(list, original_list, 3) && assert(reversed2, reverse_expected, 3);
  print_status(result, message);
  free_list(reversed2);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}