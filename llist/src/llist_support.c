#include "../includes/llist.h"
#include <stdlib.h>
#include <string.h>

static char   *mystrdup(const char *s)
{
  char *b;
  if (!(b = malloc(strlen(s) + 1))) 
    return NULL;

  strcpy(b, s);
  
  return b;
}

node_t	*node_init(const char *key, void *value)
{
	node_t 	*node;

	if (!(node = malloc(sizeof(node_t)))) 
    return NULL;
  if (!(node->data = malloc(sizeof(data_t)))) 
    return NULL;
  if (!(node->data->key = mystrdup(key))) 
  {
  	free(node->data);
    free(node);
    return NULL;
  }
  node->data->value = value;
  return node;
}