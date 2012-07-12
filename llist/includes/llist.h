#ifndef LLIST_H
  #define LLIST_H

	typedef struct    hashnode_s 
	{
	  struct  data_s	 *data;
	  struct  hashnode_s *next;
	} node_t;

	typedef struct    data_s 
	{
	  char    *key;
	  void    *value;
	} data_t;

  node_t 			*node_init(const char *key, void *data);
	int   			llist_set(node_t *llist, const char *key, void *value);
	int   			llist_remove(const char *key);
	void  			*llist_get(const char *key);
	void				llist_destroy();
	static int 	def_return_hash(const char *str);

#endif
