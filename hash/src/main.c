#include "hash.c"


int main()
{
	hash_t 	*hashtabl;
	void 	*value;
	void	*value1;

	hashtabl = hash_init(128);
	
	hash_set(hashtabl, "test", "value1");
  hash_set(hashtabl, "test1", "value1qwe");
	hash_set(hashtabl, "test", "value12");
	value1 = hash_get(hashtabl, "test");
  printf("%s\n", value1?value1:"...");
  value1 = hash_get(hashtabl, "test1");
  printf("%s\n", value1?value1:"...");

  hash_remove(hashtabl,"testq");

  value1 = hash_get(hashtabl, "test");
  printf("%s\n", value1?value1:"...");
  value1 = hash_get(hashtabl, "test1");
  printf("%s\n", value1?value1:"...");


//	hash_set(hashtabl, "test4", "value12");



//	hash_set(hashtabl, "test", "value1");

//	value = hash_get(hashtabl, "test");
//	printf("-->%s\n", (char *)value);
//	hash_remove(hashtabl, "test");
//	value1 = hash_get(hashtabl, "test");
//	printf("-->%s\n", (char *)value);

}