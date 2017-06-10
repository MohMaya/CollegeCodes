if test $# -ne 2
then
        echo "Invalid Usage"
        echo "Usage : bash larger.sh <number1> <number2>"
        exit 1
fi


a=$1
b=$2

if test $a -gt $b
then
        echo "$a is greater than $b"
elif test $b -gt $a
then
        echo "$b is greater than $a"
else
        echo "$a is equal to $b"
fi
