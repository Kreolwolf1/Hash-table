#include "../src/btree.c"


int main()
{
  node_t *btree;
  node_t *value;

  btree = list_create("test");

  list_insert(btree, "test1", def_btree_search_func); 

  value = list_find(btree, def_btree_search_func, "test");

  printf("---%s\n", (char *)value);

  return 0;
}