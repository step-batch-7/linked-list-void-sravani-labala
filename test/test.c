#include "../linkedlist.h"
#include "sample_functions.h"

void print_status(Status status, char *message)
{
  printf("%s\n%s\n\n", message, status ? "Success" : "Failure");
}

Status assert(List_ptr list, int *values, int length)
{
  Status status = Success;
  Node_ptr p_walk = list->first;
  int index = 0;
  while (p_walk != NULL)
  {
    status = *(int *)p_walk->element == values[index];
    p_walk = p_walk->next;
    index++;
  }
  return status && list->length == length;
}

void free_list(List_ptr list)
{
  Node_ptr element = NULL;
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    element = p_walk;
    p_walk = p_walk->next;
    free(element);
  }
  free(list);
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d ", *(int *)p_walk->element);
    p_walk = p_walk->next;
  }
}

void test_add_to_list()
{
  printf("-------add_to_list------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  message = "should be able to add at the end for an empty list";
  int expected_values1[] = {1};
  status = add_to_list(list, num1);
  result = status && assert(list, expected_values1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  message = "should be able to add at the end of the larger list";
  int expected_values2[] = {1, 2};
  status = add_to_list(list, num2);
  result = status && assert(list, expected_values2, 2);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
}

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

void test_insert_at()
{
  printf("-------insert_at------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  Status status;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  message = "should be able to add at the position 0 for empty list";
  status = insert_at(list, num1, 0);
  int expected1[] = {1};
  result = status && assert(list, expected1, 1);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  message = "should be able to add at the position 0 for larger list";
  status = insert_at(list, num2, 0);
  int expected2[] = {2, 1};
  result = status && assert(list, expected2, 2);
  print_status(result, message);

  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  message = "should be able to add at the middle of the list";
  status = insert_at(list, num3, 1);
  int expected3[] = {2, 3, 1};
  result = status && assert(list, expected3, 3);
  print_status(result, message);

  int *num4 = malloc(sizeof(int));
  *num4 = 4;
  message = "should be able to add at the last position of the list";
  status = insert_at(list, num4, 2);
  int expected4[] = {2, 3, 4, 1};
  result = status && assert(list, expected4, 4);
  print_status(result, message);

  int *num5 = malloc(sizeof(int));
  *num5 = 5;
  message = "should be able to add at the end of the larger list";
  status = insert_at(list, num5, 4);
  int expected5[] = {2, 3, 4, 1, 5};
  result = status && assert(list, expected5, 5);
  print_status(result, message);

  int *num6 = malloc(sizeof(int));
  *num6 = 6;
  message = "should not add if the position is invalid (negative position)";
  status = insert_at(list, num6, -1);
  result = !status && assert(list, expected5, 5);
  print_status(result, message);

  message = "should not add if the position is invalid (position greater than the list)";
  status = insert_at(list, num6, 10);
  result = !status && assert(list, expected5, 5);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  free(num6);
}

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

void test_remove_from_end()
{
  printf("-------remove_from_end------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  int *actual;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  actual = remove_from_end(list);
  add_to_list(list, num1);

  message = "should be able to remove for the list containing one element";
  actual = remove_from_end(list);
  int expected1[] = {};
  result = *actual == 1 && assert(list, expected1, 0);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 1;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 2;
  add_to_list(list, num3);

  message = "should be able to remove at the end of the larger list";
  actual = remove_from_end(list);
  int expected2[] = {1};
  result = *actual == 2 && assert(list, expected2, 1);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}

void test_remove_at()
{
  printf("-------remove_at------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;
  int *actual;

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  actual = remove_at(list, 0);
  add_to_list(list, num1);

  message = "should be able to remove at position 0 for a list containing one element";
  actual = remove_at(list, 0);
  int expected1[] = {};
  result = *actual == 1 && assert(list, expected1, 0);
  print_status(result, message);

  int *num2 = malloc(sizeof(int));
  *num2 = 1;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 2;
  add_to_list(list, num3);
  int *num4 = malloc(sizeof(int));
  *num4 = 3;
  add_to_list(list, num4);
  int *num5 = malloc(sizeof(int));
  *num5 = 4;
  add_to_list(list, num5);
  int *num6 = malloc(sizeof(int));
  *num6 = 5;
  add_to_list(list, num6);

  message = "should be able to remove at the position 0 for larger list";
  actual = remove_at(list, 0);
  int expected2[] = {2, 3, 4, 5};
  result = *actual == 1 && assert(list, expected2, 4);
  print_status(result, message);

  message = "should be able to remove at the middle of the list";
  actual = remove_at(list, 1);
  int expected3[] = {2, 4, 5};
  result = *actual == 3 && assert(list, expected3, 3);
  print_status(result, message);

  message = "should be able to remove at the end of the larger list";
  actual = remove_at(list, 2);
  int expected4[] = {2, 4};
  result = *actual == 5 && assert(list, expected4, 2);
  print_status(result, message);

  message = "should not remove if the position is invalid (position greater than the list)";
  actual = remove_at(list, 2);
  result = actual == NULL && assert(list, expected4, 2);
  print_status(result, message);

  message = "should not remove if the position is invalid (negative position)";
  actual = remove_at(list, -5);
  result = actual == NULL && assert(list, expected4, 2);
  print_status(result, message);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  free(num6);
}

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

void test_for_each()
{
  printf("-------reverse list------\n");
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

void test_filter()
{
  printf("-------filter------\n");
  char *message = NULL;
  List_ptr list = create_list();
  int result;

  message = "should filter an empty list";
  List_ptr filtered1 = filter(list, &is_even);
  int expected1[] = {};
  result = assert(list, expected1, 0) && assert(filtered1, expected1, 0);
  print_status(result, message);
  free_list(filtered1);

  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  add_to_list(list, num1);
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  add_to_list(list, num2);
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  add_to_list(list, num3);

  message = "should filter for a larger list";
  List_ptr filtered2 = filter(list, &is_even);
  int expected2[] = {2};
  int original_list[] = {1, 2, 3};
  result = assert(list, original_list, 3) && assert(filtered2, expected2, 1);
  print_status(result, message);
  free_list(filtered2);

  free_list(list);
  free(num1);
  free(num2);
  free(num3);
}

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

int main(void)
{
  test_add_to_list();
  test_add_to_start();
  test_insert_at();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_clear_list();
  test_reverse();
  test_for_each();
  test_filter();
  test_map();
  return 0;
}