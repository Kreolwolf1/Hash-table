#ifndef HASH
# define HASH
# include "llist.h"
/* # include "btree.c" */

typedef struct hash_s {
	int      size;
	node_t   **nodes;
} hash_t;

typedef struct    hashdata_s 
{
  char    *key;
  void    *value;
} hashdata_t;

static  hashdata_t  *mystrdup(void *value, const char *s);
static  int  def_return_hash(const char *str, int size);
hash_t  *hash_init(int size);
void  *hash_get(hash_t *hash, char *key);
int		hash_set(hash_t *hash, char *key, void *data);
int		hash_remove(hash_t *hash, char *key);
int		hash_destroy(hash_t *hash);
int		hash_clean(hash_t *hash);
int   find_hash_string(void *listdata, void *searchdata);
int   hash_clean(hash_t *hash); 

#endif
