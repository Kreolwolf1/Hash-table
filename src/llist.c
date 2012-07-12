#include "../includes/llist.h"
#include <string.h>
#include <stdio.h>
#include "llist_support.c"

void   hashtbl_destroy()
{
  struct hashnode_s *node, *oldnode;
  unsigned int      n;

  for(n = 0; n < HASHSIZE; ++n) 
  {
    node = nodes[n];
    while(node) 
    {
      free(node->data->key);
      free(node->data);
      oldnode = node;
      node = node->next;
      free(oldnode);
    }
    nodes[n] = 0;
  }
}

int   hashtbl_set(const char *key, void *data)
{
  struct  hashnode_s *node;
  int     hash = def_return_hash(key);

  node = nodes[hash];
  while (node)
  {
    if (!strcmp(node->data->key, key))
    {
      node->data->value = data;
      return 0;
    }
    node = node->next;
  }

  if (!(node = malloc(sizeof(struct hashnode_s)))) 
    return -1;

  if (!(node->data = malloc(sizeof(struct data_s)))) 
    return -1;
  
  if (!(node->data->key = mystrdup(key))) 
  {
    free(node);
    return -1;
  }
  
  node->data->value = data;
  node->next = nodes[hash];
  nodes[hash] = node;

  return 0;
}

int   hashtbl_remove(const char *key)
{
  struct  hashnode_s *node, *prevnode=NULL;
  int     hash = def_return_hash(key);

  node = nodes[hash];
  while (node)
  {
    if (!strcmp(node->data->key, key))
    {
      free(node->data->key);
      
      if (prevnode) 
        prevnode->next = node->next;
      else
        nodes[hash] = node->next;
      
      free(node);
      
      return 0;
    }
    
    prevnode = node;
    node = node->next;
  }

  return -1;
}

void    *hashtbl_get(const char *key)
{
  struct  hashnode_s *node;
  int     hash;
 
  hash = def_return_hash(key);
  node = nodes[hash];
  while(node)
  {
    if(!strcmp(node->data->key, key)) 
      return node->data->value;
    node = node->next;
  }

  return NULL;
}
