#include "sample_functions.h"

Element mapper_inc(Element element)
{
  int *mapped_ptr = malloc(sizeof(int));
  *mapped_ptr = *(int *)element + 1;
  return mapped_ptr;
}

void increment_processor(Element element)
{
  int previous_value = *(int *)element;
  *(int *)element = previous_value + 1;
}

Status is_even(Element element)
{
  Status status = (*(int *)element % 2) ? Failure : Success;
  return status;
}

Element sum(Element value1, Element value2)
{
  int *result = malloc(sizeof(int));
  *result = *(int *)value1 + *(int *)value2;
  return result;
}

Status is_equal(Element value1, Element value2)
{
  Status status = *(int *)value1 == *(int *)value2;
  return status;
}