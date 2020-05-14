#include "sample_functions.h"

// Element mapper(Element element)
// {
// }

// Element reducer(Element element, Element element2)
// {
// }

// Status predicate(Element element)
// {
// }

// void processor(Element element)
// {
// }

// Status matcher(Element element, Element element2)
// {
// }

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