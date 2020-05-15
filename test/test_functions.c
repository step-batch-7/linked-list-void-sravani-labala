#include "test_functions.h"

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
