echo "Enter the decimal value"
read dec

num=$dec
bin=0
pv=1
rem=0

while test $num -gt 0
do
        rem=`expr $num % 2`
        rem=`expr $rem \* $pv`
        pv=`expr $pv \* 10`
        bin=`expr $bin + $rem`
        num=`expr $num / 2`
done

echo "Decimal($dec) = Binary($bin) "
