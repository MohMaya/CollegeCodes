cd wrkinDir
find . -maxdepth 1 -type f -size +1 > fillist
exec < fillist

while read line
do
        echo "$line"
done
