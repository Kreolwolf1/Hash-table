#include "../includes/llist.h"
#include <stdio.h>

int main()
{

  //TEST FOR set AND get ACTIONS
  char *test_node, *test_node_2;
  
  hashtbl_set("test","value");
  test_node = hashtbl_get("test");
  
  if (test_node == "value")
    printf("\nTEST FOR set AND get ACTIONS successfilly completed\n\n");
  else
    printf("\nTEST FOR set AND get ACTIONS failed.\n Must return ->value<-\n But return ->%s<-\n",test_node?test_node:"-");
  


  //TEST FOR remove ACTION
  hashtbl_remove("test");
  test_node = hashtbl_get("test");

  if (!test_node)
    printf("\nTEST FOR remove ACTIONS successfilly completed\n\n");
  else
    printf("\nTEST FOR remove ACTION failed.\n Return ->%s<-\n",test_node?test_node:"-");
 


  //TEST FOR remove ACTION
  hashtbl_set("test","value");
  hashtbl_set("test2","value2");
  hashtbl_destroy();
  test_node = hashtbl_get("test");
  test_node_2 = hashtbl_get("test2");


  if (!test_node && !test_node_2)
    printf("\nTEST FOR destroy ACTION successfilly completed\n\n");
  else
    printf("\nTEST FOR remove ACTIONS failed.\n Return ->%s<-\n AND ->%s<-\n",test_node?test_node:"-",test_node_2?test_node_2:"-");



  return 0;
}
