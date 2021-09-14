#include<stdio.h>
#include<string.h>
#include <unistd.h>
int main(){
char *command;
char *token;
char *Token[50];
int count=-1;
printf("Enter the command: ");
scanf(command);
token=strtok(command, " ");
while(token!=NULL){
count=count+1;
Token[count]=strtok(command, " ");
}
execvp(Token[0], Token);
}
