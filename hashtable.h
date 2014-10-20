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
 *   *addFunct(void *, void*): Function used to resolve collisions when adding 
 *    to a entry. Used to give user greater control over how collision are handled
 * *createCol(): Create the collider object to handle collision when two hashed objects map to the same bucket.
 *   *contFunct(void *, void *): Function used to see if a collision resolving container (first pointer), contains the object referenced by the second void pointer
 *   *(addCallBack)(void *, void *): Function called when an object already hashed is enterd into the hashtable. First pointer is list of insertion, second is the object itself. 
 *
 *    threshold: if size / n_buckets exceeds this threshold, resize() will be called, and the hashtable will be expanded (and its members rehashed) until size / n_buckets is below the threshold
 */
struct HashTable {

  void *hash_array;
  int size, n_buckets;
  int (*hashFunct)(void *);
  void *(*createColl)();
  void (*addFunct)(void *, void *);
  int (*contFunct)(void *, void *);
  void (*addCallBack)(void *, void *);
  double threshold;
};

typedef struct HashTable HashTablePtr;

HashTablePtr hash_create(double threshold, int n_buckets, int (*hashFunct)(void *),void *(*createColl)(), void (*addFunct)(void *, void *), int (*contFunct)(void *, void *), void (*addcallBack)(void *, void*));

void hash_destroy(HashTablePtr hash_table);
void resize(HashTablePtr hash_table);
void add_hash(HashTablePtr hash_table, void *to_add);
void remove(HashTablePtr hash_table, void *to_remove);
