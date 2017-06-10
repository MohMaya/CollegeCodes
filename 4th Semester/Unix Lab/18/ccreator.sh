echo "Enter the number of .c files to be created"
read n

while test $n -gt 0
do
        touch $n.c
        n=`expr $n - 1`
done
