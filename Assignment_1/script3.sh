printf "file\tprintf\tscanf\tint\n"
for file in $*
do
	pval=`grep -o printf $file|wc -l`
	sval=`grep -o scanf $file|wc -l`
	ival=`grep -o int $file|wc -l`
	printf "%s\t%d\t%d\t%d\n" "$file" "$pval" "$sval" "$ival"
done
