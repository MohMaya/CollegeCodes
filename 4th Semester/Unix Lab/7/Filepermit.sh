if test $# -ne 2
then
        echo "Invalid Usage"
        echo "Usage : 'bash Filepermit.sh <file1> <file2>'"
        exit 1
fi

if test -f $1
then
        if test -f $2
        then
                if test -r $1
                then
                        if test -w $2
                        then
                                cp $1 $2
                        else
                                echo  "NO WRITE PERMISSION ON $2"
                        fi
                else
                        echo  "NO READ PERMISSION ON $1"
                fi
        else
                echo  "$2 NOT A FILE"
        fi
else
        echo  "$1 NOT A FILE"
fi
