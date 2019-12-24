first_func=`cat $1 | grep -c "popular_command" $1`
second_func=`cat $1 | grep -c "efficiency" $1`
third_func=`cat $1 | grep -c "cafe_restaurant_app" $1`
fourth_func=`cat $1 | grep -c "weekly_calender_app" $1`
echo "popular_command function is : "$first_func
echo "efficiency function is : "$second_func
echo "cafe_restaurant_app function is : "$third_func
echo "weekly_calender_app function is : "$fourth_func

if [ $first_func -gt $second_func -a $first_func -gt $third_func -a $first_func -gt $fourth_func ]
then
    echo "popular_command is popular"
elif [ $second_func -gt $first_func -a $second_func -gt $third_func -a $second_func -gt $fourth_func ]
then
    echo "efficiency is popular"
elif [ $third_func -gt $second_func -a $third_func -gt $first_func -a $third_func -gt $fourth_func ]
then
    echo "cafe_restaurant_app is popular"
elif [ $fourth_func -gt $second_func -a $fourth_func -gt $first_func -a $fourth_func -gt $third_func ]
    echo "weekly_calender_app is popular"
fi
