#include <stdio.h>
#include "listcoll.h"

int hash(void *to_hash) {

  IndexObjPtr obj_tohash = (IndexObjPtr)to_hash;

  int hash = 5381;
  int c;

  char *str = obj_tohash->word;

  while(c = *str++) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}

LinkedIndexObjListPtr create() {
  LinkedIndexObjListPtr list = malloc(sizeof(struct LinkedIndexObjList));

  list->front = NULL;
  list->curr_file_name = NULL;


  return list;
}

void add(void *list, void *to_add) {
  
  LinkedIndexObjListPtr list_ptr = (LinkedIndexObjListPtr)list;
  IndexObjPtr obj_toadd = (IndexObjPtr)to_add;

  //If the list is empty
  if(list_ptr->front == NULL) {
    list_ptr = obj_toadd;

    //Create the linked list of files this word belongs to
    FileIndexPtr filein = malloc(sizeof(struct FileIndex));
    
    //Get the current file name from the object
    filein->file_name = obj_toadd->curr_file;
    filein->freq = 1;
    filein->next = NULL;

    //Set the front of the sorted index file list
    //to be our new object
    obj_toadd->file_list->front = filein;

    return;
  } 

  //If the list is not empty
  IndexObjPtr obj = list_ptr->front;

  //Insert at the front of the list
  list_ptr->front = obj_toadd;
  obj_toadd->next = obj;

  //Add is only called when the list does not contain this object
  FileIndexPtr filein = malloc(sizeof(struct FileIndex));

  filein->file_name = obj_toadd->curr_file;
  filein->freq = 1;
  filein->next = NULL;

  obj_toadd->file_list->front = filein;

}

int contains(void *list, void *to_con) {
  LinkedIndexObjListPtr list_ptr = (LinkedIndexObjListPtr)list;
  IndexObjPtr obj_tocon = (IndexObjPtr)to_con;

  if(list_ptr == NULL || obj_tocon == NULL) {
    return 0;
  }

  IndexObjPtr obj = list_ptr->front;
  
  do {
    //Match found!
    //NOTE Make sure newlines aren't present
    //may cause bugs in compare function
    if(strcmp(obj_tocon->word, obj->word) == 0) {
      return 1;
    }
  } while((obj = obj->next) != NULL);
 
  return 0;

}

void addCallBack(void *list, void *collided) {

  LinkedIndexObjListPtr list_ptr = (LinkedIndexObjListptr)list;
  IndexObjPtr obj_coll = (IndexObjPtr)collided;


}

//TODO: Check is this function is responsible for creating
// inital node for file index list
IndexObjPtr create_index(char *name, char *file_name) {
  IndexObjPtr obj = malloc(sizeof(struct IndexObj));

  //Assign name
  obj->word = name;
  
  obj->file_list = malloc(sizeof(struct FileIndexList));
  obj->file_list->front = NULL;

  obj->next = NULL;

  obj->curr_file = file_name;

  return obj;
}
