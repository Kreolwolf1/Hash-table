#include "../includes/llist.h"
#include "llist_support.c"
#include <stdlib.h>
#include <string.h>

int   llist_set(node_t *llist, const char *key, void *value)
{
  node_t 	*node;

  node = llist;
  while (node)
  {
    if (!strcmp(node->data->key, key))
    {
      node->data->value = value;
      return 0;
    }
    node = node->next;
  }

  node = node_init(key, value);  
  printf(">>node:\n  key:%s\n  value:%s\n", node->data->key, node->data->value);
  node->next = llist;
  llist = node;
  printf(">>llist:\n  key:%s\n  value:%s\n", llist->data->key, llist->data->value);
  
  return 0;
}