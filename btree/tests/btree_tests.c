#include "../src/btree.c"


int main()
{
  node_t *btree;
  node_t *value;
  node_t *value1;

  btree = list_create("test");

  list_insert(btree, "7", def_btree_search_func); 

  value = list_find(btree, def_btree_search_func, "7");

  //printf("-->%s\n", (char *)value->data);


  list_insert(btree, "16", def_btree_search_func); 
  list_insert(btree, "19", def_btree_search_func); 
  list_insert(btree, "11", def_btree_search_func); 
  list_insert(btree, "13", def_btree_search_func); 
  list_insert(btree, "12", def_btree_search_func); 
  list_insert(btree, "14", def_btree_search_func); 
  list_insert(btree, "18", def_btree_search_func);


  value = list_find(btree, def_btree_search_func, "12");
  
  
  list_remove(btree, value, def_btree_search_func);
  list_destroy(btree);
  
  value = list_find(btree, def_btree_search_func, "11");
  printf("-->%s\n", (char *)value);
  value = list_find(btree, def_btree_search_func, "16");
  printf("-->%s\n", (char *)value);
  value = list_find(btree, def_btree_search_func, "19");
  printf("-->%s\n", (char *)value);
  value = list_find(btree, def_btree_search_func, "13");
  printf("-->%s\n", (char *)value);
  value = list_find(btree, def_btree_search_func, "12");
  printf("-->%s\n", (char *)value);
  value = list_find(btree, def_btree_search_func, "14");
  printf("-->%s\n", (char *)value);


  return 0;
}