#include "object.h"

#include <malloc.h>
#include <string.h>
#include <assert.h>

struct Object
{
  char* tag;
};

Object* objectConstruct(char const* tag)
{
  Object* ret = calloc(1, sizeof *ret);
  ret->tag = calloc(strlen(tag)+1, sizeof(char));
  strcpy(ret->tag, tag);
  return ret;
}

char const* objectGetTag(Object const* obj)
{
  assert(obj);
  return obj->tag;
}

void objectDestruct(Object* obj)
{
  if(!obj)
    return;
  free(obj->tag);
  free(obj);
}
