#include "../includes/llist.h"
#include <stdio.h>

# define HASHSIZE 128

void  test_bulk()
{
}

int main()
{
	//if(!(nodes=calloc(HASHSIZE, sizeof(struct hashnode_s*)))) {
	//	free(hashtbl);
	//	return NULL;
	//}
  //

  struct hashnode_s *nodes[HASHSIZE];
	char *test_node_1, *test_node_2, *test_node_3;

	hashtbl_set("France", "Paris");
	hashtbl_set("England", "London");
	hashtbl_set("Sweden", "Stockholm");
	hashtbl_set("Germany", "Berlin");
	hashtbl_set("Norway", "Oslo");
	hashtbl_set("Italy", "Rome");
	hashtbl_set("Spain", "Madrid");
	hashtbl_set("Estonia", "Tallinn");
	hashtbl_set("Netherlands", "Amsterdam");
	hashtbl_set("Ireland", "Dublin");

	printf("\nAfter insert:\n");
	
	test_node_1 = hashtbl_get("England");
	printf("England: %s\n", test_node_1?test_node_1:"-");
	
	test_node_2 = hashtbl_get("Ireland");
	printf("Ireland: %s\n", test_node_2?test_node_2:"-");

	hashtbl_remove("Ireland");
	printf("\nAfter remove:\n");
  
  
	test_node_1 = hashtbl_get("England");
	printf("England: %s\n", test_node_1?test_node_1:"-");
  
	test_node_2 = hashtbl_get("Ireland");
	printf("Ireland: %s\n", test_node_2?test_node_2:"-");

	hashtbl_destroy();
	printf("\nAfter destroy hash-table:\n");

	test_node_1 = hashtbl_get("Norway");
	printf("Norway: %s\n", test_node_1?test_node_1:"-");
  
	test_node_2 = hashtbl_get("Estonia");
	printf("Estonia: %s\n", test_node_2?test_node_2:"-");
  	
	test_node_3 = hashtbl_get("England");
	printf("England: %s\n", test_node_3?test_node_3:"-");

  return 0;
}
