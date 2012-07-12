#include "llist.c"
#include <stdlib.h>
void main()
{
	node_t *list;

	list = node_init("first", "first_value");
	printf("%s\n", list->data->value);
  list = llist_set(list, "second", "second_value");
	printf("%s\n", list->data->value);
}