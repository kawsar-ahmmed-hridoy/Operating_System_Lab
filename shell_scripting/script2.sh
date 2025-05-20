#script to swap to numbers.

echo "Enter first number: "
read a
echo "Enter second number: "
read b

temp=$a
a=$b
b=$temp

echo "After swaping, first number: $a and second number: $b"
