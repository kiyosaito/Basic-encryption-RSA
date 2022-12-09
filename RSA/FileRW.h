/*
*/
void save(char* content,char* location,long int size);
char* load(char* location,long int* size);
char* contobyte(FILE* fp,long int* size);
long int getSize(FILE* fp);
