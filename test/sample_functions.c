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

void increment_processor(Element element)
{
  int previous_value = *(int *)element;
  *(int *)element = previous_value + 1;
}