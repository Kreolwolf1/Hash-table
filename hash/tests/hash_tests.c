#include "../src/hash.c"

void itoa(int n, char s[])
{
  int i, sign;
 
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
      
}


int   test_actions_init_destroy()
{
  hash_t  *hashtabl;

  hashtabl = hash_init(128);
  hash_destroy(hashtabl);

  if (hashtabl)
  {
    printf("\nTEST FOR init AND destroy ACTIONS successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR init AND destroy ACTIONS failed.\n");
    return -1;
  } 
}  

int   test_actions_init_set_get()
{
  hash_t  *hashtabl;
  void  *value;
  void  *value_1;

  hashtabl = hash_init(128);
  hash_set(hashtabl, "test", "value");
  hash_set(hashtabl, "test1", "value1");
  hash_set(hashtabl, "test", "value2");

  value   = hash_get(hashtabl, "test");
  value_1  = hash_get(hashtabl, "test1");
 
  if ((value == "value2") && (value_1 == "value1"))
  {
    printf("\nTEST FOR set AND get ACTIONS successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR set AND get ACTIONS failed.\nMust return ->value2<- ->value1<-\n");
    printf("But return ->%s<- ->%s<-\n",value?(char *)value:"-", value_1?(char *)value_1:"-");
    return -1;
  }
}

int   test_action_remove()
{
  hash_t  *hashtabl;
  void  *value;

  hashtabl = hash_init(128);
  hash_set(hashtabl, "test", "value");
  hash_remove(hashtabl, "test");
  value = hash_get(hashtabl, "test");
 
  if (!value)
  {
    printf("\nTEST FOR remove ACTION successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR set AND get ACTIONS failed.\nMust return empty value\n");
    printf("But return ->%s<-\n", (char *)value);
    return -1;
  }
}

int   test_action_clean()
{
  hash_t  *hashtabl;
  void  *value;
  void  *value_1;

  hashtabl = hash_init(128);
  hash_set(hashtabl, "test", "value");
  hash_set(hashtabl, "test1", "value1");
  hash_clean(hashtabl);

  value   = hash_get(hashtabl, "test");
  value_1  = hash_get(hashtabl, "test1");
 
  if ((!value) && (!value_1))
  {
    printf("\nTEST FOR clean ACTION successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR clean ACTION failed.\nMust return empty values-\n");
    printf("But return ->%s<- ->%s<-\n",value?(char *)value:"-", value_1?(char *)value_1:"-");
    return 1;
  }
}

int stress_set_get_test()
{
  hash_t  *hashtabl;
  int     i;
  int     cols = 100000;
  char    a[20];
  void    *value;

  hashtabl = hash_init(128);   
  for(i=0; i < cols; ++i) 
  {
    itoa(i, a);
    hash_set(hashtabl, a, a);
  }
  for(i=0; i < cols; ++i) 
  {
    itoa(i, a);
    value = hash_get(hashtabl, a);
    if (!(a == value))
    {  
      printf("\nSTRESS TEST set AND get ACTIONS failed.\nMust return ->%s<-\n", a);
      printf("But return ->%s<-\n",value?(char *)value:"-");
      return -1;    
    }
  }
  printf("\nSTRESS TEST set AND get ACTIONS successfilly completed\n");
  
  return 0;
}


int stress_set_get_remove_test()
{
  hash_t  *hashtabl;
  int     i;
  int     cols = 100000;
  char    a[20];
  void    *value;
  int     fl;

  hashtabl = hash_init(128);   
  for(i=0; i < cols; ++i) 
  {
    itoa(i, a);
    hash_set(hashtabl, a, a);
  }
  
  for(i = 0; i < 500; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }

  for(i = cols/2; i < cols/2 + 500; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }

  for(i = cols - 500; i < cols; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }

  for(i=0; i < cols; ++i) 
  {
    fl = 0;
    itoa(i, a);
    value = hash_get(hashtabl, a);
    
    if (i < 500)
      fl = 1;
    if (i >= cols - 500)
      fl = 1;
    if (( i >= cols/2 ) &&  ( i < (cols/2 + 500) ) )
      fl = 1;

    if ((value && fl) || ( !(a == value) && !fl))
    {  
      printf("\nSTRESS TEST set, get AND remove ACTIONS failed.\nMust return ->%s<-\n", a);
      printf("But return ->%s<-\n",value?(char *)value:"-");
      return -1;    
    }
  }
  printf("\nSTRESS TEST set, get AND remove ACTIONS successfilly completed\n");
  
  return 0;
}


int test_init(int number,int(*func)())
{
  int     resp;
  clock_t t = clock(); 

  resp = func();
  t = clock()-t; 

  return resp;
}

int main()
{
  int  cols = 6;
  void *tests_arr[cols];
  int  faild = 0;
  int  success = 0;
  int  i;
  
  tests_arr[0] = &test_actions_init_set_get;
  tests_arr[1] = &test_action_remove; 
  tests_arr[2] = &test_action_clean;
  tests_arr[3] = &test_actions_init_destroy;
  tests_arr[4] = &stress_set_get_test;
  tests_arr[5] = &stress_set_get_remove_test;
  printf("\n ------ START TASTING hash ------\n");
  
  for(i=0; i < cols; ++i)
  {  
    if (!test_init(i, tests_arr[i]))
      success++;
    else
      faild++;
  }

  printf("\n ------ END TASTING hash ------\n");
  printf("\n completed -> %d \n success -> %d \n faild -> %d \n", i, success, faild);

}