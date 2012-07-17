int     def_btree_search_func(void *searchdata, void *listdata)
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