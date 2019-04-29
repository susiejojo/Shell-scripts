#!/bin/bash
#searches no of occurences of a search string in a webpage
if [ $# -ne 2 ]; then
echo Enter valid no of arguments
else
var1=$1
var2=$2
curl $2 > text.txt
cat text.txt | grep $1 | wc -l > text1.txt
cat text1.txt
fi
