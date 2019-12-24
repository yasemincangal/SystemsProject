first_func=`cat $1 | grep -c "history" $1`    #read file line by line and store that function
second_func=`cat $1 | grep -c "efficiency" $1`
third_func=`cat $1 | grep -c "cafe_restaurant_app" $1`
fourth_func=`cat $1 | grep -c "weekly_calender_app" $1`
echo "history function is : "$first_func        #print out all functions of usage of times
echo "efficiency function is : "$second_func
echo "cafe_restaurant_app function is : "$third_func
echo "weekly_calender_app function is : "$fourth_func

if [ $first_func -ge $second_func -a $first_func -ge $third_func -a $first_func -ge $fourth_func ] #compare with other commands usage of times
then
    echo "history is popular"
fi
if [ $second_func -ge $first_func -a $second_func -ge $third_func -a $second_func -ge $fourth_func ]
then
    echo "efficiency is popular"
fi
if [ $third_func -ge $second_func -a $third_func -ge $first_func -a $third_func -ge $fourth_func ]
then
    echo "cafe_restaurant_app is popular"
fi
if [ $fourth_func -ge $second_func -a $fourth_func -ge $first_func -a $fourth_func -ge $third_func ]
then
    echo "weekly_calender_app is popular"
fi
