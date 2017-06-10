while test 1
do
        echo "MENU"
        echo "Enter Your Choice"
        echo "1. ADD"
        echo "2. SUBTRACT"
        echo "3. MULTIPLY"
        echo "4. DIVIDE"
        echo "5. EXIT"
        read ch
        case $ch in
                1) echo "Enter the numbers to be added(a b)"
                   read a b
                   c=`echo $a + $b|bc`
                   echo "$a + $b = $c"
                   ;;
                2) echo "Enter the numbers to be subtracted(a b)"
                   read a b
                   c=`echo $a - $b|bc`
                   echo "$a - $b = $c"
                   ;;
                3) echo "Enter the numbers to be multiplied(a b)"
                   read a b
                   c=`echo $a \* $b|bc`
                   echo "$a * $b = $c"
                   ;;
                4) echo "Enter the numbers to be divided(a b)"
                   read a b
                   c=`echo $a / $b|bc`
                   d=`echo $a % $b|bc`
                   echo "$a / $b = $c"
                   echo "$a % $b = $d"
                   ;;
                5) exit 1
                   ;;
                *) echo "INVALID CHOICE:: RE-Enter"
        esac

done
