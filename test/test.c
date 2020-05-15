#include "test_functions.h"

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
  test_reduce();
  test_add_unique();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  return 0;
}