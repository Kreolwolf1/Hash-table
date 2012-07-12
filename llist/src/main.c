#include "llist.c"

int main()
{
	node_t 	*list;
	node_t	*match;

	/* Create initial elements of list */
	list=list_create((void*)"First");
	
	printf("Initial list:\n");
	printf("%s\n", (char *)list->data);
	putchar('\n');

	/* Insert 1 extra element in front */
	list=list_insert(list, "BeforeFirst");
	printf("After list_insert_beginning():\n");
	printf("%s\n", (char *)list->data);
	putchar('\n');

	/* Find element in front */
	printf("search test: \n");
	list=list_insert(list, "search_test");
	if((match=list_find(list, findstring, "search_test")))
		printf("Found \"search_test\"\n");
	else printf("Did not find \"search_test\"\n");

	return 0;
}