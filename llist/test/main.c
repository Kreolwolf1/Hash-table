#include "llist.h"
#include <stdio.h>
  
int main()
{
  node_lt *list, *second, *list_test, *inserted;
  node_lt *match;

  list_test = list_create((void*)"Test");
  printf("Before list_remove():\n");
  list_foreach(list_test, printstring);

  inserted = list_find(list_test, findstring, "Test");
  printf("After list_remove():\n");
  if (!list_remove(list_test, list_test))
    printf(" >> Head of list has been removed\n");
  else
    list_foreach(list_test, printstring);
  putchar('\n');


  /* Create initial elements of list */
  list = list_create((void*)"First");
  second = list_insert_after(list, (void *)"Second");
  list_insert_after(second, (void *)"Third");

  printf("Initial list:\n");
  list_foreach(list, printstring);
  putchar('\n');

  /* Insert 1 extra element in front */
  list = list_insert(list, "BeforeFirst");
  printf("After list_insert():\n");
  list_foreach(list, printstring);
  putchar('\n');

  /* Insert 1 extra element after second */
  inserted = list_insert_after(second, "AfterSecond");
  printf("After list_insert_after():\n");
  list_foreach(list, printstring);
  putchar('\n');

  /* Remove the element */
  list_remove(list, inserted);
  printf("After list_remove():\n");
  list_foreach(list, printstring);
  putchar('\n');

  /* List destroy */
  list_destroy(list);
  printf("After list_destroy():\n");
  list_foreach(list, printstring);

  /* Search */
  if((match = list_find(list, findstring, "Third")))
    printf("Found \"Third\"\n");
  else
    printf("Did not find \"Third\"\n");

  return 0;
}