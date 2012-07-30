#ifndef HASH
# define HASH
# ifndef LIST_TYPE
#  define LIST_TYPE 1
# endif
# include "llist.h"
# include "btree.h"
# if (LIST_TYPE == 1)
    typedef node_lt node_t;
# elif (LIST_TYPE == 2)
    typedef node_bt node_t; 
# endif 

typedef struct    hash_s 
{
	int      size;
	node_t   **nodes;
} hash_t;

typedef struct    hashdata_s 
{
  char    *key;
  void    *value;
} hashdata_t;

hashdata_t  *mystrdup(void *value, const char *s);
hash_t      *hash_init(int size);
node_t      *(*create_lb)(void *data);
node_t      *(*insert_lb)(node_t *list, void *data, ...);
node_t      *(*find_lb)(node_t *node, int (*func)(void *,void *), void *data);
void  *hash_get(hash_t *hash, char *key);
int   (*foreach_lb)(node_t *node, int(*func)(void*));
int   (*remove_lb)(node_t *list, node_t *node, ...);
int   (*destroy_lb)(node_t *root);
int   (*foreach_lb)(node_t *root, int(*func)(void*));
int   init_hash_function();
int   def_hash(const char *str, int size);
int		hash_set(hash_t *hash, char *key, void *data);
int		hash_remove(hash_t *hash, char *key);
int		hash_destroy(hash_t *hash);
int		hash_clean(hash_t *hash);
int   find_hash_string(void *listdata, void *searchdata);
int   hash_clean(hash_t *hash); 
int   foreach_for_clean(void *data);





#endif
