echo "Enter the number"
read num

rem=0
rev=0
place_value=1
n=$num

while test $n -gt 0
do
        n=`expr $n / 10`
        place_value=`expr $place_value \* 10`
done

n=$num
place_value=`expr $place_value / 10`
while test $n -gt 0
do
        rem=`expr $n % 10`
        rem=`expr $rem  \* $place_value`
        rev=`expr $rev + $rem`
        place_value=`expr $place_value / 10`
        n=`expr $n / 10`
done

echo $rev

if test $num -eq $rev
then
        echo "Palindrome"
else
        echo "Not A Palindrome"
fi
