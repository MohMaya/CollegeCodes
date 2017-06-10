echo "Enter the number whose factorial is to be calculated :"
read num

fact=1
i=$num

while test $i -gt 0
do
        fact=`echo $fact \* $i|bc`
        i=`expr $i - 1`
done

echo "Factorial of $num is : $fact"
