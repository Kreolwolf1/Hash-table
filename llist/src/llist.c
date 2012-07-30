#include "llist.h"

node_lt *list_create(void *data)
{
  node_lt *node;

  if (!(node = malloc(sizeof(node_lt)))) 
    return NULL;
  node->data = data;
  node->next = NULL;
  return node;
}

node_lt *list_insert(node_lt *list, void *data, ...)
{
  node_lt  *newnode;

  newnode = list_create(data);
  newnode->next = list;
  return newnode;
}

node_lt *list_insert_after(node_lt *node, void *data)
{
  node_lt  *newnode;

  newnode = list_create(data);
  newnode->next = node->next;
  node->next = newnode;
  return newnode;
}

node_lt *list_find(node_lt *node, int(*func)(void*,void*), void *data)
{
  while(node) {
    if (func(node->data, data)==0)
      return node;
    node=node->next;
  }
  return NULL;
}

int list_remove(node_lt *list, node_lt *node, ...)
{
  while (list->next && list->next!=node)
    list=list->next;
  if (list->next) {
    list->next=node->next;
    free(node);
    return 0;   
  } 
  else
    return -1;
}


int list_destroy(node_lt *list)
{
  node_lt  *node;

  while (list) {
    node = list;
    list = list->next;
    free(node);
  }

  return 0;
}

int list_foreach(node_lt *node, int(*func)(void*))
{
  while (node) {
    if (func(node->data) != 0)
      return -1;
    node = node->next;
  }
  return 0;
}
