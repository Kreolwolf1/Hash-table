#ifndef BTREE_H
# define BTREE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

  typedef struct node_bs {
    void          *data;
    struct node_bs *left;
    struct node_bs *right;
  } node_bt;

  node_bt  *btree_left_search(node_bt *node);
  node_bt  *btree_create(void *data);
  node_bt  *btree_insert(node_bt *node, void *data, int(*func)(void*,void*), void *key);
  node_bt  *btree_find(node_bt *node, int (*func)(void *,void *), void *data);
  node_bt  *btree_search(node_bt *node, void *data, int(*func)(void*,void*));
  int      btree_remove(node_bt *list, node_bt *node, int(*func)(void*,void*), void *key);
  int      btree_foreach(node_bt *root, int(*func)(void*));
  int      btree_destroy(node_bt *root);
  int      remove_root(node_bt *list);
  int      remove_not_root(node_bt *node, node_bt **buff);
  int      btree_foreach_test(node_bt *root, node_bt *parent, char  *text); 
  int      def_btree_search_func(void *searchdata, void *listdata);

#endif