#ifndef HASH
# define HASH

# include "./../../llist/src/llist.c"

typedef struct hash_s {
	int 			size;
	struct node_s	**nodes;
} hash_t;


typedef struct    hashdata_s 
{
  char    *key;
  void    *value;
} hashdata_t;

hash_t	*hash_init(int size);
int		hash_set(hash_t *hash, char *key, void *data);
void	*hash_get(hash_t *hash, char *key);
int		hash_remove(hash_t *hash, char *key);
int		hash_destroy(hash_t *hash);
int		hash_clean(hash_t *hash);
static	int			def_return_hash(const char *str, int size);
static hashdata_t   *mystrdup(void *value, const char *s);
int 				find_hash_string(void *listdata, void *searchdata); 

#endif
