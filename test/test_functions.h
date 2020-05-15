#ifndef __TEST_FUNCTIONS__
#define __TEST_FUNCTIONS__
#include "../linkedlist.h"
#include "sample_functions.h"

void print_status(Status status, char *message);
Status assert(List_ptr list, int *values, int length);
void free_list(List_ptr list);
void display(List_ptr list);

void test_add_to_list();
void test_add_to_start();
void test_insert_at();
void test_remove_from_start();
void test_remove_from_end();
void test_remove_at();
void test_clear_list();
void test_reverse();
void test_for_each();
void test_filter();
void test_map();
void test_reduce();
void test_add_unique();
void test_remove_first_occurrence();
void test_remove_all_occurrences();
#endif