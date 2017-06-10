if test $# -ne 1
then
        echo "Invalid Usage"
        echo "Usage : bash Cirlce.sh <Radius>"
        exit 1
fi
rsq=`echo $1 \* $1|bc`
pr=`echo 2 \* 3.14 \* $1|bc`
ar=`echo 3.14 \* $1 \* $1|bc`

echo "Area of circle : $ar square units"
echo "Perimeter of circle : $pr units"
