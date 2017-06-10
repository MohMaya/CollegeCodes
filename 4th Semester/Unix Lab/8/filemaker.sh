echo "Enter the name of file"
read f1

touch $f1

echo "Enter the contents of $f1 (Press enter and ctrl+d to end)"
cat>$f1
