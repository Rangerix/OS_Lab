
total=$(find $1 -type f|wc -l)			#counts total no of files recursively (not directories)
echo $total
dirs=`find $1 -maxdepth 1 -mindepth 1 -type d` 		#subdirectories at level 1
#echo $dirs
#now print number of files in the subdirectories
for i in $dirs
do
	val=`find $i -type f|wc -l`
	printf "%s : %d\n" "$i" "$val"
done

printf "\nall the files accessed within 2 days:\n"
find $1 -type f -mtime -2
