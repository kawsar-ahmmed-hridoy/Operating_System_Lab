echo "Input first number: "
read a
echo "Input second number: "
read b
c=$(expr $a + $b)
echo "The sum of this two numbers are: $c"
d=$(expr $a \* $b)
echo "The multiplication of this two numbers are: $d"
if [ $b -eq 0 ]; then
  echo "Division by zero is not allowed."
else
  result=$(expr $a / $b)
  echo "Result of division: $result"
fi
