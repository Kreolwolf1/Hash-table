#include "llist.c"

int main()
{
	node_t *list, *second, *inserted;
	node_t *match;

	/* Create initial elements of list */
	list=list_create((void*)"First");
	second=list_insert_after(list, (void*)"Second");
	list_insert_after(second, (void*)"Third");

	printf("Initial list:\n");
	list_foreach(list, printstring);
	putchar('\n');

	/* Insert 1 extra element in front */
	list=list_insert(list, "BeforeFirst");
	printf("After list_insert():\n");
	list_foreach(list, printstring);
	putchar('\n');

	/* Insert 1 extra element after second */
	inserted=list_insert_after(second, "AfterSecond");
	printf("After list_insert_after():\n");
	list_foreach(list, printstring);
	putchar('\n');

	/* Remove the element */
	list_remove(list, inserted);
	printf("After list_remove():\n");
	list_foreach(list, printstring);
	putchar('\n');

	/* Search */
	if((match=list_find(list, findstring, "Third")))
		printf("Found \"Third\"\n");
	else printf("Did not find \"Third\"\n");

	return 0;
}