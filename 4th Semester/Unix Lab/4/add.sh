# Usage : bash add.sh <Number1> <Number2>
#keys $# => Number of passed parameters
if test $# -ne 2
then
        echo "Invalid Usage"
        echo "Usage : bash add.sh <Number1> <Number2>"
        exit 1
fi
c=`echo $1 + $2|bc`
echo "Sum of $1 and $2 is $c"
