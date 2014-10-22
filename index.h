#ifndef INDEX_H
#define INDEX_H
#endif

void checkContents(char *to_read, char *to_write);
int isDir(char *to_read);
void readDir(char *to_read);
char* toLower(char *str);
void readFile(char *to_read);
void writeFile(char *to_write);
char* apdir(char *base, char* to_append);
void writeList(LinkedIndexObjListPtr list, char *fp);
