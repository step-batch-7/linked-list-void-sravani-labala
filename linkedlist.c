#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr new_list = (List_ptr)malloc(sizeof(LinkedList));
  if (new_list != NULL)
  {
    new_list->first = NULL;
    new_list->last = NULL;
    new_list->length = 0;
  }
  return new_list;
}

Node_ptr create_node(Element value)
{
  Node_ptr new_node = (Node_ptr)malloc(sizeof(Node));
  if (new_node != NULL)
  {
    new_node->element = value;
    new_node->next = NULL;
  }
  return new_node;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
  {
    return Failure;
  }
  Node_ptr *ptr_to_set = &list->first;
  if (list->first != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  *ptr_to_set = new_node;
  list->last = new_node;
  list->length++;
  return Success;
}

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
  {
    return Failure;
  }
  if (list->last == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->first;
  list->first = new_node;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{
  if (list->length < position || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }
  if (position == (list->length))
  {
    return add_to_list(list, element);
  }
  Node_ptr new_node = create_node(element);
  if (new_node == NULL)
  {
    return Failure;
  }
  Node_ptr p_walk = list->first;
  int index = 1;
  while (index < position)
  {
    p_walk = p_walk->next;
    index++;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->length++;
  return Success;
}

List_ptr reverse(List_ptr list)
{
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Element element = (*mapper)(p_walk->element);
    add_to_list(new_list, element);
    p_walk = p_walk->next;
  }
  return new_list;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
}

Element reduce(List_ptr list, Element element, Reducer reducer)
{
}

void forEach(List_ptr list, ElementProcessor processor)
{
}

Element remove_from_start(List_ptr list)
{
  Node_ptr p_walk = list->first;
  if (p_walk == NULL)
  {
    return NULL;
  }
  list->first = p_walk->next;
  Element element = p_walk->element;
  free(p_walk);
  if (list->length == 1)
  {
    list->last = NULL;
  }
  list->length--;
  return element;
}

Element remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->first;
  if (p_walk == NULL)
  {
    return NULL;
  }
  int index = 1;
  while (index < list->length - 1)
  {
    p_walk = p_walk->next;
    index++;
  }
  p_walk->next = NULL;
  Element element = p_walk->element;
  free(list->last);
  list->last = p_walk;
  if (list->length == 1)
  {
    list->first = NULL;
  }
  list->length--;
  return element;
}

Element remove_at(List_ptr list, int position)
{
  if ((list->length - 1) < position || position < 0)
  {
    return NULL;
  };
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == (list->length - 1))
  {
    return remove_from_end(list);
  }
  Node_ptr p_walk = list->first;
  int index = 1;
  while (index < position)
  {
    p_walk = p_walk->next;
    index++;
  }
  Node_ptr remove = p_walk->next;
  p_walk->next = remove->next;
  Element element = remove->element;
  free(remove);
  list->length--;
  return element;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher)
{
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
}

Status clear_list(List_ptr list)
{
  Node_ptr element = NULL;
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    element = p_walk;
    p_walk = p_walk->next;
    free(element);
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
}