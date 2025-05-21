echo "Enter a number to check odd or even: "
read a
b=$((a%2))

if [ $b -eq 0 ]
then
   echo "$a is an even number"
else
   echo "$a is an odd number"
fi
