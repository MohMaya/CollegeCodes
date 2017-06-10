if test $# -eq 0
then
        echo "Invalid input format. Enter in the format 'bash wctr.sh <filename> [-l] [-w] [-c]'"
else
        fname=$1
        nc=0
        nw=0
        nl=0
        no=0
        if test ! -f $fname
        then
                echo "File $fname not found"
        else
                exec < $fname
                while IFS= read -r -n1 ch
                do
                        nc=`expr $nc + 1`
                        #Ignoring Multiple spaces or tabs right now
                        #Will Implement it in a future version
                        # -o ch = $"\n"
                        if test "$ch" = " "
                        then
                                no=`expr $no + 1`
                        elif test "$ch" = "\t"
                        then
                                no=`expr $no + 1`
                        fi
                done
                exec < $fname
                while read line
                do
                        nl=`expr $nl + 1`
                done
                exec < $fname
                while IFS=' ' read -r wr
                do
                        nw=`expr $nw + 1`
                done
                nw=`expr $no + $nl`
                #nw=`expr $nw - 2`
                nc=`expr $nc - 1`
                echo "$nc $nw $nl"
        fi
fi
