#include "../src/btree.c"

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
  node_t  *list;

  list = list_create("test");
  list_destroy(list);
  if (list)
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
  node_t  *list;
  node_t  *value;
  node_t  *value_1;

  list = list_create("test");
  list_insert(list, "test2", def_btree_search_func,"test2");
  list_insert(list, "test3", def_btree_search_func,"test3");

  value   = list_find(list, def_btree_search_func,"test2");
  value_1  = list_find(list, def_btree_search_func,"test3");
 
  if ((value->data == "test2") && (value_1->data == "test3"))
  {
    printf("\nTEST FOR set AND get ACTIONS successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR set AND get ACTIONS failed.\nMust return ->value2<- ->value1<-\n");
    printf("But return ->%s<- ->%s<-\n", (char *)value->data, (char *)value->data);
    return -1;
  }
}

int   test_action_remove()
{
  node_t  *list;
  node_t  *value;
  node_t  *value_1;

  list = list_create("test");
  list_insert(list, "test2", def_btree_search_func,"test2");
  
  value = list_find(list, def_btree_search_func,"test");
  value_1 =  list_find(list, def_btree_search_func,"test2");

  list_remove(list, value_1, def_btree_search_func,"test2");
  list_remove(list, value, def_btree_search_func,"test");

  value = list_find(list, def_btree_search_func,"test");
  value_1 =  list_find(list, def_btree_search_func,"test2");
  
  if ((!value) && (!value_1))
  {
    printf("\nTEST FOR remove ACTION successfilly completed\n");
    return 0;
  }
  else
  {
    printf("\nTEST FOR set AND get ACTIONS failed.\nMust return empty value\n");
    printf("But return ->%s<-\n", (char *)value->data);
    return -1;
  }
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
  int  cols = 3;
  void *tests_arr[cols];
  int  faild = 0;
  int  success = 0;
  int  i;
  
  tests_arr[0] = &test_actions_init_set_get;
  tests_arr[1] = &test_actions_init_destroy;
  tests_arr[2] = &test_action_remove; 

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