#ifndef HASHTBL_H_INCLUDE_GUARD
# define HASHTBL_H_INCLUDE_GUARD

# include <stdlib.h>

typedef struct    hashnode_s 
{
  struct  data_s	 *data;
  struct  hashnode_s *next;
} hashnode_t;

typedef struct    data_s 
{
  char    *key;
  void    *value;
} data_t;

int   hashtbl_set(const char *key, void *data);
int   hashtbl_remove(const char *key);
void  *hashtbl_get(const char *key);
void  hashtbl_destroy();
static int   def_return_hash(const char *str);

#endif
