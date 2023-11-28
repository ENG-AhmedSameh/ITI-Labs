#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void copyString(char * sourceString , char * destinationString);
int main(void){
    char s1[] = {"I'm the original string"},s2[] = {"supposed to be have copy of s1"};
    system("cls");
    printf("Before Copying s1 value in s2 value:\n \ts1= %s \n\ts2= %s",s1,s2);
    copyString(&s1,&s2);
    printf("\nAfter Copying s1 value in s2 value:\n \ts1= %s \n\ts2= %s",s1,s2);

    getch();
    return 0;
}

void copyString(char * sourceString , char * destinationString){
    int i = 0;
    while (sourceString[i] !='\0')
    {
        destinationString[i] = sourceString[i];
        i++;
    }    
    destinationString[i] = '\0';
}