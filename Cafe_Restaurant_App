#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "points_of_places.txt"

struct Node{ //every node has name, point, next and previous one
    float point;
    int line; //in folder //might be deleted maybe
    int index;//at linkedlist
    struct Node* next;
    struct Node* prev;
    char place[20]; //name of place
};

void push(int index,char * name);
void give_Point(float point, char *name);
void toString_Node(struct Node *cur_node);
void printlist();

struct Node * head=NULL;

int main() {
FILE *input_file=NULL ;
FILE *points_of_places=fopen(FILE_NAME,"w"); //create a file

input_file=fopen("C:\\Users\\hp\\CLionProjects\\restaurant_cafe_scoring\\cafe_restaurant.txt","r"); //writing and reading opened with file

if(input_file==NULL){//if there is no such like that folder
    printf("File is not found!!");
    return 1;
}

    char line[20];
    line[sizeof(line)-1]='\0';
    int index=0;
    while(fgets(line, sizeof(line),input_file)!=NULL){
        char *name=malloc(20*sizeof(char));
        //puts(line);
        memcpy(name, line, sizeof(line));
        //printf("%s",x); //output of file
       // printf("index:  %d, name: %s",index,name);
        push(index,name);
        //printf("%s\n",name);
        index++;
    }
    printlist();
    int choice;
    printf("Give point type 1\nSee recommended places type 2 \n"
           "See all places with points within txt file type 3 \nSee points are sorted with places list type 4 \n"
           "See all places in alphabetical order type 5 \n");
    scanf("%d",&choice); // take point interval, or choose fav. place then it will show next and prev.


    if(choice==1){
        printlist();
        char* where;
        float givepoint;
        printf("Where? ");
        scanf( "%s", &where);
        printf("Give points max:5.0 min :0.0 ");
        scanf("%f",&givepoint);
        if(givepoint<=5.0 && givepoint>=0.0 )
             give_Point(givepoint,where);
        else
            printf("Point interval is max:5.0 min :0.0, give number again %f",&givepoint);
        printlist();
    }







fclose(points_of_places);
fclose(input_file);
    return 0;
}

void push(int index,char *name){  //add new node to end of the linkedlist
   struct Node *new_node=(struct Node *) malloc(sizeof(struct Node)); //allocate memory for new node;
   struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));

    new_node->index=index;
    strcpy(new_node->place,name);
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL){
        head=new_node; //create linkedlist by starting from head if there is no one

    }else{
        cur_node=head; //start from head

        while(cur_node->next!=NULL){  //go till end
            cur_node=cur_node->next;

        }
        cur_node->next=new_node;//add end of the list
        new_node->prev=cur_node;
    }

   // printf("Node : index:%d place:%s point:%f \n",cur_node->index,cur_node->place,cur_node->point);
}
void give_Point(float point, char *name){
    struct Node *cur_node;
    cur_node=head;
    while(1){
        cur_node=cur_node->next;
        if(strcmp(cur_node->place,name)==0)
            cur_node->point=point;
            break;
    }

}
void printlist(){ //by travelling in linkedlist
    struct Node *cur_node;
    cur_node=head;
    while(cur_node->next!=NULL){
        toString_Node(cur_node); //call toString function
        cur_node=cur_node->next;
    }
}

void toString_Node(struct Node *cur_node){ //prints every property of struct except line for now
   printf("Node : index:%d place:%s point:%f \n",cur_node->index,cur_node->place,cur_node->point);

}
