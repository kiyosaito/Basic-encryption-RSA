#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileRW.c"
#include "FileED.c"
#include "Main.h"
/* 48430 Fundamentals of C Programming - Assignment 3
    Lab03
    group 6:
        Name: Martin Nguyen
        Student ID: 14166019

        Name: Jarod Phillips
        Student ID: 14298677
    Description:
        This application is used to encrypt and/or decrypt specific files using the RSA encryption method.
    how to use:
    open terminal and type "make run" then follow the prompts to encrypt or decrypt a specfic folder and not something from the home please format it as such "Folder/example.txt"
*/
int main(void){
    use();
    return 0;
}
/*

*/
void use(){ 
    int input=1;
    while(input!=0){
        help();
        scanf("%d",&input);
        switch(input){
            case 1:encryptfile();break;
            case 2:decryptfile();break;
            case 0:break;
            default:help();
        }
    }
    printf("Program exited.\n");
}
void help(){
    printf("\nWelcome to lab03 group 6's cryptography program targetted towards drone imagery\n");
    printf("\n");
    printf("Select one of the options below and press return\n");
    printf("1 - Encrypt File\n2 - Decrypt File\n0 - Exit\nChoice>");
}
void encryptfile(){
    char* infile;
    long int size;
    char location[9999];
    printf("please input location of desired file to be encrypted - example: Folder/ExampleFile.txt>");
    scanf("%s",location);
    infile = load(location,&size);
    infile = encrypt(infile);
    save(infile,location,size);
}
void decryptfile(){
    char* infile;
    long int size;
    char location[9999];
    printf("please enter location of desired file to be decrypted - example: Folder/ExampleFile.txt>");
    scanf("%s",location);
    infile = load(location,&size);
    infile = decrypt(infile);
    save(infile,location,size);
}
