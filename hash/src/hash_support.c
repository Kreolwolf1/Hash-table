static hashdata_t   *mystrdup(void *value, const char *s)
{
  char *b;
  hashdata_t *data;

  if (!(data = malloc(sizeof(struct hashdata_s*)))) 
    return NULL;
  if (!(b = malloc(strlen(s) + 1))) 
    return NULL;
  strcpy(b, s);
  data->value = value;   
  data->key = b;

  return data;
}

static int   def_hash(const char *str, int size)  // hash-function                                                                                                                                                                                                               
{                                                                                                                                                                                                                                                                      
  unsigned int    i;                                                                                                                                                                                                                                                    
  unsigned int    hash = 0;                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                    
  for (i = 0; str[i]; i++)                                                                                                                                                                                                                                              
    hash += str[i] * i;                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                       
  return hash % size;                                                                                                                                                                                                                                                 
}

int find_hash_string(void *listdata, void *searchdata)
{
  char *      chtest;
  hashdata_t  *hash_data;

  hash_data = (hashdata_t *)listdata;
    
  return strcmp(hash_data->key, (char *)searchdata)?0:1;
}

int foreach_for_clean(void *data)
{
  
}