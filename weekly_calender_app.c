#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "weekly_calender_app.h"
typedef struct node{
    char todo[5000]; // Activity that user enters
    char activity_day[5000]; //the day of the activity given by the user
    struct node * next;
}node;
struct node * head=NULL;

int weeklycalenderapp() {
    char ch[32]; // I used this code to print the current day, I founded online.
    struct tm *ts;
    size_t last;
    time_t t=time(NULL);
    ts=localtime(&t);
    last=strftime(ch, 32, "%A", ts);
    ch[last] = '\0'; //--end of the copy code
    printf("Welcome to weekly calender, today is %s.\n", ch);
    int n=0;

    printf("How many days you want to see on your calender? \n (Type the number of days which you will have a plan)");
    scanf("%d",&n);
    createList(n,ch);
    displayMyList();

    return 0;
}
void createList(int n,char ch[]){
    int i=0;
    struct node * new_node=NULL;
    struct node * current=NULL; 

    for(i=0; i<n; i++){ //This will create nodes number of n.
        new_node= (node*)malloc(sizeof(node));
        char answer[20];
        char answer2[20];
        if(i==0){
            printf("Do you have anything to write down for today? (yes/no)");
            scanf("%s", &answer);

            if(strcmp (answer,"yes")==0) {
                printf("Type your activity: ");
                scanf("\n%[^\n]", &(new_node->todo));
                strcpy(new_node->activity_day,ch);
                // printf("%s",temp->activity_day);
                n=n-1;

                // head=temp;

            }else{
                strcpy(answer2,answer); //to make "no" answer variable
            }

        }

        strcpy(answer,answer2);//to make "no" answer variable

        int x=1; //to finish the loop
        if(strcmp (answer,"no")==0 || x==1){
            printf("\nChoose a day (exp: Monday): ");
            char day_answer[200];
            scanf("%s", &day_answer);
            strcpy(new_node->activity_day,day_answer);

            if( day_answer[0]>= 'a' && day_answer[0] <= 'z'){
                printf("\nPlease correct your first letter and try again.\n");
                scanf("%s", &day_answer);
                strcpy(new_node->activity_day,day_answer);
                printf("Type your activity: ");
                scanf("\n%[^\n]", &(new_node->todo));

            }else{ //if there is no error about syntax
                printf("\nType your activity: ");
                scanf("\n%[^\n]", &(new_node->todo));
            }
        }
        else {
            //EMPTY
        }

        if(head == NULL){
            head=new_node;
        }else {
            current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = new_node;
        }
    }
}
void displayMyList(){ 
    struct node * current;
    current=head;
    while(current->next != NULL){
        printf("\t%s->%s",current->activity_day,current->todo);
        current=current->next;

    }
    printf("\t%s->%s",current->activity_day,current->todo);
}
