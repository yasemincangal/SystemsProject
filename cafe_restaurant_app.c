#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "/home/yasemin/deneme1/points_of_places.txt" //average points with place names and given point times by user will be shown in here

struct Node{ //every node has name, point, next and previous one
    float point; //average point
    int line; //in folder //might be deleted maybe
    int index;//at linkedlist
    struct Node* next;
    struct Node* prev;
    char place[20]; //name of place
    char *name_place;
    int user_gave_point; //given point times by user
};

struct Node * head=NULL;

void push(int index,char * name); //creates doubly linkedlist by adding nodes according to reading every line of txt
int getSize(); //gives doubly linkedlist's size (line number of txt at the same time)
void toString_Node(struct Node *cur_node);// it prints properties of specific node
void printlist(); //prints all doubly linkedlist
void print_into_txt_with_points(FILE *points_of_places); //prints points with places into a txt
void give_Point(float point,char *name,int size); //gives point from user by taking its average and it stores how many times points given by users at the same time
void give_Point_randomly_to_all(int size); //gives point randomly a "float number" to a specific place
void interval(int min, int max,int size); //find places and prints in that point interval
void sorted_list_according_to_points(int size); //prints sorted list of cafe_restaurant according to given points

int main() {
    FILE *input_file=NULL ;
    FILE *points_of_places=fopen(FILE_NAME,"a"); //create a file

    input_file=fopen("/home/yasemin/deneme1/cafe_restaurant.txt","r"); //writing and reading opened with file

    if(input_file==NULL){//if there is no such like that folder
        printf("File is not found!!");
        return 1;
    }

    char line[20]; //one txt line
    line[sizeof(line)-1]='\0';
    int index=0;
    while(fgets(line, sizeof(line),input_file)!=NULL){ //read every line till end of the txt
        char *name=malloc(80*sizeof(char));
        //puts(line);
        memcpy(name, line, sizeof(line)); //store names line by line
        //printf("%s",x); //output of file
        // printf("index:  %d, name: %s",index,name);
        int length=strlen(name);
        if(length>0)
            name[length-1]='\0'; //to get rid of from '\n' char
        push(index,name); //add in a linkedlist every node
        //printf("%s\n",name);
        index++;
    }
    printlist(); //show list
    int choice;
    printf("\nGive point type 1\nSee recommended places type 2 \n"
           "See all places with points in current form 3 \nSee points are sorted with places list type 4 \n"
           "Give random points to all places type 5 \nTo exit type 6\n");
    scanf("%d",&choice); // take point interval, or choose fav. place then it will show next and prev.

while(choice!=6 && choice>=1 && choice<=5 ){ //ask again till user wants to exit
    if(choice==1){ //take input from user the point and write that points with place names into a txt line by line
char *where=malloc(20*sizeof(char)); //place name 1 or 2 word
char *where1=malloc(20*sizeof(char));
printf("How many words is that place? (1 or 2)");
int x;
scanf("%d",&x);
printf("Where? ");
if(x==1){
scanf("%s",where);
}else if(x==2){
scanf("%s %s",where,where1);
strcat(where," ");
strcat(where,where1);
}
        float givepoint; //point that taken by user
        printf("\nGive points max:5.0 min :0.0 ");
        scanf("%f",&givepoint); //take the point by user
        int size=getSize(); //linkedlist current size (flexible)
        //printf("%d",size);
        if(givepoint<=5.0 && givepoint>=0.0 ){
            give_Point(givepoint,where,size); //give point a specific place
        }else{
            printf("Point interval is not in 0.0-5.0");
        }
        printlist();//print the list after giving point

        print_into_txt_with_points(points_of_places); //store values in txt file

    }else if(choice==2){
        char point_interval[10]; //input from user as 0-5 ex.
        char *p;
        p=point_interval;
        int least;
        int most;
        printlist();
        printf("Please give point interval like 0-5 (write as integers)"); //0 and 5 included
        scanf("%s",point_interval);
        //printf("%d-%d",p[0],p[2]);
        least=p[0]-48; //ASCII Code to int conversion
        most=p[2]-48;

        interval(least, most,getSize());//see places in that interval

    }else if(choice==3) {
    printlist(); //print the list current

    }else if(choice==4){ //sorting and printing it in console
            sorted_list_according_to_points(getSize()); //selection sort done and printed by using two arrays which have common behaviours about index

    }else if(choice==5){ //giving random numbers to places and putting in a txt as a result
        give_Point_randomly_to_all(getSize()); //do operations about giving float number
        print_into_txt_with_points(points_of_places); //write into txt
        printlist();
    }else{
        printf("\nTry again!!\n"); //float number or something else can be written too
    }

    printf("\nGive point type 1\nSee recommended places type 2 \n"
           "See all places with points in current form 3 \nSee points are sorted with places list type 4 \n"
           "Give random points to all places type 5 \nTo exit type 6\n");
    scanf("%d",&choice); // take point interval, or choose fav. place then it will show next and prev.
}

    fclose(points_of_places); //close files
    fclose(input_file);
    return 0;
}

