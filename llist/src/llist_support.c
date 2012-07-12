int findstring(void *listdata, void *searchdata)
{
  return strcmp((char *)listdata, (char *)searchdata)?0:1;
}