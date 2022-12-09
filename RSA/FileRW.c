#include <stdio.h>
#include "FileRW.h"
#include <stdlib.h>
/*
 function saves the char array into a sepcified location
*/
void save(char* content,char* location,long int size){
    FILE* fp=NULL;
    fp = fopen(location,"wb");
    if(fp!=NULL){
        fwrite(content,sizeof(char),size,fp);
    }
    fclose(fp);
}
/*
        int i;
        for(i=0;i<size;i++){
            fputc(content[i],fp);
            printf("\r%.2f%% complete",((float)i)/((float)size)*100);
        }
    reads the bytes from specified location and stores in a char array
*/
char* load(char* location,long int* size){
    FILE* fp=NULL;
    long int sizehold;
    char* content;

    fp=fopen(location,"rb");
    if(fp!=NULL){
        fseek(fp, 0, SEEK_END);
        sizehold = ftell(fp);
        rewind(fp);
        content = (char*) malloc(sizeof(char)*(sizehold));
        fread(content,1,sizehold,fp);
        *size = sizehold;
    }
    fclose(fp);
    return content;
}
long int getSize(FILE* fp){
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}
