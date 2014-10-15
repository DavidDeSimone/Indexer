#ifndef HASHTABLE_H
#define HASHTABLE_H
#endif

/* HashTable implementation for CS214 
 * 
 * Members:
 *   hash_array: The array hosting the hashed member objects
 *   size: the number of objects in the hashtable
 *   n_buckets: the number of buckets for the hashtable (i.e. the size of hash_array)
 *   *hashFunct(void *): function pointer to the hash function for the generic type pointed to by the members of the hash_array
 *    threshold: if size / n_buckets exceeds this threshold, resize() will be called, and the hashtable will be expanded (and its members rehashed) until size / n_buckets is below the threshold
 */
struct HashTable {

  void *hash_array;
  int size, n_buckets;
  int (*hashFunct)(void *);
  double threshold;
};

typedef struct HashTable HashTablePtr;

HashTablePtr hash_create(double threshold, int n_buckets, int (*hashFunct)(void *));

void hash_destroy(HashTablePtr hash_table);

void resize(HashTablePtr hash_table);
void add(HashTablePtr hash_table, void *to_add);
void remove(HashTablePtr hash_table, void *to_remove);
