echo "This code is to compare 2 different files to see their efficiency."
read -p "Which file you want to compare? (Enter only 1 file, type it with the right extension): " file1
#I was using -s but I learned that it means silence, which is not being able to take and read inputs from user.
echo " "
read -p "Enter the second file name: " file2
#Take the name of the file and read it.
echo " "
#if [ `ls -a | grep $file1==NULL` && `ls -a | grep $file2==NULL`] This line does not work properly.
#I was trying to do this: If user enters a file name that does not exist, the code should print the sentence above.
#then
#printf "Make sure you entered existing file names, please try again."
if [ $(cat $file1 | wc -l) -gt $(cat $file2 | wc -l) ] #If file1 has more lines than file 2
then
printf "$file1 has %s lines \n" "$(cat $file1 | wc -l)"
printf "$file2 has %s lines \n" "$(cat $file2 | wc -l)"
printf "$file1 has more lines than $file2\n"
elif [ $(cat $file2 | wc -l) -gt $(cat $file1 | wc -l) ] #If file2 has more lines than file1
then
printf "$file1 has %s lines \n" "$(cat $file1 | wc -l)"
printf "$file2 has %s lines \n" "$(cat $file2 | wc -l)"
printf "$file2 has more lines than $file1\n"
elif [ $(cat $file2 | wc -l) -eq $(cat $file1 | wc -l) ] #If the number of lines are equal
then
printf "$file1 has %s lines \n" "$(cat $file1 | wc -l)"
printf "$file2 has %s lines \n" "$(cat $file2 | wc -l)"
printf "$file2 and $file1 has the same number of lines\n"
else
echo "There must have been a problem, please try again."
fi

start1=$(date +%s%N | cut -b1-13)
chmod u+x $file1
./$file1
end1=$(date +%s%N | cut -b1-13)
executiontime1=$(($end1-$start1))
echo "Execution time of $file1: $executiontime1 milliseconds"
#NOTE: I need to run my file without printing the output.
#This will run the file1 and calculate the execution time in between.
echo " "
start2=$(date +%s%N | cut -b1-13)
chmod u+x $file2
./$file2
end2=$(date +%s%N | cut -b1-13)
executiontime2=$(($end2-$start2))
echo "Execution time of $file2: $executiontime2 milliseconds"
echo " "
#NOTE: I need to run my file without printing the output.
#Same thing happens for the file2
if [ $executiontime1 -lt $executiontime2 ]
then
printf "$file1 is faster than $file2\n"
fi

if [ $executiontime2 -lt $executiontime1 ]
then
printf "$file2 is faster than $file1\n"
fi

if [ $executiontime1 -eq $executiontime2 ]
then
printf "$file1 and $file2 have the same execution time\n"
fi
