#include "hash.h"

int init_hash_function()
{
  if (LIST_TYPE == 1)
  {
    create_lb = &list_create;
    insert_lb = &list_insert;
    find_lb = &list_find;
    remove_lb = &list_remove;
    destroy_lb = &list_destroy;
    foreach_lb = &list_foreach;
    return 0;
  }
  else if (LIST_TYPE == 2)
  {
    create_lb = &btree_create;
    insert_lb = &btree_insert;
    find_lb = &btree_find;
    remove_lb = &btree_remove;
    destroy_lb = &btree_destroy;
    foreach_lb = &btree_foreach;
    return 0;
  }
  return -1;
}



hashdata_t   *mystrdup(void *value, const char *s)
{
  char *b;
  hashdata_t *data;

  if (!(data = malloc(sizeof(hashdata_t)))) 
    return NULL;
  if (!(b = malloc(strlen(s) + 1))) 
    return NULL;
  strcpy(b, s);
  data->value = value;   
  data->key = b;

  return data;
}

int   def_hash(const char *str, int size)                                                                                                                                                                                                                 
{                                                                                                                                                                                                                                                                      
  unsigned int    i;                                                                                                                                                                                                                                                    
  unsigned int    hash = 0;                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                    
  for (i = 0; str[i]; i++)                                                                                                                                                                                                                                              
    hash += str[i] * i;                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                       
  return hash % size;                                                                                                                                                                                                                                                 
}

int  find_hash_string(void *listdata, void *searchdata)
{
  hashdata_t  *hash_data;

  hash_data = (hashdata_t *)listdata;
  return strcmp((char *)searchdata, hash_data->key);
}

int  foreach_for_clean(void *data)
{
  free( ((hashdata_t *)data)->key );
  free( (hashdata_t *)data );
  return 0;
}
