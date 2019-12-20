#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#define FILE_NAME "history_of_terminal.txt" //save history of terminal as a file

int main() {
    FILE *historyfile=fopen(FILE_NAME,"a"); //create a file which stores a history of C-shell terminal
    char *command=malloc(80*sizeof(char));
    char function1[]="history"; //function names will be added when the others has finished
    char function2[]="b";
    char function3[]="c";
    char function4[]="d";
    char history[1000];
    char *command_name=strtok(command," "); //split by spaces the command line
    char *input1=strtok(command," "); //first param
    char *input2=strtok(command," "); //second param
    char *input3=strtok(command," "); //third param
    printf("zeynepyasemin@SystemsProgramming:~$ ");
    scanf("%s",command);
   // strcat(history,command); //concatenation

    if(strcmp(command_name,function1)==0||strcmp(command_name,function2)==0||strcmp(command_name,function3)==0||strcmp(command_name,function4)==0||strcmp(command_name,"exit")==0){
        fprintf(historyfile,"%s\n",command_name); //add that command name into history_of_terminal.txt
    }else{
        printf("That command line is not allowed.\n");
    }


    while(strcmp(command_name,"exit")!=0){ //if user write exit, then finish process

        if(strcmp(command_name,function1)==0){// if input command is history
            //execl will be added
        }








        printf("zeynepyasemin@SystemsProgramming:~$ ");
        scanf("%s",command);

        if(strcmp(command_name,function1)==0||strcmp(command_name,function2)==0||strcmp(command_name,function3)==0||strcmp(command_name,function4)==0||strcmp(command_name,"exit")==0){
            fprintf(historyfile,"%s\n",command_name);  //add that command name into history_of_terminal.txt
        }else{
            printf("That command line is not allowed.\n");
        }


    }


    return 0;
}
