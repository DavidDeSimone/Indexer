#include <stdio.h>
#include "listcoll.h"

int hash(void *to_hash) {

  IndexObjPtr obj_tohash = (IndexObjPtr)to_hash;


}

LinkedIndexObjListPtr create() {

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

void mergesort(void *list) {

  FileIndexListPtr list_tosort = (FileIndexListPtr)list;

}
