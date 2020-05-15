#include "test_functions.h"

void test_reduce()
{
  printf("-------reduce------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should give initial value if the list is empty";
  int *init = malloc(sizeof(int));
  *init = 0;
  int *actual1 = reduce(list, init, &sum);
  int original[] = {};
  result = *actual1 == 0 && assert(list, original, 0);
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

  message = "should give the reduced value for a larger list";
  int *actual2 = reduce(list, init, &sum);
  int original2[] = {1, 2, 3};
  result = *actual2 == 6 && assert(list, original2, 3);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(init);
}