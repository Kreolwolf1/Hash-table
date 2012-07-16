#include "../includes/hash.h"
#include "hash_support.c"

hash_t	*hash_init(int size)
{
	hash_t *hash;
	node_t *nodes_parr[size];

	if(!(hash = malloc(sizeof(hash_t)))) 
		return NULL;

	if(!(hash->nodes=calloc(size, sizeof(struct node_s*)))) {
		free(hash);
		return NULL;
	}

	hash->size = size;
	hash->nodes = nodes_parr;

	return hash;
}

int		hash_set(hash_t *hash, char *key, void *value)
{
	node_t 		*node;
	node_t		*buff_node;
	int 		hash_key; 
	hashdata_t	*data; 

	hash_key = def_hash((char*)key, hash->size);
	node = hash->nodes[hash_key];
	if (node)
	{
		if (buff_node = list_find(node, find_hash_string, key))
		{
			((hashdata_t *)buff_node->data)->value = value;
			return 0;
		}
		buff_node = list_insert(node, mystrdup(value, key));
		buff_node->next = hash->nodes[hash_key];
	}	
	else
	{
		buff_node = list_create(mystrdup(value, key)); 	
	} 
	hash->nodes[hash_key] = buff_node;

	return 0;
}

void	*hash_get(hash_t *hash, char *key)
{
	int 		hash_key; 
	node_t 		*node;

	hash_key = def_hash((char*)key, hash->size);
	node = hash->nodes[hash_key];	
	node = list_find(node, find_hash_string, key);
	if (node)
		return ((hashdata_t *)node->data)->value;
	else
		return NULL;
}

int		hash_remove(hash_t *hash, char *key)
{
	int 		hash_key; 
	node_t 		*list;
	node_t 		*buff_node;

	hash_key = def_hash((char*)key, hash->size);
	list = hash->nodes[hash_key];	
	buff_node = list_find(list, find_hash_string, key);
	if (buff_node)
	{
		free(((hashdata_t *)buff_node->data)->key);
		free((hashdata_t *)buff_node->data);
		list_remove(list, buff_node);

		return 0;
	}
	else
		return -1;
}



