int findstring(void *listdata, void *searchdata)
{
  return strcmp((char *)listdata, (char *)searchdata)?0:1;
}

int printstring(void *s)
{
  printf("%s\n", (char *)s);
  return 0;
}