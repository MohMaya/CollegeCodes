if test $# -ne 1
then
        echo "INVALID USAGE"
        echo "USAGE : bash inpdir.sh <filename>"
        exit 1
fi

fname=$1

if test -f $fname
then
        echo "The File exists"
        echo "Now enter the data to be inserted into the file (End by pressing enter key and then Ctrl+D)"
        cat >> $fname
else
        echo -n "The File Does Not Exist, "
        if test -d $fname
        then
                echo "But A Directory Does."
                echo "Moving into the directory ..."
                cd $fname
                if test -f $fname
                then
                        echo "The File exists inside the directory"
                        echo "Now enter the data to be inserted into the file (End by pressing enter key and then Ctrl+D)"
                        cat >> $fname
                else
                        echo "The File does not exist inside the directory"
                        echo "Creating the file ..."
                        touch $fname
                        echo "Now enter the data to be inserted into the file (End by pressing enter key and then Ctrl+D)"
                        cat >> $fname
                fi
        else
                echo "The Directory also does not exists"
                echo "Creating and moving to the directory ..."
                mkdir $fname
                cd $fname
                echo "Creating the file ..."
                touch $fname
                echo "Now enter the data to be inserted into the file (End by pressing enter key and then Ctrl+D)"
                cat >> $fname
        fi
fi
