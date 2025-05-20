
echo "Enter the numbers (space separated) to check max: "
read -a a

mx=${a[0]}

for i in "${a[@]}"
do
   if [ "$i" -gt "$mx" ]; then
        mx=$i
   fi
done

echo "Largest number of this array is: $mx"
