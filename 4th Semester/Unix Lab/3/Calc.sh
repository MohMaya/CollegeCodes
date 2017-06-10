#I tried to make a calculator that can perform floating cl=alculations but Ryt Now I don't Know how to return a float value from a function. So I am echoing ryt from the function rather than the
# driver function. Will update if found an alternative.
# key $? => store the return value of last commmand



sum()
{
        c=`echo $1 + $2|bc`
        echo "$c"
        #return $c
}

diff()
{
        c=`echo $1 - $2|bc`
        echo "$c"
        #return $c
}

prod()
{
        c=`echo $1 \* $2|bc`
        echo "$c"
        #return $c
}


div()
{
        c=`echo $1 / $2|bc`
        echo -n "Quotient : $c , "
        #return $c
}

mod()
{
        c=`echo $1 % $2|bc`
        echo "Remainder : $c"
        #return $c
}


while test 1
do
        echo "****Menu****"
        echo "Enter:"
        echo "1. Add"
        echo "2. Subtract"
        echo "3. Multiply"
        echo "4. Divide"
        echo "5. Exit"
        read ch
        case $ch in
                1 )     echo "Enter A and B"
                        read a b
                        echo -n "$a + $b = "
                        sum $a $b
                        #echo "$a + $b = $?"
                        ;;
                2 )     echo "Enter A and B"
                        read a b
                        echo -n "$a - $b = "
                        diff $a $b
                        #echo "$a - $b = $?"
                        ;;
                3)      echo "Enter A and B"
                echo -n "$a * $b = "
                prod $a $b
                        read a b
                        #echo "$a * $b = $?"
                        ;;
                4)      echo "Enter A and B(For A/B)"
                        read a b
                        echo -n "For $a / $b ,  "
                        div $a $b
                        mod $a $b
                        #q=$?
                        #mod $a $b
                        #r=$?

                        ;;
                5 )     exit 1;;
                * )     echo "Invalid Input"
        esac

done
