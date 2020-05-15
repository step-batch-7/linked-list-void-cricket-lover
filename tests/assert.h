#ifndef __ASSERT_H
#define __ASSERT_H

typedef int *Int_ptr;
typedef char *Char_ptr;

void display_test_result(Status actual, Status expected, char *message);
typedef Status (*Comparator)(Element actual, Element *expected, int index);
Status assert_lists(Element expected, int length, List_ptr actual, Comparator comparator, Status actual_status);

#endif