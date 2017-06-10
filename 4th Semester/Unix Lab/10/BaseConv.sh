#Script to convert a given decomal to Octal, Binary, HexaDecimal using operators ibase and obase
echo "Enter the Decimal Value"
read dec

bin=`echo "ibase=10;obase=2;" $dec|bc`
oct=`echo "ibase=10;obase=8;" $dec|bc`
hex=`echo "ibase=10;obase=16;" $dec|bc`


echo "Binary      of $dec : $bin"
echo "Octal       of $dec : $oct"
echo "HexaDecimal of $dec : $hex"
