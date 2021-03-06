#include "hash.h"

hash_t  *hash_init(int size)
{
  hash_t *hash;

  init_hash_function();
  if(!(hash = malloc(sizeof(hash_t)))) 
    return NULL;
  if(!(hash->nodes = calloc(size, sizeof(node_t*)))) {
    free(hash);
    return NULL;
  }
  hash->size = size;

  return  hash;
}

int   hash_set(hash_t *hash, char *key, void *value)
{
  node_t      *node;
  node_t      *buff_node;
  int         hash_key; 

  hash_key = def_hash((char*)key, hash->size);
  node = hash->nodes[hash_key];
  if (node)
  {
    buff_node = find_lb(node, find_hash_string, key);
    if (buff_node)
    {
      ((hashdata_t *)buff_node->data)->value = value;
      return 0;
    }
    buff_node = insert_lb(node, mystrdup(value, key), find_hash_string, key);
  } 
  else
  {
    buff_node = create_lb(mystrdup(value, key));  
  } 
  hash->nodes[hash_key] = buff_node;

  return 0;
}

void  *hash_get(hash_t *hash, char *key)
{
  int     hash_key; 
  node_t    *node;

  hash_key = def_hash((char *)key, hash->size);
  node = hash->nodes[hash_key];
  node = find_lb(node, find_hash_string, key);  
  if (node)
  {
    return ((hashdata_t *)node->data)->value;
  }
  else
  {
    return NULL;
  }
}

int   hash_remove(hash_t *hash, char *key)
{
  int       hash_key; 
  node_t    *node;
  node_t    *buff_node;

  hash_key = def_hash((char*)key, hash->size);
  node = hash->nodes[hash_key]; 
  buff_node = find_lb(node, find_hash_string, key);
  if (buff_node)
  {
    free(((hashdata_t *)buff_node->data)->key);
    free((hashdata_t *)buff_node->data);
    if  (remove_lb(node, buff_node, find_hash_string, key) < 0)
    {   
       hash->nodes[hash_key] = NULL;
    }
    return 0;
  }
  else
  {
    return -1;
  }
}


int   hash_clean(hash_t *hash)
{
  int i;
  
  for(i=0; i < hash->size; ++i)
  {
    if (hash->nodes[i])
    {
      foreach_lb(hash->nodes[i], foreach_for_clean);
      destroy_lb(hash->nodes[i]);
      hash->nodes[i] = NULL;  
    } 
  }

  return 0;
}

int   hash_destroy(hash_t *hash)
{
  hash_clean(hash);
  free(hash->nodes);
  free(hash);

  return 0;   
}