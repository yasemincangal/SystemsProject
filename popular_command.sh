first_func=`cat $1 | grep -c 'a' $1`
second_func=`cat $1 | grep -c "b" $1`
third_func=`cat $1 | grep -c "c" $1`
fourth_func=`cat $1 | grep -c "d" $1`
echo "a function is : "$first_func
echo "b function is : "$second_func
echo "c function is : "$third_func
echo "d function is : "$fourth_func

if [ $first_func -gt $second_func -a $first_func -gt $third_func -a $first_func -gt $fourth_func ]
then
    echo "a is popular"
elif [ $second_func -gt $first_func -a $second_func -gt $third_func -a $second_func -gt $fourth_func ]
then
    echo "b is popular"
elif [ $third_func -gt $second_func -a $third_func -gt $first_func -a $third_func -gt $fourth_func ]
then
    echo "c is popular"
else
    echo "d is popular"
fi
