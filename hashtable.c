/* Hash Table implemenation for C
 * hashing function being djb2 by Dan Bernstein.
 */

#include "hashtable.h"

/*
 *
 *
 */
HashTablePtr hash_create(double threshold, int n_buckets, int (*hashFunct)(void *), void (*addFunct)(void *, void *), int (*contFunct)(void *, void*), void (*addCallBack)(void *, void*)) {

  //Carve memory for the hashtable
  HashTablePtr table = malloc(sizeof(HashTablePtr));

  //Carve memory for the inital array
  table->hash_array = malloc(sizeof(void *) * n_buckets);

  table->size = 0;

  //Set the hashing function
  table->hashFunct = hashFunct;

  //Set the adding function for collision resolving
  table->addFunct = addFunct;

  //Set the function for determining if the collision structure contains 
  //the given object
  table->contFunct = contFunct;

  //Set the add callback. The add callback is called when add() is called
  // on an object already in the table

  table->threshold = threshold;

  return table;
}

/*
 * Destructor function for given hash table. Destroys the array
 * storing the object, and the table struct itself
 */
void hash_destroy(HashTablePtr hash_table) {
  free(hash_table->hash_array);
  free(hash_table);
}

void resize(HashTablePtr hash_table) {


}


/*
 * Function used to add a object to the hashtable
 *
 */
void add(HashTablePtr hash_table, void *to_add) {

  int hash = hash_table->hashFunct(to_add);
  int bucket = hash % hash_table->n_buckets;

  //Object used to handle hash collision
  void *coll_obj = hash_table->hash_array[bucket];
  
  //If the object is contained in the hash table
  if(hash_table->contFunct(coll_obj, to_add)) {
    //Call the callback function for this list
    hash_table->addCallBack(coll_obj, to_add));   
  } else {
    //Add the item to the resolver list
    hash_table->addFunct(coll_obj, to_add);
  }

}

void remove(HashTablePtr hash_table, void *to_remove) {


}




