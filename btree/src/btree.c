#include "btree.h"

node_bt      *btree_create(void *data)
{
  node_bt *node;

  node = malloc(sizeof(node_bt));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

node_bt    *btree_insert(node_bt *node, void *data, int(*func)(void*,void*), void *key)
{
  node_bt  *new_node;
  node_bt  *previos;
  node_bt  *root;
  int compare_result;

  root = node;
  new_node = btree_create(data);
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


node_bt    *btree_find(node_bt *node, int(*func)(void*,void*), void *data)
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

int     btree_remove(node_bt *list, node_bt *node, int(*func)(void*,void*), void *key)
{
  node_bt *parent;
  node_bt **buff;
  node_bt *last_left;
  
  if (list == node)
  {
    if (remove_root(list) == 0)
      return 0;
    else
      return -1;  
  }
  parent = btree_search(list, key, func);
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

int     btree_destroy(node_bt *root)
{
  if (root==NULL) 
    return;             

  btree_destroy(root->left);       
  btree_destroy(root->right);      
  free(root);
}

int     btree_foreach(node_bt *root, int(*func)(void*)) 
{
  if (root == NULL) 
    return 0;             
  if (func(root->data) != 0)
    return -1;
  btree_foreach(root->left, func);        
  btree_foreach(root->right, func);      
}

int     btree_foreach_test(node_bt *root, node_bt *parent, char  *text) 
{
  if (root == NULL) 
    return 0;             
  
  printf("-->%s     parent->%s    -->%s\n", (char *)root->data, (char *)parent->data, text);
  parent = root;
  btree_foreach_test(root->left, parent, "L");       
  btree_foreach_test(root->right, parent, "R");      
}