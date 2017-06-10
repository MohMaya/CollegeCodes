echo "Enter the filename :"
read fname

echo "You name Please : "
read uname

if test -w $fname
then
        echo "$uname">>$fname
else
        echo "No Write Permission"
fi
