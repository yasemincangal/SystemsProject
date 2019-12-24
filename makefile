array :main.o cafe_restaurant_app.o weekly_calender_app.o
gcc -o array main.o cafe_restaurant_app.o weekly_calender_app.o

main.o :  main.c
cc -c main.c

cafe_restaurant_app.o :  cafe_restaurant_app.c cafe_restaurant_app.h
cc -c cafe_restaurant_app.c

weekly_calender_app.o : weekly_calender_app.c weekly_calender_app.h
cc -c weekly_calender_app.c
 
clean:
rm -f main.o cafe_restaurant_app.o weekly_calender_app.o
