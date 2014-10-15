#ifndef LISTCOLL_H
#define LISTCOLL_H
#endif

/*
 * Object used for counting frequency for a word in a document
 * file_name: the name of the file the word is contained in
 * freq: the frequnecy of the word
 * next: the next file in the linked list
 */
struct FileIndexList {
  char *file_name;
  int freq;
  FileIndexList *next;
};

typedef struct FileIndexList* FileIndexListPtr;

/* Object for an indexed word in the document.
 * word: the word itself
 * FileIndexListPtr: pointer to the FileIndexList, the list of files and the number of occurences the word has in each file
 * next: the next object in the linked list
 */
struct IndexObj {
  char *word;
  FileIndexListPtr file_list;
  indexObj *next;

};

typedef struct IndexObj* IndexObjPtr;

/*
 * Data Strucuture to handle collision in a linked list enviroment
 * Structure in this case is NOT generic, and is made for the context of 
 * handling word:document frequency
 *
 * To assist in easy adding during the addCallBack function, the linked list 
 * will be supplied with a "current file" string. This string represents what file to add frequency to in the add callback. 
 */

struct LinkedIndexObjList {
  IndexObjPtr front;
  char *curr_file_name;
};

typedef struct LinkedIndexObjList* LinkedIndexObjListPtr;

int hash(IndexObjPtr to_hash);
void add(LinkedIndexObjListPtr list, IndexObjPtr to_add);
int contains(LinkedIndexObjListPtr list, IndexObjPtr to_con);
void addCallBack(LinkedIndexObjListPtr list, IndexObjPtr collided);
