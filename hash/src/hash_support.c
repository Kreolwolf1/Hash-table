#include "hash.h"

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
