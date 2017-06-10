echo "Enter the number of files to be created"
read n
mkdir files
cd files
while test $n -gt 0
do
        touch $n
        rem=`expr $n % 2`
        if test $rem -eq 0
        then
                echo "qwerty">$n
        else
                echo "asdfgh">$n
        fi
        n=`expr $n - 1`
done
echo "Files created CONTENTS OF EVEN NUMBERED FILE : qwerty   CONTENTS OF ODD NUMBERED FILE : asdfgh"
