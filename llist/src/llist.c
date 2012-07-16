#include "../includes/llist.h"

node_t *list_create(void *data)
{
  node_t *node;

  if (!(node = malloc(sizeof(node_t)))) 
    return NULL;
  node->data = data;
  node->next = NULL;
  return node;
}

node_t *list_insert(node_t *list, void *data)
{
  node_t  *newnode;

  newnode = list_create(data);
  newnode->next = list;
  return newnode;
}

node_t *list_insert_after(node_t *node, void *data)
{
  node_t  *newnode;

  newnode = list_create(data);
  newnode->next = node->next;
  node->next = newnode;
  return newnode;
}

node_t *list_find(node_t *node, int(*func)(void*,void*), void *data)
{
  while(node) {
    if (func(node->data, data)>0)
      return node;
    node=node->next;
  }
  return NULL;
}

int list_remove(node_t *list, node_t *node)
{

  if ((list == node))
  {
    if (list->next == NULL)
      free(node);
    else
      list->next = node->next;
    return 0;
  }
  while (list->next && list->next != node)
    list=list->next;
  if (list->next) 
  {
    list->next=node->next;
    free(node);
    return 0;   
  } 
  else
  {
    if ((list == node))
    {
      free(node);
      return 0;
    }
    return -1;
  }
}

int list_destroy(node_t *list)
{
  node_t  *node;

  while (list) {
    node = list;
    list = list->next;
    free(node);
  }

  return 0;
}

int list_foreach(node_t *node, int(*func)(void*))
{
  while (node) {
    if (func(node->data) != 0)
      return -1;
    node = node->next;
  }
  return 0;
}