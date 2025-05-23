#!/bin/bash

echo "Give filename: " 
read f

if [ -f "$f" ]; 
then
    echo "File exists: $f"
else
    touch "$f"
    echo "Created new file: $f"
fi

if [ -x "$f" ]; 
then
    echo "File has permission"
else
    chmod +x "$f"
    echo "Added execute permission to $f"
fi

if command -v nano >/dev/null 2>&1; 
then
    editor="nano"
elif command -v vim >/dev/null 2>&1; 
then
    editor="vim"
else
    editor="vi"
fi

#Bonus step
echo "File metadata:"
stat_output=$(stat --format=" Permission: %A\n Owner: %U\n Size: %s bytes\n Modification time: %y" "$f" 2>/dev/null)
if [ $? -ne 0 ]; then
    ls_output=$(ls -l "$f")
    echo "$ls_output"
else
    echo "$stat_output"
fi