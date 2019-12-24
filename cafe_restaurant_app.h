void push(int,char * ); //creates doubly linkedlist by adding nodes according to reading every line of txt
int getSize(); //gives doubly linkedlist's size (line number of txt at the same time)
void toString_Node(struct Node *);// it prints properties of specific node
void printlist(); //prints all doubly linkedlist
void print_into_txt_with_points(FILE *); //prints points with places into a txt
void give_Point(float ,char *,int ); //gives point from user by taking its average and it stores how many times points given by users at the same time
void give_Point_randomly_to_all(int ); //gives point randomly a "float number" to a specific place
void interval(int , int ,int ); //find places and prints in that point interval
void sorted_list_according_to_points(int ); //prints sorted list of cafe_restaurant according to given points
