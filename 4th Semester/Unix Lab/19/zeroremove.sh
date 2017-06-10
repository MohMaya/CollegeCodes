cd Files
for a in *
do
        if test -s $a
        then
                continue
        else
                rm -i $a
        fi
done
