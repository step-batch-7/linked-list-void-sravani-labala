#include "test_functions.h"

void test_remove_all_occurrences()
{
  printf("-------remove_all_occurrence------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  remove_all_occurrences(list, num1, &is_equal);

  add_to_list(list, num1);

  message = "should remove the given element in a single element list";
  List_ptr removed_list1 = remove_all_occurrences(list, num1, &is_equal);
  int expected1[] = {};
  int removed[] = {1};
  result = assert(list, expected1, 0) && assert(removed_list1, removed, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 1;
  add_to_list(list, num3);
  int *num4 = malloc(sizeof(int));
  *num4 = 2;
  add_to_list(list, num4);

  message = "should remove all occurrences of given element in larger list";
  List_ptr removed_list2 = remove_all_occurrences(list, num2, &is_equal);
  int expected2[] = {2, 2};
  int original2[] = {1};
  result = assert(list, original2, 1) && assert(removed_list2, expected2, 2);
  print_status(result, message);

  message = "should not remove if the given element is not present";
  List_ptr removed_list3 = remove_all_occurrences(list, num2, &is_equal);
  int expected3[] = {};
  result = assert(list, original2, 1) && assert(removed_list3, expected3, 0);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(num4);
}