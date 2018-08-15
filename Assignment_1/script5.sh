echo "enter a word:"
read word
val=$(grep -wo $word $1| wc -l)
if [ $val -gt 0 ] 
then
	printf "frequency : %d\n" $val
	echo "enter new word:"
	read newword
	sed -i s/$word/$newword/g $1
else
	pval=$(grep -o $word $1|wc -l)
	if [ $pval -gt 0 ]
	then
		printf "partial match exists\n"
	else 
		printf "not found\n"
	fi
fi
