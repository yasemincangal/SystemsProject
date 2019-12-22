#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "/home/yasemin/deneme1/history_of_terminal.txt" //save history of terminal as a file

int main(void) {
char command_[80]; //linux didn't accept pointer even with malloc
char *command;
command=command_;
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
//printf("-%s-",command);
FILE *historyfile=fopen(FILE_NAME,"a");
    if(strcmp(command_name,function1)==0||strcmp(command_name,function2)==0||strcmp(command_name,function3)==0||strcmp(command_name,function4)==0||strcmp(command_name,"exit")==0){
        fprintf(historyfile,"%s\n",command_name); //add that command name into history_of_terminal.txt
    }else{
        printf("That command line is not allowed.\n");
    }

fclose(historyfile);
    while(strcmp(command_name,"exit")!=0){ //if user write exit, then finish process
        historyfile=fopen(FILE_NAME,"a"); //create a file which stores a history of C-shell terminal
        if(strcmp(command_name,function1)==0){// if input command is history
           system("./history.sh /home/yasemin/deneme1/history_of_terminal.txt"); //execution of history shell program

        }








        printf("zeynepyasemin@SystemsProgramming:~$ ");
        scanf("%s",command);

        if(strcmp(command_name,function1)==0||strcmp(command_name,function2)==0||strcmp(command_name,function3)==0||strcmp(command_name,function4)==0||strcmp(command_name,"exit")==0){
            fprintf(historyfile,"%s\n",command_name);  //add that command name into history_of_terminal.txt
        }else{
            printf("That command line is not allowed.\n");
            // strcat(history,command); //concatenation
        }

fclose(historyfile);
    }

 
    return 0;
}
