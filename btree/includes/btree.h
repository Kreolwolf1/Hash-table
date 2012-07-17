#ifndef LLIST_H
# define LLIST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

  typedef struct node_s {
    void          *data;
    struct node_s *left;
    struct node_s *right;
  } node_t;

  node_t  *list_left_search(node_t *node);
  node_t  *list_create(void *data);
  node_t  *list_insert(node_t *node, void *data, int(*func)(void*,void*));
  node_t  *list_insert_after(node_t *node, void *data);
  node_t  *list_find(node_t *node, int (*func)(void *,void *), void *data);
  node_t  *list_search(node_t *node, void *data, int(*func)(void*,void*));
  int     list_remove(node_t *list, node_t *node, int(*func)(void*,void*));
  int     list_foreach(node_t *node, int(*func)(void*));
  int     list_destroy(node_t *list);

#endif