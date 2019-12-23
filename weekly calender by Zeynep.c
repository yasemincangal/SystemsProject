#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    char todo[2000]; // Activity that user enters
    char activity_day[2000]; //the day of the activity given by the user
    struct node * next;
}node;

node * createLinkedList(int n);

void displayList(node* head);

int main() {
    //char day_name[7]={'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'};
    //char todo[200]; //Activity that user enters
    //char todo_list[1000]; //Activity list which user entered.
    //char day_answer[200]; //Day when the user wants to add activity, entered by the user. line:33
    char ch[32]; // I used this code to print the current day, I founded online.
    struct tm *ts;
    size_t last;
    time_t t=time(NULL);
    ts=localtime(&t);
    last=strftime(ch, 32, "%A", ts);
    ch[last] = '\0'; //--end of the copy code
    printf("Welcome to weekly calender, today is %s.\n", ch);

    int n=0;
    node * HEAD=NULL;
    printf("How many days you want to see on your calender? \n (Type the number of days which you will have a plan)");
    scanf("%d",&n);
    HEAD=createLinkedList(n);
    displayList(HEAD);

    return 0;
}
node * createLinkedList(int n){
int i=0;
node * head=NULL;
node * temp=NULL;
node * p=NULL;

for(i=0; i<n; i++){
    temp = (node*)malloc(sizeof(node));
    printf("Do you have anything to write down for today? (yes/no)");
    char answer[20];
    scanf("%s", &answer);
    temp = (node*)malloc(sizeof(node));
    if(strcmp (answer,"yes")==0) {
        printf("\nType your activity: ", i + 1);
        scanf("\n%s", &(temp->todo));
        temp->next = NULL;
    }

    if(strcmp (answer,"no")==0){
        printf("Choose a day (exp: Monday): ");
        char day_answer[200];
        scanf("%s", &day_answer);
        if( day_answer[0]>= 'a' && day_answer[0] <= 'z'){
            printf("Please correct your first letter and try again.");
            scanf("%s", &day_answer);
            printf("\nType your activity: ", i + 1);
            scanf("\n%s", &(temp->todo));
            temp->next = NULL;
        }
    }
    else {
    }



    if(head == NULL){
        head=temp;
    }
    else{
        p=head;
        while(p->next != NULL)
            p=p->next;
        p->next=temp;
    }
}
return head;
}
void displayList(node * head){
    node * p=head;
    while(p->next != NULL){
        printf("\t%s->",p->todo);
        p=p->next;
    }
}