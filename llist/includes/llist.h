#ifndef LLIST_H
# define LLIST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

	typedef struct node_ls {
		void            *data;
		struct  node_ls  *next;	
	} node_lt;

  node_lt 	*list_create(void *data);
  node_lt 	*list_insert(node_lt *list, void *data, ...);
  node_lt  *list_insert_after(node_lt *node, void *data);
  node_lt 	*list_find(node_lt *node, int (*func)(void *,void *), void *data);
  int 		list_remove(node_lt *list, node_lt *node, ...);
  int 		list_foreach(node_lt *node, int(*func)(void*));
  int     list_destroy(node_lt *list);
  int     findstring(void *listdata, void *searchdata);
  int     printstring(void *s);

#endif
