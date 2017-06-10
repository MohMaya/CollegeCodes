echo "Enter UserName"
read uname
n=5

#echo $st

while test $n -ne 0
do
        st=$(who|grep -wc $uname)
        if test $st -ne 0
        then
                echo "UserFound"
                exit 1
        else
                #echo "Not Found"
                sleep 60
        fi
        n=`expr $n - 1`
done
echo "Not Found"
