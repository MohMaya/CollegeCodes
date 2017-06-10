echo "Enter the name of file 1"
read f1
echo "Enter the name of file 2"
read f2

diff $f1 $f2 >> /dev/null
if test $? -eq 0
then
        echo "The contents are same"
        rm -i $f2
        #echo "Deleted"
else
        echo "Contents are different"
fi
