#script to convert a user NUmber from user entered base to another user entered base
echo "Enter the Number to be converted"
read num

echo "Enter the base of the Input NUmber"
read inpb

echo "Enter the base of the Output NUmber"
read optb


op=`echo "ibase=$inpb;obase=$optb;" $num|bc`

echo "The answer is $op"
