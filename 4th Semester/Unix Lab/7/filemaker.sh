echo "Enter the name of first file"
read f1

touch $f1

echo "Enter the contents of $f1 (Press enter and ctrl+d to end)"
cat>$f1


echo "Enter the name of second file"
read f2
touch $f2

echo "Enter the contents of $f2 (Press enter and ctrl+d to end)"
cat>$f2
