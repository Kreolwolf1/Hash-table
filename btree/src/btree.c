#include "btree.h"

node_t      *list_create(void *data)
{
  node_t *node;

  node = malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

node_t    *list_insert(node_t *node, void *data, int(*func)(void*,void*), void *key)
{
  node_t  *new_node;
  node_t  *previos;
  node_t  *root;
  int compare_result;

  root = node;
  new_node = list_create(data);
  while(root) {
    previos = root;
    compare_result = func(root->data, key);     
    if (compare_result < 0)
      root = root->left;
    else if (compare_result > 0)
      root = root->right;
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
  
  return node;
} 


node_t    *list_find(node_t *node, int(*func)(void*,void*), void *data)
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

int     list_remove(node_t *list, node_t *node, int(*func)(void*,void*), void *key)
{
  node_t *parent;
  node_t **buff;
  node_t *last_left;
  
  if (list == node)
  {
    if (remove_root(list) == 0)
      return 0;
    else
      return -1;  
  }
  parent = list_search(list, key, func);
  if (parent->left == node) 
  {
    buff = &parent->left; 
  }
  else 
  {
    buff = &parent->right;
  }
  
  remove_not_root(node, buff);
  
  return 0;
}

int     list_destroy(node_t *root)
{
  if (root==NULL) 
    return;             

  list_destroy(root->left);       
  list_destroy(root->right);      
  free(root);
}

int     list_foreach(node_t *root, int(*func)(void*)) 
{
  if (root == NULL) 
    return 0;             
  if (func(root->data) != 0)
    return -1;
  list_foreach(root->left, func);        
  list_foreach(root->right, func);      
}

int     list_foreach_test(node_t *root, node_t *parent, char  *text) 
{
  if (root == NULL) 
    return 0;             
  
  printf("-->%s     parent->%s    -->%s\n", (char *)root->data, (char *)parent->data, text);
  parent = root;
  list_foreach_test(root->left, parent, "L");       
  list_foreach_test(root->right, parent, "R");      
}