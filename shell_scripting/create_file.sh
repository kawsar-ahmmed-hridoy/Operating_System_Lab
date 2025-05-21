echo "Enter the name of your file: "
read name
touch $name
echo "File created successfully!"
echo "Rename the file X file into Y"
read X
read Y
mv "$X" "$Y"
echo "File renamed to '$Y' successfully!"

#read from file;
R
read nm
if [-f $nm]
then
    cat nm
else
    echo "No file existed. Now created!"
    touch $nm
fi