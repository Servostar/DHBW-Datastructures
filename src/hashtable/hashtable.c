
#include "hashtable.h"

Hashmap new_hashmap(unsigned int capacity) {
  Hashmap map = {
    .capacity = capacity,
    .keys = (const char**) calloc(sizeof(const char**), capacity),
    .values = (int*) calloc(sizeof(int), capacity)
  };

  return map;
}

void destroy_hashmap(Hashmap *hashmap) {
  if (hashmap->keys != NULL) {
    free(hashmap->keys);
    free(hashmap->values);

    hashmap->keys = NULL;
    hashmap->values = NULL;
    hashmap->capacity = 0;
  }
}

void print_hashmap(Hashmap *hashmap) {
  for (int x = 0; x < hashmap->capacity; x++) {
    printf("%08x (%d)\t| %s\n", hashmap->values[x], hashmap->values[x], hashmap->keys[x]);
  }
}

unsigned int hash(const char *string) {
  const int len = strlen(string);
  
  unsigned int hash = 0;

  for (int x = 0; x < len; x++)
    hash += (hash * 31 + string[x]) / (1 << x) - 1;

  return hash;
}

unsigned int hash2(const char *string) {
  const int len = strlen(string);
  
  unsigned int hash = 0;

  for (int x = 0; x < len; x++)
    hash += (hash * 31 + string[x] + 7) / (1 << x) - 1;

  return hash;
}

#define QUADRADIC_PROBING

unsigned int address_of(Hashmap *hashtable, const char *string) {
  unsigned int bucket = hash(string);

  int iteration = 0;

  do {

    #ifdef LINEAR_PROBING

      bucket = (bucket + 1) % hashtable->capacity;

    #elifdef QUADRADIC_PROBING
  
      bucket = (bucket + iteration * iteration) % hashtable->capacity;
      iteration ++;
  
    #elifdef DOULE_HASHING

      bucket = iteration == 0 ? bucket : (hash(string) + iteration * hash2(string)) % hashtable->capacity;

    #else
    #error *** No collision avoidance method specified ***
    #endif

  } while (hashtable->values[bucket] != 0 && strcmp(hashtable->keys[bucket], string) != 0);

  return bucket;
}

void put(Hashmap *hashtable, const char* string, const int value) {
  unsigned int bucket = address_of(hashtable, string);
  
  hashtable->values[bucket] = value;
  hashtable->keys[bucket] = string;
}

void hashmap_remove(Hashmap *hashtable, const char* string) {
  unsigned int bucket = address_of(hashtable, string);

  if (hashtable->keys[bucket] != NULL) {
    hashtable->keys[bucket] = NULL;
    hashtable->values[bucket] = 0;
  }
}

int get(Hashmap *hashtable, const char* string) {
  unsigned int bucket = address_of(hashtable, string);

  if (hashtable->keys[bucket] != NULL) {
    return hashtable->values[bucket];
  }

  return 0;
}
