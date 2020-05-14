#ifndef __ASSERT_H
#define __ASSERT_H

void display_test_result(Status actual, char *message);
typedef Status (*Comparator)(Node_ptr p_walk, Element *expected, int index);
Status assert_lists(Element expected, int length, List_ptr actual, Comparator comparator);

#endif