void push(int index,char *name){  //add new node to end of the linkedlist
    struct Node *new_node=(struct Node *) malloc(sizeof(struct Node)); //allocate memory for new node;
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));
    new_node->user_gave_point=0; //assigning
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
void give_Point(float point,char *name,int size){ //give a point to a specific place and will be take average
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));
    float sum;
    cur_node=head;

    for(int i=0;i<size;i++){
        if(strcmp(cur_node->place,name)==0){ //place name has found in linkedlist
            (cur_node->user_gave_point)++; //given number times has incremented by 1
            sum=cur_node->point;
            sum+=point;
            cur_node->point=sum/(1.0*cur_node->user_gave_point); //take average and assign
           // printf("%s is this :%f",cur_node->place,cur_node->point);
            break;  //place name has found in linkedlist
        }
        //printf("%d ----- %d\n",sizeof(place), sizeof(name));
            if(i!=(size-1)) //if there is no such a restaurant or cafe like that
            cur_node=cur_node->next;
        if(i==(size-1))// name couldn't found
            printf("Place name is wrong\n\n");
    }

}

void printlist(){ //by travelling in linkedlist
    struct Node *cur_node;
    cur_node=head; //start from head

    while(cur_node->next!=NULL){
        toString_Node(cur_node); //call toString function
        cur_node=cur_node->next; //to visit all nodes
    }

    toString_Node(cur_node);//last node to print too
}
void print_into_txt_with_points(FILE *points_of_places){
    struct Node *cur_node;
    cur_node=head;
    points_of_places=fopen(FILE_NAME,"w");//clear all content of txt file at first when the program executed again

    while(cur_node->next!=NULL){
        fprintf(points_of_places,"place:%s point:%f \"point given times:%d\"\n",cur_node->place,cur_node->point,cur_node->user_gave_point);
        cur_node=cur_node->next;
    }

    fprintf(points_of_places,"place:%s point:%f \"point given times:%d\"\n",cur_node->place,cur_node->point,cur_node->user_gave_point);
}
void toString_Node(struct Node *cur_node){ //prints every property of struct except line for now
    printf("Node : index:%d place:%s point:%f \"point given times:%d\"\n",cur_node->index,cur_node->place,cur_node->point,cur_node->user_gave_point);
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
        size++; //just head
    return size;
}

void give_Point_randomly_to_all(int size){
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));
    cur_node=head;
    for(int i=0;i<size;i++){ //give float number between 0.0-5.0
        cur_node->point=(rand()%5)+((rand()%10)*0.1 + ((rand()%10)*0.01)+((rand()%10)*0.001) +(rand()%10)*0.0001 +(rand()%10)*0.00001+(rand()%10)*0.000001); //0.0-5.0 between gives float number randomly

        if(i!=(size-1))  //prevent overflow
            cur_node=cur_node->next;

    }

}
void interval(int min, int max,int size){ //find places in that point interval and show as recommended places to user
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));
    cur_node=head;
    int x=0; //boolean false
    for(int i=0;i<size;i++){
        if((cur_node->point)>=(1.0*min) && (cur_node->point)<=(1.0*max)){ //proper values in that interval
            x=1;//true, there is a place in that interval
            printf("You can visit %s\n",cur_node->place); //show places, proper ones
        }

        if(i!=(size-1)) //if there is no such a restaurant or cafe like that
            cur_node=cur_node->next;

        if(i==(size-1)&& x==0)// name couldn't found
            printf("There is no place in that point interval :( .");

    }
}

void sorted_list_according_to_points(int size){ //selection sort with two array which are places and points
    struct Node *cur_node=(struct Node *) malloc(sizeof(struct Node));
    cur_node=head;
    float arr[size]; //point values array
    char sorted_place_arr[size][20] ;//2-D array to store all places and it has a common behaviour about index with arr
    for(int i=0;i<size;i++){
        arr[i]=cur_node->point;//store all point in an array
        strcpy(sorted_place_arr[i],cur_node->place); //store all names in an array

        if(i!=(size-1))//prevent overflow
            cur_node=cur_node->next;
    }
    int index=0;//smallest index
    for(int i=0;i<size-1;i++){ //swap every time whenever you find the smallest
        float min=arr[i]; //smallest value

        for (int j= i; j<size-1 ; j++) { //find smallest
            if(arr[j]<=arr[j+1] && arr[j]<=min){ //find smallest till one before end of the array and if there is equality more than one same smaller, holds the last one
                index=j;
                min=arr[j];
      }
            if(arr[size-1]<=min) { //last element control
                index=size-1;
                min=arr[size-1];
            }
        }
        float temp=arr[i]; //swap now two array in the same way, bc index numbers are common of these two arrays
        char *place_temp=malloc(20*sizeof(char));
        strcpy(place_temp,sorted_place_arr[i]);
        arr[i]=arr[index];
        strcpy(sorted_place_arr[i],sorted_place_arr[index]);
        arr[index]=temp;
        strcpy(sorted_place_arr[index],place_temp);
    }
    //after all these operations, now print the array
    printf("\nThis is the sorted list according to given points of places :\n");
    int i=0;
        for(int j=size-1;j>=0;j--){
            printf("%d. %s , point:%f \n",i+1, sorted_place_arr[j],arr[j]); //print info by starting from highest point
            i++;
        }


}
