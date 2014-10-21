// TODO. The to_write variable could be a directory. And thus to empty it
//We must first delete the contents of the directory. 
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "listcoll.h"
#include "index.h"

LinkedIndexObjListPtr list;

int main(int argc, char **args) {
  int err = 0;
  char *to_write;
  char *to_read;

  if(argc != 3) {
    printf("Error, incorrect number of command line arguments!\n");
    return -1;
  }

  to_read = malloc(sizeof(char) * strlen(args[2]) + 1);
  to_write = malloc(sizeof(char) * strlen(args[1]) + 1);

  strcpy(to_write, args[1]);
  strcpy(to_read, args[2]);

  //Initalize LinkedObjList structure
  list = create();


  err = checkContents(to_read, to_write);

  if(err != 0) {
    printf("Error, entry entered not a directory!\n");
    return -2;
  }

  free(to_write);
  free(to_read);
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

  //Read directory
  DIR *dir;
  struct dirent *dent;
  char buff[50];

  strcpy(buffer, to_read);
  
  dir = opendir(buff);
  
  if(dir != NULL) {

    //Look over Dir contents
    while((dent = readdir(dir)) != NULL) {
      if(isDir(dent->d_name)) {
	readDir(dent->d_name);
      } else {
	readFile(dent->d_name);
      }

    }

  }



}


/*
 * Changes all characters in the given string to their lower case versions
 */
char* toLower(char *str) {
  return str;
}


/* Reads a file given by to_read. Creates a hashmap for given file.
 * Tokenizes each word of the file. Constructs an wrapper object for the word
 * and hashes it. If a collision occures, occurrence will be raised by collision
 * object. Adds hashmap into hashmap array upon complition. 
 */
void readFile(char *to_read) {
  FILE *fp;

  //Read in the file
  fp = fopen(to_read, "rt");
  char line[800];

  while(fgets(line, 800, fp) =! NULL) {
    //Tokenize String
    char *token;

    token = strtok(line, " ");

    while(token != NULL) {

      char *toMake = malloc(sizeof(strlen(token)));
      strcpy(toMake, token);

      //Lower the case of the string
      toMake = toLower(toMake);

      //Create Index Obj
      IndexObjPtr obj = create_index(toMake, to_read); 

      //Add Index Obj
      add(list, obj);	

      //Move to next token
      token = strtok(NULL, " ");
    }

  }

  fclose(fp);
}

void writeFile(char *to_write) {

}

