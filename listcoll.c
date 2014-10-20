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


  





}

int contains(void *list, void *to_con) {
  LinkedIndexObjListPtr list_ptr = (LinkedIndexObjListPtr)list;
  IndexObjPtr obj_tocon = (IndexObjPtr)to_con;

}

void addCallBack(void *list, void *collided) {

  LinkedIndexObjListPtr list_ptr = (LinkedIndexObjListptr)list;
  IndexObjPtr obj_coll = (IndexObjPtr)collided;


}


IndexObjPtr create_index(char *name, char *filename) {



}
