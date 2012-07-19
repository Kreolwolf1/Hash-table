int       def_btree_search_func(void *searchdata, void *listdata)
{
  return strcmp((char *)listdata, (char *)searchdata);
}

node_t    *list_search(node_t *node, void *data, int(*func)(void*,void*))
{
  node_t  *previos = node;
  int     compare_result;
  
  while(node) {
    compare_result = func(node->data, data);     
    if (compare_result < 0)
    {
      previos = node;
      node = node->left;
    }
    else if (compare_result > 0)
    {  
      previos = node;
      node = node->right;
    }
    else
      break; 
  }

  return previos;
}

node_t    *list_left_search(node_t *node)
{
  node_t *parent;

  while(node)
  {
    parent = node;
    node = node->left;

  }
  return parent;
}

int     remove_root(node_t *list)
{
  node_t *last_left;

  if ((list->left == NULL) && (list->left == NULL))
  {
    free(list);
    return -1;
  }
  else if (list->left == NULL)
  {
    *list = *list->right;
  } 
  else if (list->right == NULL)
  {
    *list = *list->left;
  }
  else
  {
    last_left = list_left_search(list->right);
    last_left->left = list->left;
    *list = *list->right;
  }

  return 0;
}

int     remove_not_root(node_t *node, node_t **buff)
{
  node_t *last_left;

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
}
