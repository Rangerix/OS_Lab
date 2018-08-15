echo "enter a word:"
read word
val=$(grep -o $word $1| wc -l)
if [ $val -gt 0 ] 
then
	printf "frequency : %d\n" $val
	(grep -no "$word" $1 | sort -n | uniq -c| cut -d ':' -f 1 | rev | cut -d ' ' -f -2 | rev) | awk '{print $2 " " $1}'
else
	printf "not found\n"
fi
