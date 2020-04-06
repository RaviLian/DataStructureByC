#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int countWords();
char* maxStr();


char string[20];

int main() {
    //printf("There are %d words in this line.\n",countWords());
    char *p;
    p = maxStr();
    printf("The max string:\n");
    puts(p);
    return 0;
}

int countWords(){
    char str[MAXSIZE];
    int i,num = 0, word = 0;
    char c;
    gets(str);
    for(i = 0; (c = str[i])!='\0'; i++){
        if(c==' ') word = 0;
        if(c!=' '){
            if(word == 0){
                word = 1;
                num++;
            }
        }
    }
    return num;
}

char* maxStr(){
    char str[3][20];
    int i;
    for(i = 0; i < 3; i++)
        gets(str[i]);
    if(strcmp(str[0],str[1])>0){
        strcpy(string,str[0]);
    } else{
        strcpy(string,str[1]);
    }
    if(strcmp(string,str[2])>0){
        ;
    } else{
        strcpy(string,str[2]);
    }
    return string;
}