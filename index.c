// TODO. The to_write variable could be a directory. And thus to empty it
//We must first delete the contents of the directory. 
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "listcoll.h"
#include "hashtable.h"

//Each File with have an associated HashTable
//Array of HashTables for each file
HashTablePtr *tables;

int main(int argc, char **args) {
  int err = 0;
  char *to_write;
  char *to_read;

  if(argc != 3) {
    printf("Error, incorrect number of command line arguments!\n");
    return -1;
  }

  to_write = args[1];
  to_read = args[2];

  err = checkContents(to_read, to_write);

  if(err != 0) {
    printf("Error, entry entered not a directory!\n");
    return -2;
  }

 
  return 0;
}

/* Checks the file to read. Calls appropriate function  
 * based on function content
 */
void checkContents(char *to_read, char *to_write) {
 
  if(isDir(to_read)) {
    readDir(to_read);
  } else {
    readFile(to_read);
  }

  writeFile(to_write);
}

/* Function used to determine if a pathname is a directory
 * Returns 0 if false, 1 if true
 */
int isDir(char *to_read) {

  struct stat s;
  if( stat(to_read, &s) == 0) {

    if(s.st_mode & S_IFDIR) {
      return 1;
    } else if(s.st_mode & S_IFREG) {
      return 0;
    } else {
      return -2;
    }

  } else {
    return -1;
  }
}

/* Read directory, and for each file in the directory, calls 
 * readFile(). If another directory is found, recursivly calls
 * readDir(). 
 */
void readDir(char *to_read) {

}

/* Reads a file given by to_read. Creates a hashmap for given file.
 * Tokenizes each word of the file. Constructs an wrapper object for the word
 * and hashes it. If a collision occures, occurrence will be raised by collision
 * object. Adds hashmap into hashmap array upon complition. 
 */
void readFile(char *to_read) {

}

void writeFile(char *to_write) {

}

