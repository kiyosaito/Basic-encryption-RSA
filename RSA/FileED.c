#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
RSA method of encryption and decryption where encryption uses a public key where as decryption uses a private key
*/
int p, q, lambda_n;
long n, e, d;
int primecheck(int n){
    int i;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int totient(int p, int q)
{
    return (p - 1) * (q - 1);
}
int createE(int tn){
    int i;
    for(i=2;i<tn;i++){    
        if(gcd(i,tn)==1){
            return i;
        }
    }
    return -1;
}
int priv(int i, int tn){
    int j;
    for(j=1;j<tn;j++){
        if((j*i)%tn==1){
            return j;
        }
    }
    return -1;
}
long pomod(long a, long b, long m){
    long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = (x * y) % m;
        }
        y = (y * y) % m;
        b /= 2;
    }
    return x%m;
}
void createkeys(){
    printf("\nEnter 2 prime numbers>");
    scanf("%d%d",&p,&q);
    if(primecheck(p)&&primecheck(q)){
        n=(p*q);
        lambda_n=totient(p,q);
        e=createE(lambda_n);
        d=priv(e,lambda_n);
    }
    else{
        printf("non prime numbers were entered");
    }
    
}
char* encrypt(char* content){
    createkeys();
    long i,size=strlen(content);
    char* holder=(char*) malloc(sizeof(char)*(size));
    printf("The public key is: %ld,%ld\nyour private key is: %ld,%ld\n",e,n,d,n);
    for(i=0;i<size;i++){
        holder[i] = pomod(content[i],e,n);
        printf("%c -> %c\n",content[i],holder[i]);
    }
    return holder;
}
char* decrypt(char* content){
    long i,size = strlen(content);
    char* holder = (char*) malloc(sizeof(char)*(size));
    long key1,key2;
    scanf("%ld%ld",&key1,&key2);
    for(i=0;i<size;i++){
        holder[i] = pomod(content[i],key1,key2);
        printf("%c -> %c\n",content[i],holder[i]);
    }
    return holder;
}

