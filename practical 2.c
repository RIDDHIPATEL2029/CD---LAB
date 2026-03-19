#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
int main(){
charstr[100]; 
int i=0;
intvowels=0,consonant=0,digit=0,symbols=0,spaces=0; 
FILE *fp;
char ch;
fp = fopen("input.txt", "r"); 
if (fp == NULL)
{
printf("File not opened "); 
exit(1);
}
ch = fgetc(fp); 
printf("Yourstring is:\
n"); while (!feof(fp))
{
str[i++]=ch; 
ch = 
fgetc(fp);
Faculty of Engineering & Technology
Subject Name: Compiler Design (303105350) 
B.Tech : CSE, Year : 3,Semester : 6
Enrollment No : 2303031250155 23
}
str[i]='\0';
printf("%s",str); 
fclose(fp);
for(i=0;str[i]!='\0';i++)
{
if(str[i]=='a' ||str[i]=='A' ||str[i]=='e' ||str[i]=='E' ||str[i]=='i' ||str[i]=='I' ||str[i]=='o' || 
str[i]=='O' || str[i]=='u' || str[i]=='U'){
vowels++;
}
else if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
{
consonant++;
}
else if(str[i]>='0' &&
str[i]<='9'){ digit++;
}
else if (str[i]==' ')
{
}
else{
}
}
spaces++;
symbols++;
Faculty of Engineering & Technology
Subject Name: Compiler Design (303105350) 
B.Tech : CSE, Year : 3,Semester : 6
Enrollment No : 2303031250155 23
printf("\nVowels : %d",vowels); printf("\
nConsonant : %d",consonant); printf("\nDigit :
%d",digit); printf("\nSpecialSymbols :
%d",symbols); printf("\nWhite spaces: %d", 
spaces);
return 0;
}