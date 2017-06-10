prime()
{
        num=$1
        if test $num -lt 2
        then
                return 0
        fi
        if test $num -eq 2
        then
                return 1
        fi
        c=2
        while test $c -lt $num
        do
                rem=`expr $num % $c`
                if test $rem -eq 0
                then
                        return 0
                fi
                c=`expr $c + 1`
        done
        return 1
}


echo "Enter n"
read n
echo "Enter m"
read m
while test $n -le $m
do
        prime $n
        sta=$?
        if test $sta -eq 1
        then
                echo " $n "
        fi
        n=`expr $n + 1`
done
