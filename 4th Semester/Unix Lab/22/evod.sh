echo "Enter a number"
read number
a=1
rem=`expr $number % 2`
cd files
if test $rem -eq 0
then
        while test $a -lt $number
        do
                b=`expr $a + 1`
                cp $a $b
                a=`expr $a + 2`
        done
else
        echo "invalid input"
fi
