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
    char *name_place;

};
struct Node * head=NULL;
void push(int index,char * name);
int getSize();
void toString_Node(struct Node *cur_node);
void printlist();
void print_into_txt_with_points(FILE *points_of_places);
void give_Point(float point,char *name,int size);
char * remove_new_line_from_string(char *arr);
int main() {
    FILE *input_file=NULL ;
    FILE *points_of_places=fopen(FILE_NAME,"a"); //create a file

    input_file=fopen("C:\\Users\\hp\\CLionProjects\\restaurant_cafe_scoring\\cafe_restaurant.txt","r"); //writing and reading opened with file

    if(input_file==NULL){//if there is no such like that folder
        printf("File is not found!!");
        return 1;
    }

    char line[20];
    line[sizeof(line)-1]='\0';
    int index=0;
    while(fgets(line, sizeof(line),input_file)!=NULL){
        char *name=malloc(80*sizeof(char));
        //puts(line);
        memcpy(name, line, sizeof(line));
        //printf("%s",x); //output of file
        // printf("index:  %d, name: %s",index,name);
        int length=strlen(name);
        if(length>0)
            name[length-1]='\0'; //to get rid of from '\n' char
        push(index,name);
        //printf("%s\n",name);
        index++;
    }
    printlist();
    int choice;
    printf("Give point type 1\nSee recommended places type 2 \n"
           "See all places with points within txt file type 3 \nSee points are sorted with places list type 4 \n"
           "See all places in alphabetical order type 5 \nTo exit type 6\n");
    scanf("%d",&choice); // take point interval, or choose fav. place then it will show next and prev.

while(choice!=6 ){ //ask again till user wants to exit
    if(choice==1){
        printlist();
        char* where=malloc(20*sizeof(char));
        float givepoint;
        printf("Where? ");
        scanf( "%s", where);
        // char n='\n'; //added new line to be equal like in txt file, read from line by line
        //strncat(where,&n,1); //string conc.
        printf("Give points max:5.0 min :0.0 ");
        scanf("%f",&givepoint);
        int size=getSize(); //linkedlist current size (flexible)
        //printf("%d",size);
        if(givepoint<=5.0 && givepoint>=0.0 ){
            give_Point(givepoint,where,size);
        }else{
            printf("Point interval is max:5.0 min :0.0, give number again %f",&givepoint);
            give_Point(givepoint,where,size);
        }

        print_into_txt_with_points(points_of_places);

    }
    printf("Give point type 1\nSee recommended places type 2 \n"
           "See all places with points within txt file type 3 \nSee points are sorted with places list type 4 \n"
           "See all places in alphabetical order type 5 \nTo exit type 6");
    scanf("%d",&choice); // take point interval, or choose fav. place then it will show next and prev.
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
void give_Point(float point,char *name,int size){
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));

    cur_node=head;


    for(int i=0;i<size;i++){

        if(strcmp(cur_node->place,name)==0){
            cur_node->point=point;

            printf("%s is this :%f",cur_node->place,cur_node->point);
            break;
        }
        printf("\n%s is :%f\n",cur_node->place,cur_node->point);
        //printf("%d ----- %d\n",sizeof(place), sizeof(name));
            if(i!=(size-1)) //if there is no such a restaurant or cafe like that
            cur_node=cur_node->next;

        if(i==(size-1))// name couldn't found
            printf("Place name is wrong");


    }

}

void printlist(){ //by travelling in linkedlist
    struct Node *cur_node;
    cur_node=head;
    while(cur_node->next!=NULL){
        toString_Node(cur_node); //call toString function
        cur_node=cur_node->next;
    }
    toString_Node(cur_node);//last node to print too
}
void print_into_txt_with_points(FILE *points_of_places){
    struct Node *cur_node;
    cur_node=head;
    points_of_places=fopen(FILE_NAME,"w");//clear all content of txt file at first when the program executed again
    while(cur_node->next!=NULL){

        fprintf(points_of_places,"place:%s point:%f\n",cur_node->place,cur_node->point);
        cur_node=cur_node->next;

    }
    fprintf(points_of_places,"place:%s point:%f\n",cur_node->place,cur_node->point); //last node to print too
}
void toString_Node(struct Node *cur_node){ //prints every property of struct except line for now
    printf("Node : index:%d place:%s point:%f \n",cur_node->index,cur_node->place,cur_node->point);

}
int getSize(){ //size of linkedlist
    struct Node *cur_node;
    cur_node=head;
    int size=0;
    while(cur_node->next!=NULL){
        size++;
        cur_node=cur_node->next;

    }
    if(head!=NULL) //if linkedlist never happened,then size won't be incremented
        size++;
    return size;
}
