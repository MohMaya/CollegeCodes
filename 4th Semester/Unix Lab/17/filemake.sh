echo "Enter the contents of File (End by pressing Enter and then Ctrl+D)"
cat >> f1
echo "Enter the Filename you want to give :"
read fname
mv f1 $fname
