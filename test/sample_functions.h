#ifndef __SAMPLE_FUNCTIONS_H__
#define __SAMPLE_FUNCTIONS_H__
#include "../linkedlist.h"

// Element mapper(Element);
// Element reducer(Element, Element);
// Status predicate(Element);
// void processor(Element);
// Status matcher(Element, Element);

void increment_processor(Element element);
Status is_even(Element element);
Element mapper_inc(Element element);
Element sum(Element value1, Element value2);

#endif