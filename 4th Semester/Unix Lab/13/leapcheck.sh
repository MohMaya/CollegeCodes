if test $# -ne 1
then
        year=$(date "+%Y")
else
        year=$1
fi



lc=`expr $year % 400`
c=`expr $year % 100`
bf=`expr $year % 4`

if test $lc -eq 0
then
        echo "$year is a leap year"
elif test $c -ne 0 -a $bf -eq 0
then
        echo "$year is a leap year"
else
        echo "$year is not a leap year"
fi
