echo "Enter the file name"
read fname
echo "Enter m"
read m
echo "Enter n"
read n
n=`expr $m + $n`
if test -f $fname
then
        cn=1
        exec<$fname
        while read line
        do
                if test $cn -ge $m
                then
                        if test $cn -lt $n
                        then
                                echo $line >> temp
                        fi
                fi
                cn=`expr $cn + 1`
        done
        mv temp $fname
else
        echo "No such file"
        exit 1
fi
