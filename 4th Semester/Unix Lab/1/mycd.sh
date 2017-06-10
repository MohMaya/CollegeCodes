

mycd()
{
        if test -d $1 -o $1 = '-'
        then
                if test $1  = '-'
                then
                        cd ..
                        echo "Back in previous directory : $(pwd)"
                else
                        cd $1
                        pw=`echo pwd`
                        echo "Inside directory : $1"
                        echo "PWD : $(pwd)"
                fi
        else
                echo "No directory with name $1"
        fi
}


mycd $1
