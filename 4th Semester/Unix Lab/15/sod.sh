echo "Enter the Number whose sum of digits is to be calculated"
read num

rem=0
n=$num
sum=0

while test $n -gt 0
do
        rem=`expr $n % 10`
        sum=`expr $sum + $rem`
        n=`expr $n / 10`
done

echo "The Sum of digits is $sum"
