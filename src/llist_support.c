static char   *mystrdup(const char *s)
{
  char *b;
  if (!(b = malloc(strlen(s) + 1))) 
    return NULL;

  strcpy(b, s);
  
  return b;
}

static int   def_return_hash(const char *str)  // hash-function                                                                                                                                                                                                               
{                                                                                                                                                                                                                                                                      
  unsigned int    i;                                                                                                                                                                                                                                                    
  unsigned int    hash = 0;                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                    
  for (i = 0; str[i]; i++)                                                                                                                                                                                                                                              
    hash += str[i] * i;                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                       
  return hash % HASHSIZE;                                                                                                                                                                                                                                                 
}