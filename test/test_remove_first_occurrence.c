#include "test_functions.h"

void test_remove_first_occurrence()
{
  printf("-------remove_first_occurrence------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  remove_first_occurrence(list, num1, &is_equal);

  add_to_list(list, num1);

  message = "should remove the given element in a single element list";
  int *actual1 = remove_first_occurrence(list, num1, &is_equal);
  int expected1[] = {};
  result = *actual1 == 1 && assert(list, expected1, 0);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should remove the given element once in larger list";
  int *actual2 = remove_first_occurrence(list, num3, &is_equal);
  int expected2[] = {2};
  result = *actual2 == 3 && assert(list, expected2, 1);
  print_status(result, message);

  message = "should not remove if the given element is not present";
  int *actual3 = remove_first_occurrence(list, num3, &is_equal);
  int expected3[] = {2};
  result = actual3 == NULL && assert(list, expected3, 1);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}