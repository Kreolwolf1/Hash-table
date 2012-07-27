#define  COLSTESTS 6
#include "hash.h"

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
    printf("\nTEST FOR init AND destroy ACTIONS successfully completed\n");
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
  char  *def_value;
  char  *def_value1;

  def_value = "value2";
  def_value1 = "value1";
  hashtabl = hash_init(128);
  hash_set(hashtabl, "test", "value");
  hash_set(hashtabl, "test1", "value1");
  hash_set(hashtabl, "test", "value2");

  value   = hash_get(hashtabl, "test");
  value_1  = hash_get(hashtabl, "test1");
  
  hash_destroy(hashtabl);

  if (((char *)value == def_value) && ((char *)value_1 == def_value1))
  {
    printf("\nTEST FOR set AND get ACTIONS successfully completed\n");
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
  hash_destroy(hashtabl);
  if (!value)
  {
    printf("\nTEST FOR remove ACTION successfully completed\n");
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
 
  hash_destroy(hashtabl);

  if ((!value) && (!value_1))
  {
    printf("\nTEST FOR clean ACTION successfully completed\n");
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
  int     cols = 10000;
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
      hash_destroy(hashtabl);
      return -1;    
    }
  }
  printf("\nSTRESS TEST set AND get ACTIONS successfully completed\n");
  hash_destroy(hashtabl);
  return 0;
}


int stress_set_get_remove_test()
{
  hash_t  *hashtabl;
  int     i;
  int     cols = 5000;
  char    a[20];
  void    *value;
  int     fl;

  hashtabl = hash_init(500);   
  for(i= 0; i < cols; ++i) 
  {
    itoa(i, a);
    hash_set(hashtabl, a, a);
  }


  for(i = 0; i <100 ; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }
  
  for(i = 1000; i < 1100; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }
  
  for(i = 4990; i < 5000; ++i) 
  {
    itoa(i, a);
    hash_remove(hashtabl, a);
  }
  
  
  for(i = 1000; i < 5000; ++i) 
  {
    fl = 0;
    itoa(i, a);

    value = hash_get(hashtabl, a);
    
    if (i < 100)
      fl = 1;
    if (i >= 4990)
      fl = 1;
    if (( i >= 1000 ) &&  ( i < 1100 ) )
      fl = 1;

    if ((value && fl) || ( !(a == value) && !fl)) 
    {  
      printf("\nSTRESS TEST set, get AND remove ACTIONS failed.\nMust return ->%s<-\n", a);
      printf("But return ->%s<-\n",value?(char *)value:"-");
      hash_destroy(hashtabl);
      return -1;    
    }
  }
  printf("\nSTRESS TEST set, get AND remove ACTIONS successfully completed\n");
  
  hash_destroy(hashtabl);
  return 0;
}


int main()
{
  typedef int (*p_func)();
  p_func  tests_arr[COLSTESTS];
  int     faild = 0;
  int     success = 0;
  int     i;
  
  tests_arr[0] = (p_func)&test_actions_init_set_get;
  tests_arr[1] = (p_func)&test_action_remove; 
  tests_arr[2] = (p_func)&test_action_clean;
  tests_arr[3] = (p_func)&test_actions_init_destroy;
  tests_arr[4] = (p_func)&stress_set_get_test;
  tests_arr[5] = (p_func)&stress_set_get_remove_test;
  printf("\n ------ START TESTING hash ------\n");
  
  for(i=0; i < COLSTESTS; ++i)
  {  
    if (tests_arr[i]())
      faild++;
    else
      success++;
  }
  
  printf("\n ------ END TESTING hash ------\n");
  printf("\n completed -> %d \n success -> %d \n failed -> %d \n", i, success, faild);

  return 0;
}