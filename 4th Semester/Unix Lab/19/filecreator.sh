mkdir Files
cd Files
echo "Enter the number of files to be created(even files will be non zero size)"
read num

while test $num -gt 0
do
        touch $num
        rem=`expr $num % 2`
        if test $rem -eq 0
        then
                echo "qwerty asdfgh zxcvbn">$num
        fi
        num=`expr $num - 1`
done
