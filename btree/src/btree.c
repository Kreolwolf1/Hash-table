#include "../includes/btree.h"
#include "../src/btree_support.c"

node_t  *list_create(void *data)
{
  node_t *node;

  node = malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

node_t *list_insert(node_t *node, void *data, int(*func)(void*,void*))
{
  node_t  *new_node;
  node_t  *previos;
  int compare_result;

  new_node = list_create(data);
  while(node) {
    previos = node;
    compare_result = func(node->data, data);     
    if (compare_result < 0)
      node = node->left;
    else if (compare_result > 0)
      node = node->right;
    else
      break; 
  }
  if (compare_result == 0)
    previos->data = data;
  else 
    if (compare_result > 0)
      previos->right = new_node;
    else
      previos->left = new_node; 
  
  return new_node;
} 


node_t *list_find(node_t *node, int(*func)(void*,void*), void *data)
{
  int compare_result;

  while(node) {
    compare_result = func(node->data, data);     
    if (compare_result < 0)
      node = node->left;
    else 
      if (compare_result > 0)
        node = node->right;
      else
        return node; 
  }

  return NULL;
}

int list_remove(node_t *list, node_t *node, int(*func)(void*,void*))
{
  node_t *parent;
  node_t **buff;
  node_t *last_left;

  parent = list_search(list, node->data, func);
  if (parent->left == node) 
  {
    buff = &parent->left;
  }
  else
  {
    buff = &parent->right;
  }
  if ((node->left == NULL) && (node->right == NULL))
  {
    *buff = NULL;
    free(node);
  }
  else if (node->left == NULL)  
  {
      *buff = node->right;     
      free(node);
  }
  else if (node->right == NULL)  
  {
      *buff = node->left;     
      free(node);
  }
  else
  {
      *buff = node->right;
      last_left = list_left_search(node->right);
      last_left->left = node->left;
      free(node);
  }
  
  return 0;
}
