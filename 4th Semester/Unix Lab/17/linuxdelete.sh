echo "Enter the filename"
read fname

grep -v linux $fname > f

mv f $fname
